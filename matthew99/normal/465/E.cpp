#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int Mod = 1e9 + 7;
const int maxn = 100000;

pair<int, int> result[10];

int n;

char from[maxn + 5];
string to[maxn + 5];
string s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s >> n;
	REP(i, 0, n)
	{
		cin >> to[i];
		from[i] = to[i][0];
		to[i] = to[i].substr(3);
	}
	REP(i, 0, n) cerr << from[i] << ' ' << to[i] << endl;
	REP(i, 0, 10) result[i] = mp(i, 10);
	for (int i = n - 1; i >= 0; --i)
	{
		pair<int, int> new_result = mp(0, 1);
		for (int j = to[i].size() - 1; j >= 0; --j)
		{
			new_result.x = (new_result.x + (LL)result[to[i][j] - '0'].x * new_result.y) % Mod;
			new_result.y = (LL)new_result.y * result[to[i][j] - '0'].y % Mod;
		}
		result[from[i] - '0'] = new_result;
	}
	pair<int, int> new_result = mp(0, 1);
	for (int j = s.size() - 1; j >= 0; --j)
	{
		new_result.x = (new_result.x + (LL)result[s[j] - '0'].x * new_result.y) % Mod;
		new_result.y = (LL)new_result.y * result[s[j] - '0'].y % Mod;
	}
	printf("%d\n", new_result.x);
	return 0;
}