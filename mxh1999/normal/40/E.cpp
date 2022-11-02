//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 1010
//int a[maxn][maxn];
int b[maxn],c[maxn],b1[maxn],c1[maxn];
int n,m,tot,ans,mo;

int main()
{
    scanf("%d%d%d",&n,&m,&tot);
    ans=n+m+tot-1;
    if ((n+m)%2==1) {printf("0\n");return 0;}
    memset(b1,-1,sizeof(b1));
    memset(c1,-1,sizeof(c1));
    for (int i=1;i<=tot;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        b[x]++,c[y]++,b1[x]*=z,c1[y]*=z;
        if (b[x]==m)
        {
            if (b1[x]>0)    ans--;
            else    {printf("0\n");return 0;}
        }
        if (c[y]==n)
        {
            if (c1[y]>0)    ans--;
            else    {printf("0\n");return 0;}
        }
    }
    scanf("%d",&mo);
    int ans1=1;
    for (int i=1;i<=n*m-ans;i++)    ans1=(ans1*2)%mo;
    printf("%d\n",ans1);
    return 0;
}