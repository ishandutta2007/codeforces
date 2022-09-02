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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	if (n > m) swap(n, m);
	if (n >= 3)
	{
		LL ans = (LL)n * m;
		ans -= ans & 1;
		cout << ans << endl;
	}
	else if (n == 2)
	{
		LL tmp = (LL)n * m;
		if (m == 2) tmp -= 4;
		if (m == 3) tmp -= 2;
		if (m == 7) tmp -= 2;
		cout << tmp << endl;
	}
	else if (n == 1)
	{
		LL tmp = (LL)n * m;
		if (m % 6 <= 3) tmp -= m % 6;
		else if (m % 6) tmp -= 6 - m % 6;
		cout << tmp << endl;
	}
	return 0;
}