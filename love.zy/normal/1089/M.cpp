/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-09-18
File: M.cpp
*****************************************/

#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

char s[4][163][32];
int id[10][10];

void init()
{
    int cnt = 0;
    for(int i = 1; i <= 9; ++ i)
        for(int j = 1; j <= 9; ++ j)
        {
            cnt ++;
            id[i][j] = cnt << 1;
        }
    for(int k = 1; k <= 30; ++ k)
        for(int i = 1; i <= 3; ++ i)
            for(int j = 1; j <= 162; ++ j)
            {
                if(k % 3 == 2)
                {
                    if(i == 1) s[i][j][k] = '.';
                    if(i >= 2) s[i][j][k] = '#';
                }else
                {
                    if(i == 1 && j % 2 == 0) s[i][j][k] = '.';
                    if(i == 1 && j % 2 == 1) s[i][j][k] = '#';
                    if(i == 2) s[i][j][k] = '#';
                    if(i == 3) s[i][j][k] = '.';
                }
            }
    for(int i = 1; i <= 9; ++ i)
        for(int j = 1; j <= 9; ++ j)
        {
            int ceng = 3 * j - 2, u = id[i][j];
            s[1][u][ceng + 1] = '#';
            s[1][u][ceng] = s[2][u][ceng] = '.';
        }
}

void add(int d, vi a)
{
    d = d * 3 - 2;
    for(int i = 1; i <= a.size(); ++ i)
        s[3][i][d] = 48 + a[i - 1];
}
int n;
void solve_hole(int x, int y)
{
    int d = x * 3 - 2, u = id[x][y];
    s[1][u][d] = s[2][u][d] = '.';
}
bool dis[11][11];
int fa[11],d[11];
vector<int> v[11],scc[11];
int find(int x)
{
    if(fa[x]==x)return fa[x];
    return fa[x]=find(fa[x]);
}
void SCC()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)dis[i][i]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)scanf("%d",&dis[i][j]);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]|=dis[i][k]&dis[k][j];
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)if(dis[i][j]&&dis[j][i])
        {
            int x=find(i),y=find(j);
            fa[x]=y;
        }
    for(int i=1;i<=n;++i)if(i==find(i))
    {
        for(int j=i+1;j<=n;++j)if(j==find(j))if(dis[i][j]^dis[j][i])
        {
            find(i);find(j);
            if(dis[i][j])v[fa[i]].push_back(fa[j]),++d[fa[j]];
            else v[fa[i]].push_back(fa[i]),++d[fa[i]];
        }
    }
    queue<int> q;
    for(int i=1;i<=n;++i)if(i==find(i))
    {
        if(!d[i])q.push(i);
    }
    int cnt=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        ++cnt;
        for(int i=1;i<=n;++i)if(find(i)==u)scc[cnt].push_back(i);
        add(cnt,scc[cnt]);
        //printf("%d : ", cnt); for(int p : scc[cnt]) printf("%d ", p); puts("");
        for(int i=1;i<=n;++i)if(find(i)==i&&dis[u][i]&&u!=i)
        {
            --d[i];
            if(!d[i])q.push(i);
        }
    }
    for(int i=1;i<=cnt;++i)
        for(int j=i+1;j<=cnt;++j)if(dis[scc[i][0]][scc[j][0]])solve_hole(i,j);
}
void print()
{
    printf("162 3 30\n");
    for(int k=1;k<=30;++k)
    {
        for(int i=1;i<=3;++i)
        {
            for(int j=1;j<=162;++j)
            {
                putchar(s[i][j][k]);
            }
            puts("");
        }
        puts("");
    }
}
int main()
{

    //OUT;
    init();
    SCC();
    print();
    return 0;
}