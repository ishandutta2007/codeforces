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
typedef long long ll;

const int Maxn = 100005;

int n, m; 
int bounty, increase, damage;
int mx[Maxn], st[Maxn], regen[Maxn];
vector <ii> en[Maxn];
vector <ii> E;
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &bounty, &increase, &damage);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &mx[i], &st[i], &regen[i]);
	for (int i = 1; i <= m; i++) {
		int tim, enem, h; scanf("%d %d %d", &tim, &enem, &h);
		en[enem].push_back(ii(tim, h));
	}
	for (int i = 1; i <= n; i++) {
		sort(en[i].begin(), en[i].end());
		int tim = 0, cur = st[i];
		for (int j = 0; j < en[i].size(); j++) {
			if (cur > damage) { E.push_back(ii(tim, -1)); E.push_back(ii(en[i][j].first, 1)); }
			else if (regen[i] > 0) {
				int timlose = tim + (damage - cur) / regen[i] + 1;
				if (timlose < en[i][j].first && mx[i] > damage) { E.push_back(ii(timlose, -1)); E.push_back(ii(en[i][j].first, 1)); }
			}
			tim = en[i][j].first; cur = en[i][j].second;
		}
		if (cur > damage) E.push_back(ii(tim, -1));
		else if (regen[i] > 0 && mx[i] > damage) {
			int timlose = tim + (damage - cur) / regen[i] + 1;
			E.push_back(ii(timlose, -1));
		}
	}
	sort(E.begin(), E.end());
	int alive = n;
	for (int i = 0; i < E.size(); i++) {
		if (E[i].second == -1) {
			ll tst = E[i].first - 1;
			if (tst >= 0) res = max(res, ll(alive) * (bounty + ll(tst) * increase));
		}
		alive += E[i].second;
	}
	if (alive > 0) res = max(res, ll(alive) * bounty);
	if (alive > 0 && increase > 0) printf("-1\n");
	else printf("%I64d\n", res);
	return 0;
}