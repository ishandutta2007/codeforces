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

LL x;
int cnt[1 << 18];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[5];
		scanf("%s", s);
		scanf("%I64d", &x);
		int val = 0;
		REP(i, 0, 18)
		{
			if ((x % 10) & 1) val |= 1 << i;
			x /= 10;
		}
		if (s[0] == '+') ++cnt[val];
		else if (s[0] == '-') --cnt[val];
		else printf("%d\n", cnt[val]);
	}
	return 0;
}