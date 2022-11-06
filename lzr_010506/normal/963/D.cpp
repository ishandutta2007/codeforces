#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define pii pair<int, int>
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define pb push_back
//#define mp make_pair
#define db double
#define sz(x) (int)(x).size()
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
#define modp 5000007
using namespace std;
const int blocks = 45;
const int N = 2e5 + 10;
char s[N], g[N];
int n, q, k;
ull h[N], bin[N];
int pos[N], cnt;
int tot, x;
vector<vector<int> > t;
vector<int> tt;
ull get_hash(int lx, int rx)
{
	return (h[rx] - ((ull)h[lx - 1] * bin[rx - lx + 1]));
}
int l[modp + 1];
vector<ull> pre,other,mp;
int cntt;
inline void insert(int u,ull v)
{
    cntt ++;
	other.pb(v);
	pre.pb(l[u]);
	l[u] = cntt;
	mp.pb(++ tot);
}
inline int get(ull h)
{
	x = (int) h % modp;
	if (x < 0) x += modp;
	for (int q = l[x]; ~q; q = pre[q])
		if (other[q] == h) return mp[q];
	return 0;
}
inline void deal(ull h)
{
	x=(int)h % modp;
	if (x < 0) x += modp;
	insert(x, h);
}
int main()
{
    other.pb(0);
    pre.pb(0);
    mp.pb(0);
	memset(l, -1 ,sizeof(l));
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 1, n)
		h[i] = ((ull)29 * h[i - 1] + s[i] - 'a' + 1);
	bin[0] = 1;
	rep(i, 1, n)
		bin[i] = ((ull)29 * bin[i - 1]);
	t.pb(tt);
	rep(i, 1, n)
		for (int j = i; j <= n && j < i + blocks; j ++)
		{
			ull now = get_hash(i, j);
			if (!get(now))
			{
				deal(now);
				t.pb(tt);
			}
			int y = get(now);
			t[y].pb(i);
		}
	q = read();
	while (q --)
	{
		k = read();
		scanf("%s",g + 1);
		int len = strlen(g + 1);
		if (len <= blocks)
		{
			ull now = 0;
			rep(i, 1, len)
				now = (29 * now + g[i] - 'a' + 1);
			int y = get(now);
			if (!y || sz(t[y]) < k) puts("-1");
			else
			{
				cnt = sz(t[y]);
				int ans = n;
				rep(i, 0, cnt - k)
				 	ans = min(ans, t[y][i + k - 1] - t[y][i] + len);
				printf("%d\n",ans);
			}
		}
		else
		{
			cnt = 0;
			ull now = 0;
			rep(i, 1, len) now = (29 * now + g[i] - 'a' + 1);
			rep(i, 1, n - len + 1)
				if (get_hash(i, i + len - 1) == now) pos[++ cnt] = i;
			if (cnt < k) puts("-1");
			else
			{
				int ans = n;
				rep(i, 1, cnt - k + 1)
					ans = min(ans, pos[i + k - 1] - pos[i] + len);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}