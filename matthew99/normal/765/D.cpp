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

int n, m;
int a[maxn + 5];

int b[maxn + 5];
int c[maxn + 5];

int id[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(id, -1, sizeof id);
	memset(c, -1, sizeof c);
	m = 0;
	REP(i, 0, n) 
	{
		scanf("%d", a + i), --a[i];
		if (!~id[a[i]]) id[a[i]] = m++;
		b[i] = id[a[i]];
		if (a[i] == i) c[id[a[i]]] = i;
	}
	REP(i, 0, m) if (!~c[i]) { printf("-1\n"); return 0; }
	REP(i, 0, m) assert(b[c[i]] == i);
	REP(i, 0, n) assert(c[b[i]] == a[i]);
	printf("%d\n", m);
	REP(i, 0, n) printf("%d ", b[i] + 1);
	printf("\n");
	REP(i, 0, m) printf("%d ", c[i] + 1);
	printf("\n");
	return 0;
}