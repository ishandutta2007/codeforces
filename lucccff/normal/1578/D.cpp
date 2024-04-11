#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010],b[100010],c[100010];
vector <int> e[100010];
int dfs(int k,int x) {
    c[k]=1;
    b[k]=a[k];
    int j=0;
    for(int i=0;i<e[k].size();i++) {
        if (c[e[k][i]]==0) {
            j+=dfs(e[k][i],x);
            b[k]^=b[e[k][i]];
        }
    }
    if (b[k]==x) return max(1,j);
    else if (b[k]==0) if (j>0) return j+1;
    else return 0;
    else return j;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,x;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        x=0;
        for(i=1;i<=n;i++) {
            cin>>a[i];
            e[i].clear();
            x^=a[i];
            c[i]=0;
        }
        for(i=1;i<n;i++) {
            cin>>k>>l;
            e[k].push_back(l);
            e[l].push_back(k);
        }
        if (m==2) {
            if (x!=0) {
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
            }
        }
        else {
            if (x==0) {
                cout<<"YES\n";
            }
            else {
                if (dfs(1,x)>=2) {
                    cout<<"YES\n";
                }
                else {
                    cout<<"NO\n";
                }
            }
        }
    }
    return 0;
}