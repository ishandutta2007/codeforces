#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100000, maxm = 100000, max0 = 200000;

int n;
int a[maxn + 5];

vector<int> v;
int m;
int b[maxm + 5];

int N;

int nxt[max0 + 5];
bool ok[max0 + 5];

inline void init()
{
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		if (a[i] != -1) v.pb(a[i]);
	}
	scanf("%d", &m);
	REP(i, 0, m) scanf("%d", b + i), v.pb(b[i]);
	v.pb(0);
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	REP(i, 0, n) if (a[i] != -1) a[i] = lower_bound(ALL(v), a[i]) - v.begin();
	REP(i, 0, m) ok[b[i] = lower_bound(ALL(v), b[i]) - v.begin()] = 1;
	N = SZ(v);
	int lst = N;
	for (int i = N - 1; i >= 0; --i)
	{
		nxt[i] = lst;
		if (ok[i]) lst = i;
	}
}

int pre[maxn + 5];
int Maxp = -1;

int Max[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	srand(time(NULL));
#endif
	init();
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	static int f[maxn + 5], belong[maxn + 5];
	memset(f, oo, sizeof f);
	f[0] = 0;
	belong[0] = -1;
	REP(i, 0, n)
	{
		if (a[i] == -1)
		{
			for (int j = n; j >= 0; --j)
			{
				if (f[j] >= oo || nxt[f[j]] == N) continue;
				if (f[j + 1] > nxt[f[j]]) f[j + 1] = nxt[f[j]], belong[j + 1] = belong[j];
			}
		}
		else
		{
			int l = 0, r = n;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				if (f[mid] >= a[i]) r = mid - 1;
				else l = mid;
			}
			pre[i] = belong[l];
			if (f[l + 1] > a[i]) f[l + 1] = a[i], belong[l + 1] = i;
		}
	}
	for (int i = n; i >= 0; --i)
		if (f[i] < oo)
		{
			Maxp = belong[i];
			break;
		}
	int u = Maxp;
	int i = n - 1;
	while (i > Maxp) Max[i--] = oo;
	static bool in[maxn + 5];
	int cnt[max0 + 5];
	memset(in, 0, sizeof in);
	REP(i, 0, m) ++cnt[b[i]];
	while (u >= 0)
	{
		in[u] = 1;
		while (i > pre[u]) Max[i--] = a[u];
		u = pre[u];
	}
	int cur = nxt[0];
	REP(i, 0, n)
	{
		if (a[i] == -1)
		{
			if (cur < N && cur < Max[i]) 
			{
				--cnt[cur], a[i] = cur, cur = nxt[cur];
			}
		}
		else if (in[i]) cur = nxt[a[i]];
	}
	int j = 0;
	REP(i, 0, n)
		if (a[i] == -1)
		{
			while (!cnt[j]) ++j;
			a[i] = j;
			--cnt[j];
		}
	REP(i, 0, n) printf("%d ", v[a[i]]);
	return 0;
}