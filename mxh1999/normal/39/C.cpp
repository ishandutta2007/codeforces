//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 2010
struct qujian
{
    int l,r,id;
}   a[maxn];
int cnt[maxn<<1],tot;
int f[maxn];
int tmp[maxn<<1];
int gui[maxn<<1];
int ans[maxn][maxn];
int ans1[maxn],sum;
int n;

bool cmp(const qujian &a,const qujian &b)
{
    if (a.r!=b.r)   return a.r<b.r;
    return a.l>b.l;
}
bool cmp1(const int &q,const int &p)
{
    return a[q].id<a[p].id;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int s,r,x,y;
        scanf("%d%d",&s,&r);
        x=s-r;
        y=s+r;
        a[i].l=x;
        a[i].r=y;
        a[i].id=i;
        cnt[++tot]=x;
        cnt[++tot]=y;
    }
    sort(cnt+1,cnt+tot+1);
    tot=unique(cnt+1,cnt+tot+1)-(cnt+1);
    for (int i=1;i<=n;i++)
    {
        a[i].l=lower_bound(cnt+1,cnt+tot+1,a[i].l)-cnt;
        a[i].r=lower_bound(cnt+1,cnt+tot+1,a[i].r)-cnt;
    }
    n++;
    a[n].l=1,a[n].r=tot,a[n].id=n;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        //memset(tmp,0,sizeof(tmp));
        int h=1;
        for (int j=1;j<=a[h].r;j++)
        {
            tmp[j]=tmp[j-1];
            gui[j]=gui[j-1];
            while (h<=n && a[h].r<j)    h++;
            while (h<=n && a[h].r==j)
            {
                if (a[h].l>=a[i].l)
                if (tmp[a[h].l]+f[h]>tmp[j])
                {
                    tmp[j]=tmp[a[h].l]+f[h];
                    gui[j]=h;
                }
                h++;
            }
        }
        f[i]=tmp[a[i].r]+1;
        int q=a[i].r;
        ans[i][0]=0;
        while (gui[q])
        {
            ans[i][++ans[i][0]]=gui[q];
            q=a[gui[q]].l;
        }
    }
    printf("%d\n",f[n]-1);
    int h=1,t=1;
    ans1[1]=n;
    while (h<=t)
    {
        for (int i=1;i<=ans[ans1[h]][0];i++)
        {
            ans1[++t]=ans[ans1[h]][i];
        }
        h++;
    }
    sort(ans1+1,ans1+t+1,cmp1);
    bool bo=false;
    for (int i=1;i<=t;i++)
    if (a[ans1[i]].id!=n)
    {
        if (bo) printf(" ");else bo=true;
        printf("%d",a[ans1[i]].id);
    }
    printf("\n");
    return 0;
}