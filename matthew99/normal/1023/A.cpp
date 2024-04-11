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

const int maxn = 200100;

int n, m;
string s, t;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	cin >> s >> t;
	if (s == t) puts("YES");
	else if (m >= n - 1)
	{
		if (~s.find("*"))
		{
			int k = s.find("*");
			if (s.substr(0, k) == t.substr(0, k) && s.substr(k + 1) == t.substr(k + m - n + 1)) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
	else puts("NO");
	return 0;
}