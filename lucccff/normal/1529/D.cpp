#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[1000010],b[1000010],c[1000010];
    cin>>n;
    a[0]=0;
    b[0]=0;
    c[1]=1;
    for(i=1;i<=n;i++) {
        if (i!=1) {
            c[i]=2;
            m=sqrt(i);
            for(j=2;j<=m;j++) {
                if (i%j==0) {
                    l=i;
                    k=1;
                    while(l%j==0) {
                        k++;
                        l/=j;
                    }
                    c[i]=k*c[l];
                    break;
                }
            }
        }
        a[i]=(b[i-1]+c[i])%MOD;
        b[i]=(b[i-1]+a[i])%MOD;
    }
    cout<<a[n];
    return 0;
}