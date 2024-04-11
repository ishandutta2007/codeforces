#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 1000000000;

int n;
char str[Maxn];
int quest[Maxn];
int m;
int alet, blet;
int cost[Maxn];
ii dp[Maxn];

int Get(int ind) { return ind < 0? 0: quest[ind]; }

void Compute(int forba, int forbb, int from)
{
	int cur = 0;
	for (int i = from; i >= 0; i -= 2) {
		if (str[i] == 'b') forba = i;
		if (i + 1 >= n || str[i + 1] == 'a') forbb = i + 1;
		int ena = i + 2 * (alet - 1);
		int enb = i + 1 + 2 * (blet - 1);
		if (forba > ena && forbb > enb) cost[i] = Get(ena) - Get(i - 2) + Get(enb) - Get(i - 1);
		else cost[i] = Inf;
	}
}

ii Better(const ii &a, const ii &b)
{
	if (a.first != b.first) return a.first > b.first? a: b;
	return a.second < b.second? a: b;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		quest[i] = str[i] == '?';
		if (i >= 2) quest[i] += quest[i - 2];
	}
	alet = (m + 1) / 2;
	blet = m / 2;
	Compute(n + 1, n, n - 1);
	Compute(n, n + 1, n - 2);
	fill(dp, dp + Maxn, ii(-Inf, Inf));
	dp[0] = ii(0, 0);
	for (int i = 0; i < n; i++) {
		dp[i + 1] = Better(dp[i + 1], dp[i]);
		if (cost[i] < Inf) dp[i + m] = Better(dp[i + m], ii(dp[i].first + 1, dp[i].second + cost[i]));
	}
	printf("%d\n", dp[n].second);
	return 0;
}