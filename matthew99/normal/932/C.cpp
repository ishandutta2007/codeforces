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

const int maxn = 1000100;

int n, A, B;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 0; i * A <= n; ++i)
		if (!((n - i * A) % B))
		{
			int u = i, v = (n - i * A) / B;
			int cur = 1;
			REP(j, 0, u)
			{
				int tmp = cur;
				REP(k, 0, A - 1)
					printf("%d ", ++cur);
				++cur;
				printf("%d ", tmp);
			}
			REP(j, 0, v)
			{
				int tmp = cur;
				REP(k, 0, B - 1)
					printf("%d ", ++cur);
				++cur;
				printf("%d ", tmp);
			}
			return 0;
		}
	printf("-1\n");
	return 0;
}