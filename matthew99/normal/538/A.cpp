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

const int maxn = 1000;

string s;

string s0 = "CODEFORCES";

bool dp[maxn + 5][maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	int n = SZ(s);
	int tmp = SZ(s0);
	if (n < tmp) EXIT("NO\n");
	REP(i, 0, min(n, tmp) + 1)
	{
		if (i > n - (tmp - i)) break;
		if (s.substr(0, i) + s.substr(n - (tmp - i)) == s0) EXIT("YES\n");
	}
	printf("NO\n");
	return 0;
}