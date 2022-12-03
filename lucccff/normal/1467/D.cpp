#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,q,ans;
    long long a[5010][5010],b[5010],c[5010];
    cin>>n>>k>>q;
    for(i=0;i<n;i++) {
        cin>>b[i];
    }
    for(i=0;i<n;i++) {
        a[0][i]=1;
    }
    for(i=1;i<=k;i++) {
        a[i][0]=a[i-1][1];
        for(j=1;j<n-1;j++) {
            a[i][j]=a[i-1][j-1]+a[i-1][j+1];
            if (a[i][j]>=MOD) a[i][j]-=MOD;
        }
        a[i][n-1]=a[i-1][n-2];
    }
    for(i=0;i<n;i++) {
        c[i]=0;
        for(j=0;j<=k;j++) {
            c[i]=(c[i]+a[j][i]*a[k-j][i])%MOD;
        }
    }
    ans=0;
    for(i=0;i<n;i++) {
        ans=(ans+c[i]*b[i])%MOD;
    }
    for(i=0;i<q;i++) {
        cin>>l>>m;
        ans=(ans+(MOD+m-b[l-1])*c[l-1])%MOD;
        b[l-1]=m;
        cout<<ans<<endl;
    }
    return 0;
}