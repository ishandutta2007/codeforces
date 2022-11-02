//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 50010
typedef long long ll;
struct Edge
{
    int u,v,cost1,cost2;
    void read()
    {
        scanf("%d%d%d%d",&u,&v,&cost1,&cost2);
    }
}   edge[maxn];
int n,m;
int value1,value2;
int f[maxn];
int t[maxn],len;
bool bo[maxn];
ll ans=-1;

int fa(int t){return f[t]==t?t:fa(f[t]);}

bool cmp(const Edge &a,const Edge &b)
{
    return a.cost2<b.cost2;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&value1,&value2);
    for (int i=1;i<=m;i++)
        edge[i].read();
    sort(edge+1,edge+m+1,cmp);
    len=0;
    for (int i=1;i<=m;i++)
    {
        int tmp=len;
        int maxx=0;
        while (tmp>0 && edge[t[tmp]].cost1>edge[i].cost1)   t[tmp+1]=t[tmp],tmp--;
        t[tmp+1]=i;
        for (int j=1;j<=n;j++)  f[j]=j;
        for (int j=1;j<=len+1;j++)  bo[j]=false;
        for (int j=1;j<=len+1;j++)
        if (fa(edge[t[j]].u)!=fa(edge[t[j]].v))
        {
            f[fa(edge[t[j]].u)]=fa(edge[t[j]].v);
            bo[j]=true;
            maxx=edge[t[j]].cost1;
        }
        int sum=0;
        for (int j=1;j<=n;j++)  if (f[j]==j)    sum++;
        if (sum==1)
        {
            ll ans1=(ll)maxx*value1;
            ll ans2=(ll)edge[i].cost2*value2;
            if (ans==-1 || ans>ans1+ans2)   ans=ans1+ans2;
        }
        tmp=0;
        for (int j=1;j<=len+1;j++)
        {
            if (bo[j])  t[++tmp]=t[j];
            //if (j>len)    t[j]=0;
        }
        len=tmp;
    }
    cout<< ans <<endl;
    return 0;
}