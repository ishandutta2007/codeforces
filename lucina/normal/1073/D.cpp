#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
long long mini(long long x,long long y){
return x>y?y:x;
}
long long t,ans,n,g,d,sum,a[maxn];;
void sb(){
     sum=0,d=0;
    for(long long j=1;j<=n;j++){
        if(t>=a[j])
            t-=a[j],sum+=a[j],d++;
    }
}
int main(){
    scanf("%lld %lld",&n,&t);
    long long min1=1e9+1;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        min1=mini(min1,a[i]);
    }
    while(t>=min1){
        sb();
        d*=(t/sum+1);
        t=(t-sum*(t/sum));
        ans+=d;
    }
    printf("%lld\n",ans);
}