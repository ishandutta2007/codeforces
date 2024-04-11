#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long b[200010];

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

void jie(int n){
    long long j,k;
    b[0]=1;
    b[1]=k=1;
    for(int i=2;i<=n;i++) {
        k=(k*i)%MOD;
        b[i]=k;
    }
}

int main(){
    long long i,j,k,l,m,n,s;
    long long a[200010];
    cin>>n>>k;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    m=n;
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
    jie(m);

    s=pow_mod(k,m);
    for(i=0;i<=m/2;i++) {
        j=(b[m]*inv(b[i]))%MOD;
        j=(j*inv(b[i]))%MOD;
        j=(j*inv(b[m-2*i]))%MOD;
        j=(j*pow_mod(k-2,m-2*i))%MOD;
        s=(s+MOD-j)%MOD;
    }

    s=(s*inv(2))%MOD;
    s=(s*l)%MOD;
    cout<<s;

    return 0;
}