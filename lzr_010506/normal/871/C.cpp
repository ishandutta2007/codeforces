#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 200010;
const int mod = 1e9 + 7;
map<pii, int> s;
pii Xs[N];
int n, cnt, v, tmp = 1;
int a[N], b[N];
int vis[N], head[N];
int to[N << 1], Next[N << 1];
int f;

inline void ins(int a, int b)
{
    Next[++ cnt] = head[a];
	head[a] = cnt;
	to[cnt] = b;
}

inline void insert(int a,int b)
{
    ins(a, b);
    ins(b, a);
}
int dfs(int x, int fa)
{
	vis[x] = 1;
	int ans = 1;
	for(int i = head[x]; i; i = Next[i])
	{
		if(to[i] == fa) continue;
		if(vis[to[i]])
		{
			f = 0;
			continue;
		}
		ans += dfs(to[i], x);
	}
	return ans;
}
int main()
{
	n = read();
	rep(i, 0, n - 1)
	{
		a[i] = read();
		b[i] = read();
		Xs[cnt ++] = mp(a[i], 0);
		Xs[cnt ++] = mp(b[i], 1);
	}
	sort(Xs, Xs + cnt);
	int tmp = 1;
	s[Xs[0]] = 1;
	rep(i, 1, cnt - 1)
	{
		if(Xs[i] != Xs[i - 1]) tmp ++;
		s[Xs[i]] = tmp;
	}
	cnt = 0;
	rep(i, 0, n - 1)
	{
		int l = s[mp(a[i], 0)], r = s[mp(b[i], 1)];
		if(l != r) insert(l, r);
	}
	ll ans = 1;
	rep(i, 1, tmp)
	{
		if(vis[i]) continue;
		f = 1;
		int sz = dfs(i, 0), now = 1;
		while(sz --) now = now * 2 % mod;
		now = (now - f + mod) % mod;
		ans = ans * now % mod;
	}
	printf("%I64d",ans);
	return 0;
}