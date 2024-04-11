#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long n,k,m,a[maxn],sum[maxn];
int main(){
    scanf("%lld%lld%lld",&n,&k,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    double x;
    double ans=0.0;
    for(int i=n;i>=1;i--){
        if(n-i>m)
        break;
        x=(long double)(sum[n]-sum[n-i]);
        x+=min((long double)(m-n+i),(long double)(i*k));
        x/=((long double)(i));
        ans=max(ans,x);
    }
    printf("%.26f\n",ans);
}