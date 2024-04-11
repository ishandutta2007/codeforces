#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 10000;

int n, a, b;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &a, &b);
	if (n > a * b) printf("-1\n");
	else
	{
		int now[2] = {1, 2};
		REP(i, 0, a) 
		{
			REP(j, 0, b)
			{
				bool tmp = (i ^ j) & 1;
				if (now[tmp] <= n) printf("%d ", now[tmp]), now[tmp] += 2;
				else printf("0 ");
			}
			printf("\n");
		}
	}
	return 0;
}