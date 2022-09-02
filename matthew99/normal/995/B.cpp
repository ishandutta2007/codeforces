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

const int maxn = 210;

int n;
int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n * 2) scanf("%d", a + i);
	int ans = 0;
	for (int i = 0; i < n * 2; i += 2)
	{
		REP(j, i + 1, n * 2)
			if (a[j] == a[i])
			{
				for (int k = j - 1; k >= i + 1; --k)
				{
					++ans;
					swap(a[k], a[k + 1]);
				}
				break;
			}
	}
	printf("%d\n", ans);
	return 0;
}