#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

LL a[510][510],jie[510],ijie[510],inv[510],q[510][510];

LL qp(LL n,LL m) {
    LL k=1,t=n;
    while(m) {
        if (m&1) k=k*t%MOD;
        t=t*t%MOD;
        m>>=1;
    }
    return k;
}

LL C(LL m,LL n) {
    return (ijie[m]*ijie[n-m]%MOD)*jie[n]%MOD;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t;
    jie[0]=jie[1]=1;
    ijie[0]=ijie[1]=1;
    inv[1]=1;
    for(i=2;i<=500;i++) {
        jie[i]=jie[i-1]*i%MOD;
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
        ijie[i]=ijie[i-1]*inv[i]%MOD;
    }
    for(i=0;i<=500;i++) {
        for(j=0;j<=500;j++) {
            q[i][j]=qp(i,j);
        }
    }
    for(i=1;i<=500;i++) {
        a[1][i]=i;
    }
    for(i=2;i<=500;i++) {
        for(j=i;j<=500;j++) {
            if (j==i) {
                a[i][j]=i*q[i-1][j-1]%MOD;
            }
            else {
                a[i][j]=0;
                for(k=1;k<=i;k++) {
                    a[i][j]=(a[i][j]+(C(k,i)*a[k][j-i+1]%MOD)*q[i-1][i-k])%MOD;
                }
            }
        }
    }
    cin>>k>>l;
    cout<<(MOD+q[l][k]-a[k][l])%MOD;
    return 0;
}