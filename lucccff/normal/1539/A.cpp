#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x;
    cin>>t;
    while(t--) {
        cin>>n>>x>>k;
        l=k/x;
        if (l>=n-1) {
            cout<<(n-1)*n/2<<endl;
        }
        else {
            cout<<(n-1-l)*l+l*(l+1)/2<<endl;
        }
    }
    return 0;
}