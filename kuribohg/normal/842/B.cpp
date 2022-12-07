#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int R,D,n;
int x[MAXN],y[MAXN],r[MAXN];
int ans;
int main()
{
    scanf("%d%d%d",&R,&D,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&y[i],&r[i]);
    for(int i=1;i<=n;i++)
        if(x[i]*x[i]+y[i]*y[i]>=(r[i]+R-D)*(r[i]+R-D)&&x[i]*x[i]+y[i]*y[i]<=(R-r[i])*(R-r[i])) ans++;
    printf("%d\n",ans);
    return 0;
}