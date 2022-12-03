#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    long long a[200010],b[200010],c[200010];
    cin>>n;
    b[0]=1;
    for(i=1;i<=n;i++) {
        b[i]=(b[i-1]*10)%MOD;
    }
    c[1]=a[1]=10;
    for(i=2;i<=n;i++) {
        a[i]=(b[i-1]*9)%MOD;
        c[i]=((c[i-1]*10)%MOD+MOD+a[i]-a[i-1])%MOD;
    }
    for(i=n;i>=1;i--) {
        cout<<c[i]<<' ';
    }
    return 0;
}