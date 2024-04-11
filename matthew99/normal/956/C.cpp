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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n;
int a[maxn + 5];
int Max[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	Max[0] = 0;
	REP(i, 0, n) Max[i + 1] = max(Max[i], a[i]);
	int now = 0;
	LL ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i] > now) ans += LL(a[i] - now) * (n - 1 - i), now = a[i];
		else ans += now - a[i];
		if (now > Max[i]) --now;
	}
	cout << ans << endl;
	return 0;
}