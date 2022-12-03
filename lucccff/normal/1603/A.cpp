#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

LL a[100010],b[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(i=1;i<=n;i++) {
            cin>>a[i];
        }
        k=1;
        l=1;
        for(i=1;i<=n;i++) {
            k=k*(i+1)/__gcd(k,i+1);
            if (k>1e9) break;
            if (a[i]%k==0) {
                l=0;
                break;
            }
        }
        if (l) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}