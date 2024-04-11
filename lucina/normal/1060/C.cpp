#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=3000;
long long a[maxn],b[maxn],c[maxn],d[maxn],n,m,x,ans;
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(int j=1;j<=m;j++){
        scanf("%lld",&b[j]);
        b[j]+=b[j-1];
    }
    for(int i=1;i<=n;i++){
        c[i]=a[i];
        for(int j=i;j<=n;j++){
            c[i]=min(c[i],a[j]-a[j-i]);
        }
    }
    for(int i=1;i<=m;i++){
        d[i]=b[i];
        for(int j=i;j<=m;j++){
            d[i]=min(d[i],b[j]-b[j-i]);
        }
    }
    scanf("%lld",&x);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i]*d[j]<=x){
                ans=max(ans,(long long)i*j);
            }
        }
    }
    printf("%lld\n",ans);
}
/*
1235  (0,0)-->(1,1)
4563
0123
*/