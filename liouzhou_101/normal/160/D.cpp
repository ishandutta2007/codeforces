#include<cstdio>
#include<algorithm>

using namespace std;

const int MaxN=100010;

int n,m;
int x[MaxN],y[MaxN],c[MaxN],p[MaxN];
int F[MaxN];
int ans[MaxN];
int num,Q[MaxN];
int edge,map[MaxN],way[MaxN<<1],next[MaxN<<1];
int tot,mark[MaxN],list[MaxN];
int Time,DFN[MaxN],LOW[MaxN];

bool cmp(int i,int j)
{
    return c[i]<c[j];
}

int father(int x)
{
    return (F[x]==x)?x:F[x]=father(F[x]);
}

int get(int x)
{
    if (!mark[x])
    {
        ++tot;
        mark[x]=tot;
        list[tot]=x;
    }
    return mark[x];
}

void addedge(int x,int y)
{
    ++edge;
    way[edge]=y;
    next[edge]=map[x];
    map[x]=edge;
}

void tarjan(int x,int pre)
{
    DFN[x]=LOW[x]=++Time;
    for (int p=map[x];p;p=next[p])
    {
        if (!DFN[way[p]])
        {
            tarjan(way[p],p);
            LOW[x]=min(LOW[x],LOW[way[p]]);
        }
        else if ((p+1)/2!=(pre+1)/2)
            LOW[x]=min(LOW[x],DFN[way[p]]);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x[i],&y[i],&c[i]);
        p[i]=i;
    }
    sort(p+1,p+m+1,cmp);
    for (int i=1;i<=n;++i)
        F[i]=i;
    for (int k=1;k<=m;++k)
    {
        if (c[p[k]]==c[p[k-1]]) continue;
        num=edge=tot=0;
        for (int i=k;i<=m;++i)
        {
            if (c[p[i]]!=c[p[k]]) break;
            int fx=father(x[p[i]]),fy=father(y[p[i]]);
            if (fx==fy) continue;
            Q[++num]=p[i];
            ans[Q[num]]=1;
            fx=get(fx);
            fy=get(fy);
            addedge(fx,fy);
            addedge(fy,fx);
        }
        Time=0;
        for (int i=1;i<=tot;++i)
            if (!DFN[i]) tarjan(i,0);
        for (int i=1;i<=num;++i)
            if (DFN[get(father(x[Q[i]]))]<LOW[get(father(y[Q[i]]))]||DFN[get(father(y[Q[i]]))]<LOW[get(father(x[Q[i]]))])
                ans[Q[i]]=2;
        for (int i=1;i<=tot;++i)
            DFN[i]=map[i]=mark[list[i]]=0;
        for (int i=1;i<=edge;++i)
            next[i]=0;
        for (int i=1;i<=num;++i)
        {
            int fx=father(x[Q[i]]),fy=father(y[Q[i]]);
            F[fx]=fy;
        }
    }
    for (int i=1;i<=m;++i)
    {
        if (ans[i]==0) puts("none");
        if (ans[i]==1) puts("at least one");
        if (ans[i]==2) puts("any");
    }
    return 0;
}