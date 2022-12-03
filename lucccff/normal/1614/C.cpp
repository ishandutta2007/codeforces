#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

LL qp(LL n,LL m) {
    LL k=1;
    while(m) {
        if (m&1) k=k*n%MOD;
        n=n*n%MOD;
        m>>=1;
    }
    return k;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,r;
    LL ans=0;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        j=0;
        for(i=0;i<m;i++) {
            cin>>l>>r>>k;
            j|=k;
        }
        cout<<j*qp(2,n-1)%MOD<<endl;
    }
    return 0;
}