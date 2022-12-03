#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s;
    long long a[300010],b[300010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k;
        for(j=1;j<=n;j++) {
            cin>>a[j];
        }
        m=max(1ll,n-100);
        s=-1e9;
        for(j=m;j<n;j++) {
            for(l=j+1;l<=n;l++) {
                if (s<j*l-k*(a[j]|a[l])) {
                    s=j*l-k*(a[j]|a[l]);
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}