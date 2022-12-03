#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

LL inv[200010],jie[200010],ijie[200010];

LL C(LL n,LL m) {
    if (m<0||m>n) return 0;
    else return (ijie[m]*ijie[n-m]%MOD)*jie[n]%MOD;
}

LL inv2(LL x) {
    if (x==0) return 0;
    if (x==1) return 1;
    return inv2(MOD%x)*(MOD-MOD/x)%MOD;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t;
    LL ans=0,ans1=0;
    inv[1]=1;
    jie[0]=jie[1]=1;
    ijie[0]=ijie[1]=1;
    for(i=2;i<=2e5;i++) {
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
        jie[i]=jie[i-1]*i%MOD;
        ijie[i]=ijie[i-1]*inv[i]%MOD;
    }
    cin>>n>>m>>k;
    if (n==0&&m>k) ans1=ans=1;
    else if (m==0) ans1=ans=1;
    for(i=1;i<=m;i++) {
        if (i-1>0&&i-1<=n) {
            ans+=C(n-1,i-2)*C(m-1-i*k,i-1);
            ans%=MOD;
        }
        if (i<=n) {
            ans+=2*C(n-1,i-1)*C(m-1-i*k,i-1);
            ans%=MOD;
        }
        if (i+1<=n) {
            ans+=C(n-1,i)*C(m-1-i*k,i-1);
            ans%=MOD;
        }
        if (i-1>0&&i-1<=n) {
            ans1+=C(n-1,i-2)*C(m-1,i-1);
            ans1%=MOD;
        }
        if (i<=n) {
            ans1+=2*C(n-1,i-1)*C(m-1,i-1);
            ans1%=MOD;
        }
        if (i+1<=n) {
            ans1+=C(n-1,i)*C(m-1,i-1);
            ans1%=MOD;
        }
    }
    cout<<ans*inv2(ans1)%MOD<<endl;
    return 0;
}