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

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int x, y;
int a[Maxn], b[Maxn];
int c[Maxn], d[Maxn];
vector <ii> seq, ch;

ll Cross(ll ax, ll ay, ll bx, ll by) { return ax * by - ay * bx; }

bool Less(const ii &a, const ii &b)
{
	return Cross(a.first, a.second, b.first, b.second) > 0;
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &x, &y);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]);
	int mxc = 0, mxd = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &c[i], &d[i]);
		seq.push_back(ii(c[i], d[i]));
		mxc = max(mxc, c[i]); mxd = max(mxd, d[i]);
	}
	seq.push_back(ii(mxc, 0)); seq.push_back(ii(0, mxd));
	sort(seq.begin(), seq.end(), Less);
	ch.push_back(ii(0, 0));
	for (int i = 0; i < seq.size(); i++) {
		ii cur = seq[i];
		while (ch.size() >= 2) {
			int ax = cur.first - ch[ch.size() - 2].first, ay = cur.second - ch[ch.size() - 2].second;
			int bx = ch.back().first - ch[ch.size() - 2].first, by = ch.back().second - ch[ch.size() - 2].second;
			if (Cross(ax, ay, bx, by) >= 0) ch.pop_back();
			else break;
		}
		ch.push_back(cur);
	}
	seq.clear();
	for (int i = 0; i < n; i++)
		seq.push_back(ii(a[i], b[i]));
	sort(seq.begin(), seq.end(), Less);
	int pnt = 0;
	for (int i = 2; i < ch.size(); i++)
		while (pnt < seq.size() && Less(seq[pnt], ch[i])) {
			int ax = seq[pnt].first - ch[i - 1].first, ay = seq[pnt].second - ch[i - 1].second;
			int bx = ch[i].first - ch[i - 1].first, by = ch[i].second - ch[i - 1].second;
			if (Cross(ax, ay, bx, by) >= 0) { printf("Max\n"); return 0; }
			pnt++;
		}
	printf("Min\n");
	return 0;
}