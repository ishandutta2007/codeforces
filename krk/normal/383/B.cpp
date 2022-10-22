#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int n, m;
map <int, vector <int> > x;
vector <int> un;
vector <vector <ii> > I;

int getFir(const vector <ii> &V, int from)
{
	int l = 0, r = int(V.size()) - 1;
	int res = -1;
	while (l <= r) {
		int m = l + r >> 1;
		if (from <= V[m].second) { res = m; r = m - 1; }
		else l = m + 1;
	}
	if (res == -1) return n + 1;
	return max(from, V[res].first);
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int r, c; scanf("%d %d", &r, &c);
		x[r].push_back(c);
		un.push_back(r); 
		if (r < n) un.push_back(r + 1);
	}
	for (map <int, vector <int> >::iterator it = x.begin(); it != x.end(); it++)
		sort(it->second.begin(), it->second.end());
	un.push_back(1); un.push_back(n);
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	I.resize(un.size());
	if (x.find(1) == x.end()) I[0].push_back(ii(1, n));
	else I[0].push_back(ii(1, x[1][0] - 1));
	for (int i = 1; i < un.size(); i++) {
		int r = un[i];
		map <int, vector <int> >::iterator it = x.find(r);
		if (it == x.end())
			{ if (!I[i - 1].empty()) I[i].push_back(ii(I[i - 1][0].first, n)); }
		else {
			int st = 1;
			for (int j = 0; j < it->second.size(); j++) {
				int p = it->second[j];
				if (st < p) {
					int fir = getFir(I[i - 1], st);
					if (fir < p) I[i].push_back(ii(fir, p - 1));
				}
				st = p + 1;
			}
			if (st < n + 1) {
				int fir = getFir(I[i - 1], st);
				if (fir < n + 1) I[i].push_back(ii(fir, n));
			}
		}
	}
	if (!I.back().empty() && I.back().back().second == n) printf("%d\n", 2 * n - 2);
	else printf("-1\n");
	return 0;
}