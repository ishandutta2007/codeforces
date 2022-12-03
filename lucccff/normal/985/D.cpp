#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL n,h,k,x;
    cin>>n>>h;
    if (h+1>2*n/h) {
        k=sqrt(n*2);
        while(k+1>2*n/k) k--;
        if (k*(k+1)<n*2) k++;
        cout<<k<<endl;
    }
    else {
        k=sqrt(n+h*(h-1)/2);
        if (k*k-h*(h-1)/2<n) k++;
        if (k*k-h*(h-1)/2-k>=n) cout<<k+k-h-1<<endl;
        else cout<<k+k-h<<endl;
    }
    return 0;
}