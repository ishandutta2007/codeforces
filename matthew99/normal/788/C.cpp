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

const int maxabs = 1010;

typedef bitset<(maxabs << 1) + 5> bset;

int n, K;

bset step, now;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, K)
	{
		int x;
		scanf("%d", &x);
		step[x + maxabs - n] = 1; 
	}
	now[maxabs] = 1;
	int num = 0;
	REP(I, 0, maxabs << 1)
	{
		++num;
		bset nxt;
		REP(i, 0, maxabs << 1)
		{
			if (now[i]) 
			{
				if (i < maxabs) nxt |= step >> (maxabs - i);
				else nxt |= step << (i - maxabs);
			}
		}
		now = nxt;
		if (now[maxabs] == 1)
		{
			printf("%d\n", num);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}