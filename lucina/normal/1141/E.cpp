#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],best;
long long h,s[maxn],ma,ans,w;

int main(){
    cin>>h>>n;
    ma=1e18;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
        if(s[i]+h<=0){
            printf("%d ",i);
            return 0;
        }
        ma=min(ma,s[i]);
   }
   if(h+ma>0&&s[n]>=0){
    printf("-1");
    return 0;
   }
   if(ma>=0){
    printf("-1");
    return 0;
   }
   w=abs(ma);
  // printf("%lld %lld\n",w,s[n]);
   ans=((h+ma)/abs(s[n])+(((h-w)%(abs(s[n])))==0?0:1));
   h+=s[n]*ans;
   for(int i=0;i<=n;i++){
    if(s[i]+h<=0){
        printf("%lld\n",ans*n+i);
        return 0;
    }
   }
   printf("-1");
}