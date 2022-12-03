#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
    long long i,j,k,l,m,n,t;
    long long a[100010],b[100010],jie[100010],ijie[100010],inv[100010];
    char ch;
    jie[0]=jie[1]=j=1;
    ijie[0]=ijie[1]=k=1;
    inv[1]=1;
    m=MOD;
    for(i=2;i<=100000;i++) {
        inv[i]=inv[m%i]*(m-m/i)%MOD;
        j=(j*i)%MOD;
        jie[i]=j;
        k=(k*inv[i])%MOD;
        ijie[i]=k;
    }
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        getchar();
        k=n;
        for(j=0;j<n;j++) {
            ch=getchar();
            a[j]=ch-'0';
            k-=a[j];
        }
        j=0;
        l=0;
        while(j<n) {
            while(j<n&&a[j]==0) j++;
            m=j;
            while(j<n&&a[j]==1) j++;
            l+=(j-m)/2;
        }
        cout<<((jie[l+k]*ijie[k]%MOD)*ijie[l]%MOD)<<endl;
    }
    return 0;
}