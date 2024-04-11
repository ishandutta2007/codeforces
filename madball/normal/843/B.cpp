#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <cstring>
#include <random>
using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef LOCAL
const int QS = 4;
#else
const int QS = 999;
#endif

pair<int, int> query(int i)
{
	cout << '?' << ' ' << i + 1 << endl;
	int value, nxt;
	cin >> value >> nxt;
	return make_pair(value, nxt - 1);
}

void solve()
{
	mt19937 random(time(NULL));
	int n, start, x;
	cin >> n >> start >> x;
	--start;
	int mx = start;
	pair<int, int> mq = query(start);
	for (int i = 0; i < QS; ++i)
	{
		int cur = random() % n;
		pair<int, int> q = query(cur);
		if (q.first <= x && q.first > mq.first)
		{
			mx = cur;
			mq = q;
		}
	}
	for (int i = 0; i <= QS; ++i)
	{
		if (mq.first >= x)
		{
			cout << '!' << ' ' << mq.first << endl;
			break;
		}
		int cur = mq.second;
		if (cur == -2)
		{
			cout << '!' << ' ' << -1 << endl;
			break;
		}
		if (i == QS)
			throw;
		pair<int, int> q = query(cur);
		mx = cur;
		mq = q;
	}
#ifdef LOCAL
	cin >> n;
#endif
}

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	printf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}