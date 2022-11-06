#include <bits/stdc++.h>
#include <math.h>
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
using namespace std;
inline int read()
{
		int x = 0, f = 1; char ch = getchar();
		while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
		while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
		return x * f;
}
const int INF = 1e9 + 7;

struct Node
{
	static const int K = 5;
	int d = 0;
	array<pii, K> b;
	void add(int x, int cnt)
	{
	    assert(cnt > 0);
		rep(i, 0, d - 1)
			if (b[i].X == x)
			{
				b[i].Y += cnt;
				return;
			}
		b[d ++] = { x, cnt };
		if (d == K)
		{
			int Min = cnt;
			rep(i, 0, d - 2) Min = min(Min, b[i].Y);
			for(int i = 0; i < d; )
				if ((b[i].Y -= Min) == 0) swap(b[i], b[-- d]);
				else i ++;
			assert(d < K);
		}
	}
	void merge(const Node &x)
	{
		rep(j, 0, x.d - 1)
			add(x.b[j].X, x.b[j].Y);
	}
};

int main()
{
	int n = read();
	int q = read();
	vector<int> a(n);
	rep(i, 0, n - 1) a[i] =  read();
	int cnt = 1;
	while (cnt < n) cnt *= 2;
	vector<Node> t(cnt * 2);
	rep(i, 0, n - 1) t[cnt + i].add(a[i], 1);
    for (int i = cnt - 1; i > 0; -- i)
	{
		t[i] = t[i * 2];
		t[i].merge(t[i * 2 + 1]);
	}
	vector<vi> vs(*max_element(a.begin(), a.end()) + 1);
	rep(i, 0, n - 1) vs[a[i]].pb(i);
	ll sum = 0;
	while(q --)
	{
		int L = read();
		int R = read();
		int K = read();
		L --;
		Node qr;
		for (int l = L + cnt, r = R + cnt; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1) qr.merge(t[l ++]);
			if (r & 1) qr.merge(t[-- r]);
		}
		int ans = INF;
		rep(j, 0, qr.d - 1)
		{
			int x = qr.b[j].X;
			const auto &v = vs[x];
			int cnt = (int)(lower_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L));
			if (cnt * K > R - L) ans = min(ans, x);
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}

	return 0;
}