#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[300010];

int main() {
    int i,j,k,l,m,n,t;
    LL ans=0;
    scanf("%d%d",&n,&m);
    t=1<<n;
    for(i=0;i<t;i++) {
        //cin>>a[i];
        scanf("%d",a+i);
        ans+=a[i];
    }
    printf("%.9lf\n",1.0*ans/t);
    for(i=0;i<m;i++) {
        cin>>k>>l;
        ans+=l-a[k];
        a[k]=l;
        printf("%.9lf\n",1.0*ans/t);
    }
    return 0;
}