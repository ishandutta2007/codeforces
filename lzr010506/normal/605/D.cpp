#include <bits/stdc++.h>
#define FOR(i,x,y)  for(int i = x; i < y; i ++)
#define IFOR(i,x,y) for(int i = x; i > y; i --)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) ({x & (-x);})
#define pii pair<int, int>
#define vi vector<int>
#define mpii map<int, int>
#define sit set <pii> :: iterator
using namespace std;
const int N = 100010;
bool vis[N << 1];
int n, m, a[N], b[N], c[N], d[N];
mpii mat;
set <pii> cc[N << 1];
vi vx;

inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}

void modify(int x, pii val)
{
    while(x <= m)
    {
        cc[x].insert(val);
        x += lowbit(x);
    }
}

vi query(int x,int y)
{
    vi tem;
    while(x)
    {
        sit last = cc[x].upper_bound(mp(y,N));
        sit it;
        for(it = cc[x].begin(); it != last; it ++) tem.pb(it->se);
        cc[x].erase(cc[x].begin(),last);
        x -= lowbit(x);
    }
    return tem;
}

int dist[N], fa[N], path[N];

void bfs()
{
    memset(fa, -1, sizeof(fa));
    memset(dist, -1, sizeof(dist));
    vi u = query(mat[0], 0);
    queue <int> q;
    FOR(i, 0, (int)u.size())
        q.push(u[i]), vis[u[i]] = true, dist[u[i]] = 1;
    while(!q.empty())
    {
        int id = q.front();
        q.pop();
        vi v = query(mat[c[id]], d[id]);
        FOR(i,0,(int)v.size())
        {
            if(vis[v[i]]) continue;
            vis[v[i]] = true;
            dist[v[i]] = dist[id] + 1;
            fa[v[i]] = id;
            q.push(v[i]);
        }
    }
}

int main()
{
    n = read();
    FOR(i, 0, n)
        a[i] = read(), b[i] = read(), c[i] = read(), d[i] = read(),
        vx.pb(a[i]), vx.pb(c[i]);
    sort(vx.begin(),vx.end());
    m = 0;
    mat[vx[0]] = ++ m;
    FOR(i, 1, (int)vx.size())
        if(vx[i] > vx[i - 1]) mat[vx[i]] = ++ m;

    FOR(i, 0, m + 1)
        cc[i].clear();
    FOR(i, 0, n)
        modify(mat[a[i]], mp(b[i],i));
    bfs();
    printf("%d\n",dist[n - 1]);
    if(dist[n - 1] == -1) return 0;
    else
    {
        int cnt = 0;
        int u = n - 1;
        while(u != -1)
        {
            path[cnt ++] = u + 1;
            u = fa[u];
        }
        printf("%d", path[cnt - 1]);
        IFOR(i, cnt - 2, -1)
            printf(" %d", path[i]);
        printf("\n");
    }

    return 0;
}