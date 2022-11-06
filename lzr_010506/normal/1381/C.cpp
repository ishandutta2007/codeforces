#include <bits/stdc++.h>
#define pcc pair<char, char>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define eps 1e-9
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e6 + 10;
int n, x, y;
int ans[N], a[N], cnt[N];
vi c[N], tmp;
priority_queue< pii > pq;
int main()
{
	int T = read();
	while (T --)
	{
		n = read();
		x = read();
		y = read();
		rep(i, 1, n + 1) c[i].clear();
		rep(i, 1, n) a[i] = read(), c[a[i]].pb(i);
		if (y == n && ((y - x) & 1))
		{
			rep(i, 1, n + 1) {cnt[i] = 0;}
			rep(i, 1, n)
				cnt[a[i]] ++;
			
			rep(i, 1, n) ans[i] = 0;
			int C = -1;
			for (int i = 1; i <= n + 1; i++) if (!cnt[i]) {C = i; break;}
			priority_queue<pii, vector<pii> > pque;
			while (pque.size()) pque.pop();
			for (int i = 1; i <= n + 1; i++) if (cnt[i]) pque.push(mp(cnt[i], i));
			for (int i = 0; i < x; i++)
			{
				pii p = pque.top(); pque.pop();
				ans[c[p.S].back()] = p.S; c[p.S].pop_back();
				p.F--; if (p.F) pque.push(p);
			}
			tmp.clear();
			while (pque.size())
			{
				pii p = pque.top(); pque.pop();
				for (int i = 0; i < p.F; i++) tmp.push_back(c[p.S].back()), c[p.S].pop_back();
			}
			int sz = (int)tmp.size();
			int need = y - x;
			for (int i = 0; i < sz; i++)
			{
				if (!need) break;
				int x = tmp[i], y = tmp[(i + sz / 2) % sz];
				if (a[x] != a[y]) {ans[x] = a[y], need--;}
			}
			if (need) {puts("NO"); continue;}
			puts("YES");
			rep(i, 1, n) if (ans[i] == 0) ans[i] = C;
			rep(i, 1, n) printf("%d ", ans[i]);
			puts("");
			continue;
		}
		int flag = 0;
		rep(i, 1, n + 1) if (c[i].empty()) flag = i;
		rep(i, 1, n) ans[i] = flag;
		//rep(i, 1, n) cout << ans[i] << endl;
		while (!pq.empty()) pq.pop();
		rep(i, 1, n + 1)
		if (!c[i].empty())
			pq.push(mp(c[i].size(), i));
		y -= x;
		while (x)
		{
			pii p = pq.top();
			pq.pop();
			ans[c[p.Y].back()] = p.Y;
			c[p.Y].pop_back();
			if (-- p.X) pq.push(p);
			x --;
		}
		bool ok = 1;
		while (y)
		{
			pii a = pq.top();
			pq.pop();
			if (pq.empty()) {ok = 0; break;}
			pii b = pq.top();
			pq.pop();
			ans[c[a.Y].back()] = b.Y;
			y --;
			if (y)
			{
				ans[c[b.Y].back()] = a.Y;
				y --;
				if (y)
				{
					c[a.Y].pop_back();
					c[b.Y].pop_back();
					if (-- a.X) pq.push(a);
					if (-- b.X) pq.push(b);
				}
			}
		}
		if (ok)
		{
			puts("YES");
			rep(i, 1, n) printf("%d ", ans[i]);
			puts("");
			continue;
		}

		puts("NO");
	}

	return 0;
}