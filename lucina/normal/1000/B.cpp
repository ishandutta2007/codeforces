#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100005],m,n,k,q[100005];
int reverse1(int  x){
if(x==0) return 1;
else return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    int t=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        q[i]=q[i-1]+t*(a[i]-a[i-1]);
        t=reverse1(t);
    }
    q[n+1]=q[n]+t*(m-a[n]);
    int ans=q[n+1];
    for(int i=1;i<=n;i++)
    ans=max(ans,m-q[n+1]-a[i]+2*q[i]-1);
    printf("%d",ans);
}