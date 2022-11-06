#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
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
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
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

const int N = 3e5 + 10;

vector<int> ans;

int T, n, m, a[N], b[N], cnt[N], fa[N];

int find(int x) 
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void check(int k) 
{
	rep(i, 1, n - k) b[i] = k + i;
	rep(i, n - k + 1, n) b[i] = k + i - n;

	rep(i, 1, n) fa[i] = i;
	rep(i, 1, n)
	{
		int fx = find(a[i]);
		int fy = find(b[i]);
		if (fx == fy) continue;
		fa[fx] = fy;
	}

	int s = n;
	rep(i, 1, n) if (fa[i] == i) s --;

	if (s <= m) ans.push_back((n - k) % n);
}

int main() 
{
	T = read();
	while(T --)
	{
		n = read();
		m = read();
		rep(i, 1, n)
		{
			a[i] = read();
			int t = a[i] - i;
			if (t < 0) t += n;
			cnt[t] ++;
		}
		int ned = n - (m << 1);
		rep0(i, n)
			if (cnt[i] >= ned) 
			{
				int k = i < n ? i : i - n;
				check(k);
			}

		///

		std::sort(ans.begin(), ans.end());

		int m = ans.size();
		printf("%d ", m);
		rep0(i, m) printf("%d ", ans[i]);
		printf("\n");

		///

		ans.clear();
		for (int i = 0; i <= n; ++i) cnt[i] = 0;
	}

	return 0;
}