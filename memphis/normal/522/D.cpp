#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstring>
using namespace std;

bool st;

struct re{
    int tp,x,y1,y2,z; //    
    bool operator () (const re &a,const re &b) {
        return a.x<b.x||(a.x==b.x&&a.tp<b.tp);
    }
}opt[2000001];

struct rec{
    int num,id;
    bool operator () (const rec &a,const rec &b) {
        return a.num<b.num;
    }
}ls[500001];

int pre[500001];
int C[2000001],a[500001];
int n,m,opt_cnt,x,y,ans;
int Ans[500001];
char out[11];

bool en;

void add(int x1,int y1,int y2,int z)
{
    opt[++opt_cnt]=(re){0,x1,y1,y2,z};
}

void add(int p,int l,int r,int x,int y,int z)
{
    if (l==x&&r==y)
    {
        if (z<C[p]) C[p]=z;
        return;
    }
    int mid=(l+r)>>1,ll=p<<1;
    if (y<=mid) add(ll,l,mid,x,y,z);
    else if (x>=mid+1) add(ll+1,mid+1,r,x,y,z);
    else {
        add(ll,l,mid,x,mid,z);
        add(ll+1,mid+1,r,mid+1,y,z);
    }
}

void query(int p,int l,int r,int x)
{
    if (C[p]<ans) ans=C[p];
    if (l==r) return;
    int mid=(l+r)>>1,ll=p<<1;
    if (x<=mid) query(ll,l,mid,x);
    else query(ll+1,mid+1,r,x);
}

void read(int &x)
{
    char c; int flag=0;
    c=getchar();
    while ((c<'0'||c>'9')&&c!='-') c=getchar();
    if (c=='-') 
    {
        flag=1;
        c=getchar();
    }
    x=0;
    while (c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    if (flag) x=-x;
}

void pt(int x)
{
    int st_cnt=0;
    while (x)
    {
        out[++st_cnt]=x%10+'0';
        x/=10;
    }
    for (int i=st_cnt;i;i--)
        putchar(out[i]);
    puts("");
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        read(x); ls[i]=(rec){x,i};
    }
    
    sort(ls+1,ls+1+n,rec());
    ls[0].num=ls[1].num-1;
    int rank=0;
    for (int i=1;i<=n;i++)
    {
        if (ls[i].num!=ls[i-1].num) rank++;
        a[ls[i].id]=rank;
    }
    
    for (int i=1;i<=n;i++)
    {
        x=a[i];
        if (pre[x])
            add(i,1,pre[x],i-pre[x]);
        pre[x]=i;
    }
    
    int ttt=clock();
    
    for (int i=1;i<=m;i++)
    {

        read(y); read(x);
        opt[++opt_cnt]=(re){1,x,y,y,i};
    }
    sort(opt+1,opt+1+opt_cnt,re());
    
    for (int i=1;i<=2000000;i++) C[i]=2000000000;
    
    for (int i=1;i<=opt_cnt;i++)
    {
        int j=i;
        for (;j+1<=opt_cnt&&opt[j+1].x==opt[j].x;j++);
        for (int k=i;k<=j;k++)
        {
            if (opt[k].tp==0)
            {
                add(1,1,n,opt[k].y1,opt[k].y2,opt[k].z);
            }
            if (opt[k].tp==1)
            {
                ans=2000000000;
                query(1,1,n,opt[k].y1);
                Ans[opt[k].z]=ans;
            }
        }
        i=j;
    }
    for (int i=1;i<=m;i++) 
        if (Ans[i]!=2000000000) pt(Ans[i]);
        else puts("-1");
}