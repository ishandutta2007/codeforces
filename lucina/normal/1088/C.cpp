#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+10;
long long n,a[maxn],ans,u;
long long b[3000][4];
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
if(n==1){
printf("0");
return 0;
}
    int sum=0;
    u=0;
    if(a[n]<n){
        //printf("%d %d %d\n",1,n+1-a[n],n);
        u++;
        b[u][1]=1,b[u][2]=n+1-a[n],b[u][3]=n;
        sum+=(n+1-a[n]);
    }
    ans=0;
    for(int i=n-1;i>=1;i--){
        if(((a[i]+sum)%n)!=(i%n)){
           ans=i-((a[i]+sum)%n);
           if(ans<0)
            ans+=n;
           //      printf("%d %d %d\n",1,ans,i);
            u++;
            b[u][1]=1,b[u][2]=ans,b[u][3]=i;
            sum+=ans;
        }
    }
    u++;
    //printf("%d %d %d\n",2,n-1,n);
    b[u][1]=2,b[u][2]=n,b[u][3]=n-1;
    printf("%lld\n",u);
    for(int i=1;i<=u;i++){
        printf("%lld %lld %lld\n",b[i][1],b[i][3],b[i][2]);
    }

}