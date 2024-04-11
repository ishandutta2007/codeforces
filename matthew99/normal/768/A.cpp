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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static int a[100005];
	int n;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	int Min = *min_element(a, a + n);
	int Max = *max_element(a, a + n);
	int sum = 0;
	REP(i, 0, n) sum += (a[i] != Min && a[i] != Max);
	printf("%d\n", sum);
	return 0;
}