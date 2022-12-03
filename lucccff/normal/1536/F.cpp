#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[1000010],inv[1000010],ia[1000010];

void jie(int n) {
    a[0]=a[1]=ia[0]=ia[1]=1;
    inv[1]=1;
    long long i,j,k,m=MOD;
    k=1;
    j=1;
    for(i=2;i<=n;i++) {
        inv[i]=inv[m%i]*(m-m/i)%m;
        k=(k*i)%MOD;
        j=(j*inv[i])%MOD;
        a[i]=k;
        ia[i]=j;
    }
}

long long c(int m,int n) {
    return (a[n]*ia[m]%MOD)*ia[n-m]%MOD;
}

int main(){
    long long i,j,k,l,m,n,ans,p,q,s;
    cin>>n;
    jie(n);
    k=(n+3)/4;
    l=n/2;
    ans=0;
    for(i=k;i<=l;i++) {
        m=((c(n-2*i,2*i)*n%MOD)*inv[i]%MOD)*a[2*i]%MOD;
        ans=(ans+m)%MOD;
    }
    cout<<ans;
    return 0;
}