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
typedef pair <ii, int> iii;

const int Maxn = 105;

int n, k, m, a;
int cnt[Maxn], lst[Maxn];
vector <iii> V;

bool Less(const iii &a, const iii &b)
{
	if (a.first.first != b.first.first) return a.first.first > b.first.first;
	return a.first.second < b.first.second;
}

bool winSure(int ind)
{
	if (cnt[ind] == 0) return false;
	int p = 0;
	while (V[p].second != ind) p++;
	int pos = p + 1;
	int lft = m - a;
	for (int i = p + 1; i < V.size(); i++) {
		int nd = cnt[ind] - V[i].first.first + 1;
		if (nd <= lft) { lft -= nd; pos++; }
		else break;
	}
	return pos <= k;
}

bool winCan(int ind)
{
	int p = 0;
	while (V[p].second != ind) p++;
	int pos = p + 1;
	int lft = m - a;
	int cur = cnt[ind];
	if (cur == 0)
		if (1 <= lft) { lft--; cur++; }
		else return false;
	for (int i = p - 1; i >= 0; i--)
		if (V[i].first.first == 0) pos--;
		else {
			int nd = V[i].first.first - cur + 1;
			if (nd <= lft) { lft -= nd; cur += nd; pos--; }
			else break;
		}
	return pos <= k;
}

int Solve(int ind)
{
	if (winSure(ind)) return 1;
	return winCan(ind)? 2: 3;
}

int main()
{
	scanf("%d %d %d %d", &n, &k, &m, &a);
	for (int i = 1; i <= a; i++) {
		int g; scanf("%d", &g);
		cnt[g]++; lst[g] = i;
	}
	for (int i = 1; i <= n; i++)
		V.push_back(iii(ii(cnt[i], lst[i]), i));
	sort(V.begin(), V.end(), Less);
	for (int i = 1; i <= n; i++)
		printf("%d%c", Solve(i), i + 1 <= n? ' ': '\n');
	return 0;
}