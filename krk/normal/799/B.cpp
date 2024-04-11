#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxd = 3;
const int Maxn = 200005;

set <int> S;
int n;
int p[Maxn], a[Maxn], b[Maxn];
vector <int> has[Maxd];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i]--;
		has[a[i]].push_back(p[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]); b[i]--;
		has[b[i]].push_back(p[i]);
	}
	for (int i = 0; i < Maxd; i++)
		sort(has[i].rbegin(), has[i].rend());
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int c; scanf("%d", &c); c--;
		while (!has[c].empty() && S.find(has[c].back()) != S.end()) has[c].pop_back();
		if (has[c].empty()) printf("-1");
		else { printf("%d", has[c].back()); S.insert(has[c].back()); }
		printf("%c", i + 1 < m? ' ': '\n');
	}
	return 0;
}