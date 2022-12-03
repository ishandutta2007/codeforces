#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long jie[200010],a[200010],inv[200010],ijie[200010];

long long pow(long long n,long long k) {
    long long j=n,ans=1;
    while (k>0) {
        if (k&1) ans=(ans*j)%MOD;
        j=(j*j)%MOD;
        k>>=1;
    }
    return ans;
}

long long c(long long n,long long m) {
    return (ijie[m]*ijie[n-m]%MOD)*jie[n]%MOD;
}

int main() {
    long long i,j,k,l,m,n,ans,s;
    cin>>n>>k;
    if (k>=n) {
        cout<<0;
        return 0;
    }
    jie[0]=ijie[0]=1;
    inv[1]=jie[1]=ijie[1]=j=l=1;
    m=MOD;
    for(i=2;i<=n;i++) {
        j=j*i%MOD;
        jie[i]=j;
        inv[i]=inv[m%i]*(m-m/i)%MOD;
        l=l*inv[i]%MOD;
        ijie[i]=l;
    }
    if (k==0) {
        cout<<jie[n];
        return 0;
    }

    s=0;

    for(i=n-k;i>=1;i--) {
        if ((n-k-i)&1) {
            s=(s+MOD-c(n-k,i)*pow(i,n)%MOD)%MOD;
        }
        else {
            s=(s+c(n-k,i)*pow(i,n)%MOD)%MOD;
        }
    }
    cout<<s*c(n,k)*2%MOD;
    
    return 0;
}