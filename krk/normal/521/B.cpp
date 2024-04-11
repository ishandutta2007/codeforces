#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int mod = 1000000009;

int m;
map <ii, int> val;
map <ii, int> rel;
map <ii, int> sav;
set <iii> Q;
int res;

void updateChild(ii p, int add)
{
	map <ii, int>::iterator it = sav.find(p);
	if (it == sav.end()) return;
	if (it->second == 0) Q.erase(iii(val[p], p));
	it->second += add;
	if (it->second == 0) Q.insert(iii(val[p], p));
}

void updateParent(ii p, int add = -1)
{
	map <ii, int>::iterator it = rel.find(p);
	if (it == rel.end()) return;
	it->second += add;
	if (it->second == 1) {
		updateChild(ii(p.first - 1, p.second - 1), 1);
		updateChild(ii(p.first, p.second - 1), 1);
		updateChild(ii(p.first + 1, p.second - 1), 1);
	}
}

void deleteHigher(ii p)
{
	map <ii, int>::iterator it = rel.find(p);
	if (it == rel.end()) return;
	if (it->second == 1) {
		updateChild(ii(p.first - 1, p.second - 1), -1);
		updateChild(ii(p.first, p.second - 1), -1);
		updateChild(ii(p.first + 1, p.second - 1), -1);
	}
	rel.erase(it);
}

void deleteLower(ii p)
{
	map <ii, int>::iterator it = sav.find(p);
	if (it == sav.end()) return;
	updateParent(ii(p.first - 1, p.second + 1));
	updateParent(ii(p.first, p.second + 1));
	updateParent(ii(p.first + 1, p.second + 1));
	sav.erase(it);
}

bool Exist(ii p) { return val.find(p) != val.end(); }

void initChild(ii p)
{
	sav[p] = 0; Q.insert(iii(val[p], p));
}

void initParent(ii p)
{
	int val = Exist(ii(p.first - 1, p.second - 1)) + Exist(ii(p.first, p.second - 1)) + Exist(ii(p.first + 1, p.second - 1));
	rel[p] = val;
	if (val == 1) updateParent(p, 0);
}

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		val[ii(x, y)] = i;
		initChild(ii(x, y));
	}
	for (map <ii, int>::iterator it = val.begin(); it != val.end(); it++)
		initParent(it->first);
	bool big = true;
	for (int i = 0; i < m; i++) {
		res = ll(res) * m % mod;
		iii p;
		if (big) p = *Q.rbegin();
		else p = *Q.begin();
		Q.erase(p);
		res = (res + p.first) % mod;
		deleteLower(p.second); deleteHigher(p.second);
		big = !big;
	}
	printf("%d\n", res);
	return 0;
}