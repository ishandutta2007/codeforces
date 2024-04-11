#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int main() {
    long long i,j,k,l,m,n,r,a,b,c;
    cin>>n>>m>>l>>r;
    a=r-l+1;
    c=n*m;
    b=1;
    while(c>0) {
        if (c&1) b=(b*a)%MOD;
        a=(a*a)%MOD;
        c>>=1;
    }
    if ((n*m)&1) {
        cout<<b;
    }
    else if ((r-l)&1){
        cout<<b*(MOD-MOD/2)%MOD;
    }
    else {
        cout<<(b+1)*(MOD-MOD/2)%MOD;
    }
    return 0;
}