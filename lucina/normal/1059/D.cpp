#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,v,u;
double x[maxn],y[maxn],l,r,mid,f,ans,g,mx,mn;

int main(){
    scanf("%d",&n);
    scanf("%d%d",&u,&v);
    x[1]=(double)(u),y[1]=(double)(v);
    int pa=abs(y[1])/y[1];
    y[1]=abs(y[1]);
    for(int i=2;i<=n;i++){
        scanf("%d%d",&u,&v);
        x[i]=(double)(u),y[i]=(double)(v);
        if(abs(y[i])*pa!=y[i]){
            printf("-1\n");
            return 0;
        }
        y[i]=abs(y[i]);
    }
     l=0.0,r=1e16;
     int t=100;
     while(t--){
        mid=(l+r)/2.0;
        mx=2e18,mn=-2e18;
        for(int i=1;i<=n;i++){
        g=abs(y[i]-mid);
        if(g>mid){
            mx=-2e18,mn=2e18;
            break;
        }
        else{
        f=(double)sqrt(abs((mid-g)*(mid+g)));
        mn=max(mn,(x[i])-f);
        mx=min(mx,(x[i])+f);
        }
     }
     if(mn<=mx){
        r=mid;
        ans=mid;
     }
     else{
        l=mid;
     }
}
    printf("%.11f\n",ans);
}