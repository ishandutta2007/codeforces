#include <bits/stdc++.h>
using namespace std;
// u->u+v v&u=v
// +1 from high to low
// <=> u->u+2^i ((u>>i)&1)==1
// process from low to high
typedef long long ll;
// const int maxn=105;
// int ok[maxn][maxn];
ll u,v;
int main()
{
    int T,i,j,x,y,l,r;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&u,&v);
        // for(i=0;;i++)
        // {
        //     if(u==v && !add1) { printf("YES\n"); break; }
        //     if(!(v>>i)) { printf("NO\n"); break; }
        //     x=(u>>i)&1,y=(v>>i)&1;
        //     if(add1)
        //     {
        //         if(x==0 && y==1) u^=1ll<<i,add1=false;
        //         else if(x==1 && y==0) u^=1ll<<i;
        //     }
        //     else if(x==0 && y==1) { printf("NO\n"); break; }
        //     else if(x==1 && y==0) add1=true,u^=1ll<<i;
        // }
        // ok[0][0]=1;
        // for(i=0;;i++)
        // {
        //     if(u==v && ok[i][0]) { printf("YES\n"); break; }
        //     if(!(v>>i)) { printf("NO\n"); break; }
        //     for(j=0;j<=i+1;j++) ok[i+1][j]=0;
        //     x=(u>>i)&1,y=(v>>i)&1;
        //     for(j=0;j<=i;j++)
        //     {
        //         if(j^1)
        //         {
        //             if(x==0 && y==1) u^=1ll<<i,add1=false;
        //             else if(x==1 && y==0) u^=1ll<<i;
        //         }
        //         else if(x==0 && y==1) { printf("NO\n"); break; }
        //         else if(x==1 && y==0) add1=true,u^=1ll<<i;
        //     }
        //     if(x!=y) u^=1ll<<i;
        //     for(j=0;j<=i+1;j++) ok[i+1][j]=!!ok[i+1][j];
        // }
        // for(i=0;;i++)
        // {
        //     if(u==v && !add1) { printf("YES\n"); break; }
        //     if(!(v>>i)) { printf("NO\n"); break; }
        //     x=(u>>i)&1,y=(v>>i)&1;
        //     if(add1)
        //     {
        //         if(x==0 && y==1) u^=1ll<<i,add1=false;
        //         else if(x==1 && y==0) u^=1ll<<i;
        //     }
        //     else if(x==0 && y==1) { printf("NO\n"); break; }
        //     else if(x==1 && y==0) add1=true,u^=1ll<<i;
        // }
        l=r=0;
        for(i=0;;i++)
        {
            if(u==v && !l) { printf("YES\n"); break; }
            if(!(v>>i)) { printf("NO\n"); break; }
            x=(u>>i)&1,y=(v>>i)&1;
            l+=x-y,r+=x-y;
            l=max(l,0);
            if(l>r) { printf("NO\n"); break; }
            l=(l+1)>>1;
            if(x!=y) u^=1ll<<i;
        }
    }
    return 0;
}