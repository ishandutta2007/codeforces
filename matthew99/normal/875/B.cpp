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

const int max0 = 19;
const int maxn = 300100;

int n;
int fen[maxn + 5];

int Max;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	printf("1");
	REP(i, 1, n + 1)
	{
		int x;
		scanf("%d", &x);
		for (int j = x; j <= n; j += j & -j) ++fen[j];
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			int sum = 0;
			for (int j = mid; j > 0; j -= j & -j)
				sum += fen[j];
			if (n - mid == i - sum) r = mid;
			else l = mid + 1;
		}
		printf(" %d", i - (n - l) + 1);
	}
	return 0;
}