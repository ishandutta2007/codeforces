#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

const int maxn = 100000, maxlen = 500000;

int n;

int tot = 0;
int go[(maxlen << 1)][26], fa[(maxlen << 1) + 5], Max[(maxlen << 1) + 5];

int rt = 0;

LL sum[(maxlen << 1) + 5];
LL ans = 0;

inline int add(int p, int w)
{
	if (go[p][w] && Max[go[p][w]] == Max[p] + 1) return go[p][w];
	int np = tot++;
	fa[np] = -1;
	Max[np] = Max[p] + 1;
	while (p != -1 && !go[p][w]) go[p][w] = np, p = fa[p];
	if (p == -1) fa[np] = rt;
	else
	{
		int q = go[p][w];
		if (Max[q] == Max[p] + 1) fa[np] = q;
		else
		{
			int nq = tot++;
			fa[nq] = -1;
			Max[nq] = Max[p] + 1;
			memcpy(go[nq], go[q], sizeof go[nq]);
			fa[nq] = fa[q];
			fa[np] = fa[q] = nq;
			while (p != -1 && go[p][w] == q) go[p][w] = nq, p = fa[p];
		}
	}
	return np;
}

vector<int> all[maxlen + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static string s[maxn + 5];
	scanf("%d", &n);
	REP(i, 0, n) cin >> s[i];
	fa[0] = -1;
	tot = 1;
	int L = 0;
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		int cur = 0;
		for (auto c : s[i]) 
			cur = add(cur, c - 'a'), sum[cur] += x;
		chkmax(L, SZ(s[i]));
	}
	REP(i, 0, tot) all[Max[i]].pb(i);
	for (int i = L; i >= 1; --i)
		for (auto nd : all[i]) chkmax(ans, i * sum[nd]), sum[fa[nd]] += sum[nd];
	printf("%I64d\n", ans);
	return 0;
}