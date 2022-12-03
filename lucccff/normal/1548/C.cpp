#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long jie[3000010],inv[3000010],ijie[3000010],lim,a[3000010],b[3000010];
    inv[1]=1;
    jie[0]=jie[1]=j=1;
    ijie[0]=ijie[1]=k=1;
    for(i=2;i<=3000003;i++) {
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
        j=(j*i)%MOD;
        jie[i]=j;
        k=(k*inv[i])%MOD;
        ijie[i]=k;
    }
    cin>>n>>m;
    for(i=1;i<=3*n+3;i++) {
        a[i]=(ijie[i]*ijie[3*n+3-i]%MOD)*jie[3*n+3]%MOD;
    }
    a[0]=0;
    for(i=3*n+3;i>=3;i--) {
        b[i-3]=a[i];
        a[i-1]=(a[i-1]-a[i]*3+3ll*MOD)%MOD;
        a[i-2]=(a[i-2]-a[i]*3+3ll*MOD)%MOD;
        a[i]=0;
    }
    for(i=0;i<m;i++) {
        cin>>k;
        cout<<b[k]<<endl;
    }
    return 0;
}