#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_Rck
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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

int tag[1010], vis[1010];
map<int, int> M;

int main()
{
	int T = read();
	while (T --)
	{
		int n = read();
		int k = read();
		rep0(i, n * 10) tag[i] = vis[i] = 0;
		M.clear();
		int ans = 0;
		rep0(i, k)
		{
			int a = read();
			int b = read();
			M[a] = b;
			M[b] = a;
			tag[a] = 1;
			tag[b] = 1;
			if (a > b) swap(a, b);
			rep(j, a + 1, b - 1)
				if (tag[j] && (M[j] < a || M[j] > b))
					ans ++;
		}
		int cnt = k;
		int cnt2 = 0;
		int L = 1;
		int R = 1;
		while (tag[L]) L ++;
		while (tag[R] || cnt2 != n - k)
		{
			if (R > 2 * n) break;
			if (tag[R] == 0) cnt2 ++;
			R ++;
		}
		while (cnt != n)
		{
			rep(i, L + 1, R - 1)
			{
				if (!tag[i]) continue;
				if (M[i] >= L && M[i] <= R) continue;
				ans ++;
			}
			tag[L] = 1;
			tag[R] = 1;
			cnt ++;
			if (cnt == n)break;
			while (tag[L]) L ++;
			while (tag[R]) R ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}