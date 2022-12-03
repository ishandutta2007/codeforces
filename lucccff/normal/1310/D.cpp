#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,m1=1e12;
    long long a[100][100],dp[20][100],f[100];
    srand((unsigned)time(NULL));
    cin>>n>>k;
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for(t=0;t<5000;t++) {
        f[1]=0;
        for(i=2;i<=n;i++) f[i]=rand()&1;
        dp[0][1]=0;
        for(i=2;i<=n;i++) dp[0][i]=1e12;
        for(i=1;i<=k;i++) {
            if (i&1) {
                for(j=1;j<=n;j++) {
                    m=1e12;
                    if (f[j]==1) for(l=1;l<=n;l++) {
                        if (f[l]==0) {
                            if (a[l][j]+dp[i-1][l]<m) m=a[l][j]+dp[i-1][l];
                        }
                    }
                    dp[i][j]=m;
                }
            }
            else {
                for(j=1;j<=n;j++) {
                    m=1e12;
                    if (f[j]==0) for(l=1;l<=n;l++) {
                        if (f[l]==1) {
                            if (a[l][j]+dp[i-1][l]<m) m=a[l][j]+dp[i-1][l];
                        }
                    }
                    dp[i][j]=m;
                }
            }
        }
        if (m1>dp[k][1]) m1=dp[k][1];
    }
    cout<<m1;
    return 0;
}