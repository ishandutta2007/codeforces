#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <set>
#include <climits>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int c, hr, hb, wr, wb;
	scanf("%d%d%d%d%d", &c, &hr, &hb, &wr, &wb);
	LL ret = 0;
	if (wr < wb) swap(wr, wb), swap(hr, hb);
	int tmp = c / wr;
	if ((LL)hr * wb > (LL)hb * wr)
	{
		for (int i = tmp; i >= 0; --i)
		{
			if (tmp - i >= wb + 5) break;
			ret = max(ret, (LL)i * hr + LL((c - i * wr) / wb) * hb);
		}
	}
	else
	{
		for (int i = 0; i <= tmp; ++i)
		{
			if (i >= wb + 5) break;
			ret = max(ret, (LL)i * hr + LL((c - i * wr) / wb) * hb);
		}
	}
	printf("%I64d\n", ret);
	return 0;
}