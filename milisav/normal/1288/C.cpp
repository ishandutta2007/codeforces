#include<bits/stdc++.h>
typedef long long lld;
using namespace std;
lld mod = 1000000007;
int n,m;
lld a[100][2000];
lld b[100][2000];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) a[1][i]=b[1][i]=1;
    for(int i=2;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                if(j>=k) a[i][j]+=a[i-1][k];
                if(j<=k) b[i][j]+=b[i-1][k];
            }
            a[i][j]%=mod;
            b[i][j]%=mod;
        }
    }
    lld ans=0;
    for(int j=1;j<=n;j++) {
        for(int k=j;k<=n;k++) {
            ans=(ans+a[m][j]*b[m][k])%mod;
        }
    }
    printf("%lld",ans);
    return 0;
}