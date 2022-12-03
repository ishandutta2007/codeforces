#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s;
    long long a[200010],b[200010],c[200010];
    vector <int> e[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=1;j<=n;j++) {
            b[j]=-1;
            c[j]=1;
            cin>>a[j];
            e[j].clear();
        }
        for(j=1;j<=n;j++) {
            e[a[j]].push_back(j);
        }
        for(j=1;j<=n;j++) {
            if (e[j].size()!=0) {
                b[e[j][0]]=j;
                c[j]=0;
            }
        }
        k=n;
        s=-1;
        for(j=1;j<=n;j++) {
            if (c[j]==0) continue;
            while(k>0&&b[k]!=-1) k--;
            b[k]=j;
            if (k==j) s=k;
        }
        if (s>0) {
            b[s]=b[e[a[s]][0]];
            b[e[a[s]][0]]=s;
        }
        s=0;
        for(j=1;j<=n;j++) {
            if (b[j]==a[j]) s++;
        }
        cout<<s<<endl;
        for(j=1;j<=n;j++) {
            cout<<b[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}