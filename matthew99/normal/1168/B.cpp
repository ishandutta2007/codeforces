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

const int maxn = 300100;

int n;
char s[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	LL ans = 0;
	int lst = n;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i + 2; j < lst; j += 2)
		{
			if (s[i] == s[j] && s[i] == s[(i + j) >> 1])
			{
				lst = j;
				break;
			}
		}
		ans += n - lst;
	}
	cout << ans << endl;
	return 0;
}