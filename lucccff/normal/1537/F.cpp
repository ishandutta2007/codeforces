#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

long long a[200010],b[200010],c[200010];
vector <int> e[200010];

void dfs(int i,int k) {
    c[i]=k;
    for(int j=0;j<e[i].size();j++) {
        if (c[e[i][j]]==0) {
            dfs(e[i][j],3-k);
        }
    }
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,f,s;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        s=0;
        for(j=1;j<=n;j++) {
            cin>>a[j];
            c[j]=0;
        }
        for(j=1;j<=n;j++) {
            cin>>k;
            a[j]-=k;
            s+=a[j];
        }
        for(j=0;j<m;j++) {
            cin>>k>>l;
            e[k].push_back(l);
            e[l].push_back(k);
        }
        if (s&1) {
            cout<<"NO\n";
            for(j=1;j<=n;j++) {
                e[j].clear();
            }
            continue;
        }
        dfs(1,1);
        k=0;
        l=0;
        f=1;
        for(j=1;j<=n;j++) {
            for(int p=0;p<e[j].size();p++) {
                if (c[j]+c[e[j][p]]!=3) {
                    f=0;
                    break;
                }
            }
            if (c[j]==1) {
                k+=a[j];
            }
            else {
                l+=a[j];
            }
            if (!f) {
                break;
            }
        }
        if (f) {
            if (k==l) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        else {
            cout<<"YES\n";
        }
        for(j=1;j<=n;j++) {
            e[j].clear();
        }
    }
    return 0;
}