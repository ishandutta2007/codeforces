#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
//#define ls rt << 1
//#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
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
const int N = 2e5 + 10;
const int P = 1e9 + 7;
int head[N];
ll f[2][N], a[N];
int dfn[N], n, ans, cnt, tot;
struct Edge 
{
	int to, next;
}e[N << 1];
void insert(int x,int y)
{
	e[++ tot].to = y;
	e[tot].next = head[x];
	head[x] = tot;
}
void dfs(int x, int fa)
{
	dfn[x] = ++ cnt;
    for(int i =head[x];i;i=e[i].next)
    {
    	int to = e[i].to;
    	if(to == fa) continue;
       	dfs(to, x);
       	f[0][x] += f[1][to];
       	f[1][x] += f[0][to];
    }
    f[0][x] ++;
}
void dfs1(int x, int fa, ll s0, ll s1)
{
    for(int i = head[x]; i; i = e[i].next)
    {
    	int to = e[i].to;
    	if(to == fa) 
    	{
    		ans = (ans + 1ll * a[x] * (s1 - s0 + P) % P * (f[1][x] + f[0][x]) % P) % P; 
    		continue;
    	}
    	ll tmp1 = 1ll * a[x] * (f[1][to] - f[0][to] + P);
       	ll tmp2 = n - f[1][to] - f[0][to] + P;
       	tmp1 = (tmp1 % P + P) % P;
       	tmp2 = (tmp2 % P + P) % P;
       	tmp1 = tmp1 * tmp2 % P;
       	ans = (ans + tmp1) % P;
    }
    ans = (ans + 1ll * a[x] * n % P) % P;
    for(int i = head[x]; i; i = e[i].next)
    {
    	int to = e[i].to;
    	if(to == fa) continue;
    	ll now1 = f[0][x] - f[1][to] + s1;
    	ll now2 = f[1][x] - f[0][to] + s0;
        dfs1(to, x, now1, now2);
    }
}
int main()
{
	n = read();
	rep(i, 1, n) a[i] = read1();
	rep(i, 1, n) a[i] = (a[i] + P) % P;
   	
   	rep(i, 1, n - 1)
   	{
   		int x, y;
   		x = read();
   		y = read();
   		insert(x, y);
   		insert(y, x);
   	}
    ans = 0;
    dfs(1, 0);
    dfs1(1, 0, 0, 0);
  	cout << ans;
    return 0;
}