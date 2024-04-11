#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t,s;
    cin>>t;
    while(t--) {
        cin>>s>>n>>k;
        if (s<k) {
            cout<<"NO\n";
            continue;
        }
        if (s==k) {
            cout<<"YES\n";
            continue;
        }
        l=s/(k*2);
        j=s%(k*2);
        if (j<k) {
            if (n>j+l*k) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
        else {
            if (n>k-1+l*k) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}