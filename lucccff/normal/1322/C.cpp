#include <bits/stdc++.h>
#define MOD1 998244353
#define MOD2 1000000009
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s;
    long long a[500010],b[500010],c[500010],d[500010];
    vector <int> e[500010];
    map <pair<long long,long long>,int> p;
    pair <long long,long long> z; 
    cin>>t;
    for(int x=0;x<t;x++) {
        cin>>n>>m;
        p.clear();
        for(i=1;i<=n;i++) {
            cin>>a[i];
            b[i]=0;
            e[i].clear();
        }
        if (n==1) {
            cin>>k>>l;
            cout<<a[1]<<endl;
            continue;
        }
        for(i=0;i<m;i++) {
            cin>>k>>l;
            e[l].push_back(k);
        }
        s=0;
        for(i=1;i<=n;i++) {
            if (e[i].size()) {
                for(j=0;j<e[i].size();j++) {
                    c[j]=e[i][j];
                }
                sort(c,c+e[i].size());
                k=0;
                l=0;
                for(j=0;j<e[i].size();j++) {
                    k=(k*233+c[j])%MOD1;
                    l=(l*233+c[j])%MOD2;
                }
                z=make_pair(k,l);
                if (p.count(z)) {
                    d[p[z]]+=a[i];
                }
                else {
                    d[s]=a[i];
                    p[z]=s++;
                }
            }
        }
        l=d[0];
        for(i=1;i<s;i++) {
            l=__gcd(l,d[i]);
        }
        cout<<l<<endl;
    }
    return 0;
}