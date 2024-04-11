#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MaxN = 5000010, MaxM = 5000010;

struct edge
{
    int to, dis, next;
};

edge e[MaxM];
int head[MaxN], dis[MaxN], cnt,x,y,z;
bool vis[MaxN];
int n, m, s;

inline void ad( int u, int v, int d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

std::priority_queue<node> q;


inline void dijkstra()
{
    dis[s] = 0;
    q.push( ( node ){0, s} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if( vis[x] )
            continue;
        vis[x] = 1;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( dis[y] > dis[x] + e[i].dis )
            {
                dis[y] = dis[x] + e[i].dis;
                if( !vis[y] )
                {
                    q.push( ( node ){dis[y], y} );
                }
            }
        }
    }
}


signed main()
{
    scanf( "%lld%lld", &n, &m);
    for(int i = 0; i <= 4*n; ++i)dis[i] = 0x7ffffffffff;
    for (int i=1;i<=m;i++)
    {
    	cin>>x>>y>>z;
    	x--,y--;
    	for (int j=0;j<4;j++) ad(x+j*n,y+j*n,z), ad(y+j*n,x+j*n,z);
    	for (int j=0;j<2;j++) ad(x+j*n,y+j*n+2*n,0), ad(y+j*n,x+j*n+2*n,0);
    	for (int j=0;j<3;j+=2) ad(x+j*n,y+j*n+n,2*z), ad(y+j*n,x+j*n+n,2*z);
    	ad(x,y+3*n,z);
    	ad(y,x+3*n,z);
    }
    dijkstra();
    for( int i = 2; i <= n; i++ )
        cout<<dis[i+3*n-1]<<" ";
    return 0;
}