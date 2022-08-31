#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

const int MaxN=1<<19;

int n,m,num;
int x[MaxN],y[MaxN],t[MaxN];
int p[MaxN];
int ans[MaxN];

map<int,int> v[MaxN<<1];

int get(int x)
{
    int L=1,R=num;
    while (L<=R)
    {
        int mid=(L+R)>>1;
        if (p[mid]==x) return mid;
        (p[mid]<x)?L=mid+1:R=mid-1;
    }
}

bool cmp(int i,int j)
{
    return x[i]<x[j]||(x[i]==x[j]&&i<j);
}

void init()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n+m;++i)
    {
        scanf("%d%d%d",&x[i],&y[i],&t[i]);
        p[++num]=x[i];
        p[++num]=y[i];
    }
    sort(p+1,p+num+1);
    int tmp=1;
    for (int i=2;i<=num;++i)
        if (p[tmp]!=p[i]) p[++tmp]=p[i];
    num=tmp;
    for (int i=1;i<=n+m;++i)
    {
        x[i]=get(x[i]);
        y[i]=get(y[i]);
    }
    for (int i=1;i<=n+m;++i)
        p[i]=i;
    sort(p+1,p+n+m+1,cmp);
}

void add(int x,int p)
{
    int k=x+MaxN-1;
    while (k)
    {
        v[k].insert(map<int,int>::value_type(t[p],p));
        k>>=1;
    }
}

int solve(int k,int L,int R,int x,int y,int p)
{
    if (L==x&&R==y)
        return v[k].lower_bound(p)->second;
    int mid=(L+R)>>1;
    if (y<=mid)
        return solve(k<<1,L,mid,x,y,p);
    if (x>mid)
        return solve((k<<1)|1,mid+1,R,x,y,p);
    int Lc=solve(k<<1,L,mid,x,mid,p);
    int Rc=solve((k<<1)|1,mid+1,R,mid+1,y,p);
    return (t[Lc]<t[Rc])?Lc:Rc;
}

void work()
{
    t[0]=2000000000;
    for (int i=1;i<(MaxN<<1);++i)
        v[i].insert(map<int,int>::value_type(t[0],0));
    for (int k=1;k<=n+m;++k)
    {
        int i=p[k];
        if (i<=n)
            add(y[i],i);
        else
        {
            ans[i-n]=solve(1,1,MaxN,y[i],num,t[i]);
            if (!ans[i-n]) ans[i-n]=-1;
        }
        
    }
    printf("%d",ans[1]);
    for (int i=2;i<=m;++i)
        printf(" %d",ans[i]);
    puts("");
}

int main()
{
    init();
    work();
    return 0;
}