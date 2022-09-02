#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 200100;

int n;
int fa[maxn + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

bool in[maxn + 5];
int cnt[maxn + 5], cntin[maxn + 5];
bool loop[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n << 1) fa[i] = i;
	REP(i, 0, n)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		if (x == y) loop[x] = 1;
		in[x] = 1;
		fa[get(x)] = get(y);
	}
	REP(i, 0, n << 1) ++cnt[get(i)], cntin[get(i)] += in[i], loop[get(i)] |= loop[i];
	int ans = 1;
	REP(i, 0, n << 1) if (cnt[i] && cnt[i] > 1 && !loop[i])
	{
		if (cntin[i] == cnt[i]) (ans <<= 1) %= Mod;
		else ans = (LL)ans * cnt[i] % Mod;
	}
	printf("%d\n", ans);
	return 0;
}