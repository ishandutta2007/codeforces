#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

LL inv[1000010],jie[1000010],ijie[1000010],a[1000010],b[1000010];

LL C(LL n,LL m) {
    return (ijie[m]*ijie[n-m]%MOD)*jie[n]%MOD;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t,ans=0;
    inv[1]=1;
    jie[0]=jie[1]=1;
    ijie[0]=ijie[1]=1;
    b[0]=1;
    b[1]=2;
    for(i=2;i<=1e6;i++) {
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
        jie[i]=jie[i-1]*i%MOD;
        ijie[i]=ijie[i-1]*inv[i]%MOD;
    }
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++) {
        j=i+1;
        while(j<n&&a[j]==a[i]) j++;
        if (j!=n) ans+=(a[i]*jie[n-i-1]%MOD*jie[i]%MOD*C(n,i)%MOD)*(j-i)%MOD;
        i=j-1;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}