#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define mod 1000000007
#define ll long long
#define N 110000
int n,m,tot,neg;
int head[N],nex[N<<1],to[N<<1],val[N<<1];
int vis[N],cnt[N],a[N],b[N],use[N],u1[N<<1];
int st[N][2],top,ans,du[N],f[N][2][2],g[N][2][2][2],d[N][2];
int e[N],sum;
void add(int x,int y,int z)
{
    nex[++ tot] = head[x];
    head[x] = tot;
    to[tot] = y;
    val[tot] = z;
}
void dfs(int x)
{
    if(use[x])return;
    use[x] = 1;
    for(int i = head[x]; i; i = nex[i])
        if(!u1[i])
        {
            e[++ sum] = i;
            u1[i] = u1[i ^ 1] = 1;
            dfs(to[i]);
        }
}
int get(int v,int x,int y)
{
    if(to[v] != abs(b[val[v]])) swap(x, y);
    int t = val[v];
    if(a[t] < 0)x ^= 1;
    if(b[t] < 0)y ^= 1;
    return x | y;
}
int main()
{
	n = read();
	m = read();
	tot = 1;
	int ans = 1;
    rep(i, 1, n)
    {
    	cnt[i] = read();
    	if(cnt[i] == 1)
        {
        	a[i] = read();
            if(vis[abs(a[i])])
            {
                st[top][0] = st[top][1] = 0;
                top --;
                (ans *= 2) %= mod;
                continue;
            }
            vis[abs(a[i])] = a[i];
            if(!du[abs(a[i])]) st[++ top][0] = st[top][1] = 1;
        }
        if(cnt[i] == 2)
        {
        	a[i] = read();
        	b[i] = read();
        	if(a[i] == -b[i])
            {
                neg ++;
                vis[abs(a[i])] = 1;
                (ans *= 2) %= mod;
            }
            else
            {
                int a1 = abs(a[i]), b1 = abs(b[i]);
                if(a1 == b1) vis[a1] = 1, st[++ top][0] = st[top][1] = 1;
                else
                {
                    add(a1, b1, i);
                    add(b1, a1, i);
                    du[a1] ++;
                    du[b1] ++;
                    if(vis[a1])st[top][0] = st[top][1] = 0, top --;
                    if(vis[b1])st[top][0] = st[top][1] = 0, top --;
                }
            }
        }
    }
    rep(now, 1, m)
    	if(!use[now] && du[now] != 2)
        {
            if(!du[now] && !vis[now]) (ans *= 2) %= mod;
            else if(!du[now])continue;
            else
            {
                sum = 0;
                dfs(now);
                rep(i, 1, sum)
                	memset(f[i], 0, sizeof(f[i]));
                if(vis[now])
                {
                    if(vis[now] < 0)
                    {
                        f[1][0][get(e[1], 0, 0) ^ 1] ++;
                        f[1][1][get(e[1], 0, 1) ^ 1] ++;
                        f[1][0][get(e[1], 1, 0)] ++;
                        f[1][1][get(e[1], 1, 1)] ++;
                    }
                    else
                    {
                        f[1][0][get(e[1], 0, 0)] ++;
                        f[1][1][get(e[1], 0, 1)] ++;
                        f[1][0][get(e[1], 1, 0) ^ 1] ++;
                        f[1][1][get(e[1], 1, 1) ^ 1] ++;
                    }
                }
                else
                {
                    f[1][0][get(e[1], 0, 0)] ++;
                    f[1][1][get(e[1], 0, 1)] ++;
                    f[1][0][get(e[1], 1, 0)] ++;
                    f[1][1][get(e[1], 1, 1)] ++;
                }
                rep(i, 1, sum - 1)
                	rep(j, 0, 1)
                		rep(k, 0, 1)
                			rep(t, 0, 1)
                				(f[i + 1][j][t ^ get(e[i + 1], k, j)] += f[i][k][t]) %= mod;

                top ++;
                rep(i, 0, 1)
                	rep(j, 0, 1)
                    {
                    	int t;
                        if(t = vis[to[e[sum]]]) (st[top][j ^ i ^ (t < 0)] += f[sum][i][j]) %= mod;
                        else (st[top][j] += f[sum][i][j]) %= mod;
                    }
            }
        }
    rep(now, 1, m)
    	if(!use[now] && du[now] == 2)
        {
            sum = 0;
            dfs(now);
            rep(i, 1, sum)
            	memset(g[i], 0, sizeof(g[i]));
            g[1][0][0][get(e[1], 0, 0)] ++;
            g[1][0][1][get(e[1], 0, 1)] ++;
            g[1][1][0][get(e[1], 1, 0)] ++;
            g[1][1][1][get(e[1], 1, 1)] ++;
            rep(i, 1, sum - 1)
            	rep(j, 0, 1)
            		rep(k, 0, 1)
            			rep(t, 0, 1)
            				rep(w, 0, 1)
            					(g[i + 1][j][t][w ^ get(e[i + 1], k, t)] += g[i][j][k][w])%=mod;
            top ++;
            rep(i, 0, 1)
            	rep(j, 0, 1)
            		rep(k, 0, 1)
	                    (st[top][get(e[sum], j, i) ^ k] += g[sum - 1][i][j][k]) %= mod;

        }
    d[0][0] = ans;
    rep(i, 1, top)
    	rep(j, 0, 1)
    		rep(k, 0, 1)
                (d[i][j ^ k] += (ll)d[i - 1][j] * st[i][k] % mod) %= mod;

    if(neg & 1) printf("%d\n",d[top][0]);
    else printf("%d\n",d[top][1]);
    return 0;
}