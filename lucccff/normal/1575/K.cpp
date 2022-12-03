#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

long long qp(long long n,long long m) {
    long long t=n%MOD,k=1;
    while(m) {
        if (m&1) k=k*t%MOD;
        t=t*t%MOD;
        m>>=1;
    }
    return k;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,c,r,a1,a2,b1,b2;
    cin>>n>>m>>k>>c>>r;
    cin>>a1>>a2>>b1>>b2;
    if (a1==b1&&a2==b2) {
        cout<<qp(k,n*m);
    }
    else {
        cout<<qp(k,n*m-c*r);
    }
    return 0;
}