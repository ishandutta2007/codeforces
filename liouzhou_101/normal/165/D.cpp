#include<cstdio>
#include<vector>

using namespace std;

const int MaxN=100010;

int n,p;
int x[MaxN],y[MaxN];
vector<int> v[MaxN],son[MaxN];
int dis[MaxN],pre[MaxN],pF[MaxN],flag[MaxN],able[MaxN];
int size[MaxN];

void build(int belong,int now,int deep)
{
    dis[now]=deep;
    flag[now]=able[now]=1;
    if (size[belong]==p) belong=now;
    pF[now]=belong;
    ++size[belong];
    for (vector<int>::iterator it=v[now].begin();it!=v[now].end();++it)
        if (!dis[*it])
        {
            pre[*it]=now;
            build(belong,*it,deep+1);
        }
}

void init()
{
    scanf("%d",&n);
    for (p=1;p*p<n;++p);
    for (int i=1;i<n;++i)
    {
        scanf("%d%d",&x[i],&y[i]);
        v[x[i]].push_back(y[i]);
        v[y[i]].push_back(x[i]);
    }
    build(1,1,1);
    for (int i=1;i<=n;++i)
        for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
            if (dis[*it]==dis[i]+1&&pF[i]==pF[*it])
                son[i].push_back(*it);
}

void draw(int now)
{
    if (now!=pF[now])
        able[now]=flag[now]&able[pre[now]];
    for (vector<int>::iterator it=son[now].begin();it!=son[now].end();++it)
        draw(*it);
}

void paint(int now,int color)
{
    flag[now]=color;
    draw(now);
}

void solve(int px,int py)
{
    int x=px,y=py;
    while (pF[x]!=pF[y])
    {
        if (dis[pF[x]]>=dis[pF[y]])
        {
            if (!able[x])
            {
                puts("-1");
                return;
            }
            if (!flag[pF[x]])
            {
                puts("-1");
                return;
            }
            x=pre[pF[x]];
        }
        else
        {
            if (!able[y])
            {
                puts("-1");
                return;
            }
            if (!flag[pF[y]])
            {
                puts("-1");
                return;
            }
            y=pre[pF[y]];
        }
    }
    while (x!=y)
    {
        if (dis[x]>=dis[y])
        {
            if (!flag[x])
            {
                puts("-1");
                return;
            }
            x=pre[x];
        }
        else
        {
            if (!flag[y])
            {
                puts("-1");
                return;
            }
            y=pre[y];
        }
    }
    printf("%d\n",dis[px]+dis[py]-dis[x]-dis[x]);
}

void work()
{
    int m;
    scanf("%d",&m);
    while (m--)
    {
        int type;
        scanf("%d",&type);
        if (type<3)
        {
            int edge;
            scanf("%d",&edge);
            edge=(dis[x[edge]]>dis[y[edge]])?x[edge]:y[edge];
            paint(edge,2-type);
        }
        else
        {
            int px,py;
            scanf("%d%d",&px,&py);
            solve(px,py);
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}