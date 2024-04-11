#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,p;
    long long a[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k;
        cin>>l;
        m=0;
        for(j=1;j<n;j++) {
            cin>>p;
            m=abs(__gcd(p-l,m));
        }
        if ((k-l)%m!=0) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}