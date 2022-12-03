#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int b[30];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++) {
            cin>>k;
            for(j=0;j<30;j++) {
                b[j]+=k&1;
                k>>=1;
            }
        }
        l=0;
        for(i=0;i<30;i++) l=__gcd(l,b[i]);
        for(i=1;i<=n;i++) {
            if (l%i==0) cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}