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

const int maxn = 100100;
const int maxlen = 3000100;

int n;

char s[maxlen + 5];
int sn;
char ans[maxlen + 5];

int nxt[maxlen + 5];

int get_nxt(int x) { return nxt[x] == x ? x : nxt[x] = get_nxt(nxt[x]); }

inline void add(int p)
{
	for (int i = get_nxt(p); i < p + sn; i = get_nxt(i))
	{
		ans[i] = s[i - p];
		nxt[i] = get_nxt(i + 1);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(ans, '?', sizeof ans);
	REP(i, 0, maxlen + 1) nxt[i] = i;
	REP(i, 0, n)
	{
		scanf("%s", s);
		sn = strlen(s);
		int k;
		scanf("%d", &k);
		REP(j, 0, k)
		{
			int x;
			scanf("%d", &x), --x;
			add(x);
		}
	}
	int N = maxlen;
	while (ans[N - 1] == '?') --N;
	REP(i, 0, N) if (ans[i] == '?') ans[i] = 'a';
	ans[N] = 0;
	printf("%s\n", ans);
	return 0;
}