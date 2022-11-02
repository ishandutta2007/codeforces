//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 1000010
int n,m;
int num[maxn];
int f[maxn];
bool bo[maxn];

int fa(int t){return f[t]==t?t:f[t]=fa(f[t]);}

void Union(int x,int y)
{
    int i=fa(x),j=fa(y);
    if (i!=j)   f[i]=j;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)  f[i]=i;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        num[x]++,num[y]++;
        Union(x,y);
    }
    int ans=0,sum=0;
    for (int i=1;i<=n;i++)
    {
        if (num[i]&1)   ans++,bo[fa(i)]=true;
        if (num[i]==0 && i!=1)  f[i]=0;
    }
    for (int i=1;i<=n;i++)
    if (f[i]==i)    sum++;
    if (sum==1) {printf("%d\n",ans/2);return 0;}
    for (int i=1;i<=n;i++)
        if (f[i]==i && !bo[i] && (num[i]!=0||i==1)) ans+=2;
    printf("%d\n",ans/2);
    return 0;
}