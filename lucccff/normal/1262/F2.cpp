#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long b[200010],inv1[200010],c[200010];

long long mult_mod(long long a,long long b){
    a %= MOD;
    b %= MOD;
    long long ret = 0;
    long long tmp = a;
    while(b){
        if (b & 1){
            ret += tmp;
            if(ret > MOD)ret-=MOD;
        }
        tmp <<= 1;
        if(tmp > MOD)tmp-=MOD;
        b >>= 1;
    }
    return ret;
}

long long pow_mod(long long a,long long n){
    long long ret = 1;
    long long temp = a%MOD;
    while(n) {
        if (n & 1)ret = mult_mod(ret,temp);
        temp = mult_mod(temp,temp);
        n >>= 1;
    }
    return ret;
}

long long inv(long long a)//mod
{
    return pow_mod(a,MOD-2);
}

long long inv2(long long a){
    long long m=MOD;
    //if(a == 1)return 1;
    return inv1[m%a]*(m-m/a)%m;
}

long long initinv(int n) {
    inv1[1]=1;
    for(int i=2;i<=n;i++) {
        inv1[i]=inv2(i);
    }
}

void jie(int n){
    long long j,k;
    c[0]=b[0]=1;
    c[1]=b[1]=j=k=1;
    for(int i=2;i<=n;i++) {
        k=(k*i)%MOD;
        j=(j*inv1[i])%MOD;
        b[i]=k;
        c[i]=j;
    }
}

int main(){
    long long i,j,k,l,m,n,s,p;
    long long a[200010];
    cin>>n>>k;
    m=n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    for(i=0;i<n;i++) {
        j=i+1;
        while(j<n&&a[j]==a[i]) {
            m--;
            j++;
        }
        i=j-1;
    }
    if (a[0]==a[n-1]) m--;
    
    l=pow_mod(k,n-m);
    initinv(m);
    jie(m);

    s=pow_mod(k,m);
    for(i=0;i<=m/2;i++) {
        p=b[m];
        j=(c[i]*c[i])%MOD;
        j=(j*c[m-2*i])%MOD;
        p=(p*j)%MOD;
        p=(p*pow_mod(k-2,m-2*i))%MOD;
        s=(s+MOD-p)%MOD;
    }
    
    s=(s*inv1[2])%MOD;
    s=(s*l)%MOD;

    cout<<s;

    return 0;
}