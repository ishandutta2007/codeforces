//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 110
int n,s;
int v[maxn][maxn];
int t[maxn][maxn];
int k[maxn];
int ans;

int main()
{
    scanf("%d%d",&n,&s);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        for (int j=1;j<=k[i];j++)
        {
            scanf("%d%d",&v[i][j],&t[i][j]);
            t[i][j]+=t[i][j-1];
            t[i][k[i]+1]=1<<30;
        }
    }
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
        {
            int t1=1,t2=1,x1=0,x2=0,tmp=0,tmp2=-1;
            while (t1<=k[i] || t2<=k[j])
            {
                int tmp1=min(t[i][t1],t[j][t2]);
                x1+=(tmp1-tmp)*v[i][t1];
                x2+=(tmp1-tmp)*v[j][t2];
                if (t[i][t1]<t[j][t2])  t1++;else t2++;
                if (x1>x2 && tmp2==0)   ans++;
                if (x1<x2 && tmp2==1)   ans++;
                if (x1>x2)  tmp2=1;
                if (x1<x2)  tmp2=0;
                tmp=tmp1;
            }
        }
    printf("%d\n",ans);
    return 0;
}