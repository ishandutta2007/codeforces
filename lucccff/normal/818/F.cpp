#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        if (n==1) {
            cout<<0<<endl;
            continue;
        }
        k=sqrt(2*n);
        while (k*(k+1)>=2*n) k--;
        k++;
        if (2*(n-k)>=(n-k+1)+(k-2)*(k-1)/2) {
            cout<<2*(n-k)<<endl;
        }
        else {
            cout<<(n-k+1)+(k-2)*(k-1)/2<<endl;
        }
    }
    return 0;
}