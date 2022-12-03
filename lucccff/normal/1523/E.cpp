#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long jie[100010],ijie[100010];

long long inv1(long long a){
    long long m=MOD;
    if(a == 1) return 1;
    return inv1(m%a)*(m-m/a)%m;
}

long long ic(long long m,long long n) {
    if (n<m||m<0) return 0;
    else return (ijie[n]*jie[n-m]%MOD)*jie[m]%MOD;
}

long long c(long long m,long long n) {
    if (n<m||m<0) return 0;
    else return (jie[n]*ijie[n-m]%MOD)*ijie[m]%MOD;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    long long a[100010],inv[100010];
    inv[1]=1;
    m=MOD;
    j=k=1;
    jie[1]=jie[0]=1;
    ijie[1]=ijie[0]=1;
    for(i=2;i<=100000;i++) {
        inv[i]=(inv[m%i]*(m-m/i))%m;
        j=(j*i)%MOD;
        jie[i]=j;
        k=(k*inv[i])%MOD;
        ijie[i]=k;
    }
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k;
        l=0;
        for(j=1;(j-1)*k<n;j++) {
            l=(l+(c(j,n-(j-1)*(k-1))*ic(j,n)%MOD+MOD-c(j+1,n-j*(k-1))*ic(j+1,n)%MOD)*(j+1))%MOD;
        }
        cout<<l<<endl;
    }
    return 0;
}