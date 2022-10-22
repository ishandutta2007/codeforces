#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e+9 + 7;
const ld eps = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif

int ans[61] = {0,
1,
1,
2,
2,
2,
3,
3,
3,
3,
4,
4,
4,
4,
4,
5,
5,
5,
5,
5,
5,
6,
6,
6,
6,
6,
6,
6,
7,
7,
7,
7,
7,
7,
7,
7,
8,
8,
8,
8,
8,
8,
8,
8,
8,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
10,
10,
10,
10,
10,
10};

/*map<vector<int>, int> func[61];

int getfunc(int sum, vector<int> &moves)
{
	if (sum == 0)
		return 0;
	if (func[sum].count(moves) != 0)
		return func[sum][moves];
	vector<int> moved;
	for (int i = 1; i <= sum; ++i)
	{
		auto it = lower_bound(moves.begin(), moves.end(), i);
		if (it == moves.end())
		{
			moves.insert(it, i);
			moved.push_back(getfunc(sum - i, moves));
			moves.erase(lower_bound(moves.begin(), moves.end(), i));
		}
	}
	sort(moved.begin(), moved.end());
	moved.resize(unique(moved.begin(), moved.end()) - moved.begin());
	for (int i = 0; i <= moved.size(); ++i)
		if (i == moved.size() || moved[i] != i)
		{
			func[sum][moves] = i;
			return i;
		}
}*/

void solve()
{
	int n;
	int res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a = i + 1;
scanf("%d", &a);
res ^= ans[a];
//		vector<int> pingas;
//		res ^= getfunc(a, pingas);
	}
	printf(res ? "NO" : "YES");
/*int s = 0;
	for (int i = 0; i < 61; ++i)
		s += func[i].size();
	printf("%d", s);*/
/*for (int i = 1; i <= 60; ++i)
{
vector<int> pingas;
printf("%d\n", getfunc(i, pingas));*/
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}