#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int lim = 10000000;

int n, m;
int bx[Maxn], by[Maxn];
int rx[Maxn], ry[Maxn];
map <int, vector <ii> > V, H;
map <int, vector <ii> > toV, toH;

bool Enough(int t)
{
	toV.clear(); toH.clear();
	for (int i = 0; i < n; i++)
		V[bx[i] + by[i]].push_back(ii(by[i] - bx[i] - 2 * t, by[i] - bx[i] + 2 * t));
	for (int i = 0; i < m; i++)
		H[ry[i] - rx[i]].push_back(ii(rx[i] + ry[i] - 2 * t, rx[i] + ry[i] + 2 * t));
	int col = 0;
	for (map <int, vector <ii> >::iterator it = V.begin(); it != V.end(); it++) {
		sort(it->second.begin(), it->second.end());
		for (int i = 0, j; i < it->second.size(); i = j) {
			j = i;
			while (j < it->second.size() && it->second[i].second >= it->second[j].first) {
				it->second[i].second = it->second[j].second; j++;
			}
			vector <int> tmp;
			for (int r = 0; r < m; r++) {
				int y = ry[r] - rx[r];
				int x1 = rx[r] + ry[r] - 2 * t, x2 = rx[r] + ry[r] + 2 * t;
				if (it->second[i].first <= y && y <= it->second[i].second && x1 <= it->first && it->first <= x2)
					tmp.push_back(y);
			}
			sort(tmp.begin(), tmp.end()); tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
			for (int l = 0; l < tmp.size(); l++)
				toV[it->first].push_back(ii(tmp[l], col));
			col++;
		}
	}
	V.clear();
	for (map <int, vector <ii> >::iterator it = H.begin(); it != H.end(); it++) {
		sort(it->second.begin(), it->second.end());
		for (int i = 0, j; i < it->second.size(); i = j) {
			j = i;
			while (j < it->second.size() && it->second[i].second >= it->second[j].first) {
				it->second[i].second = it->second[j].second; j++;
			}
			vector <int> tmp;
			for (int b = 0; b < n; b++) {
				int x = bx[b] + by[b];
				int y1 = by[b] - bx[b] - 2 * t, y2 = by[b] - bx[b] + 2 * t;
				if (it->second[i].first <= x && x <= it->second[i].second && y1 <= it->first && it->first <= y2)
					tmp.push_back(x);
			}
			sort(tmp.begin(), tmp.end()); tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
			for (int l = 0; l < tmp.size(); l++)
				toH[it->first].push_back(ii(tmp[l], col));
			col++;
		}
	}
	H.clear();
	for (map <int, vector <ii> >::iterator it = toV.begin(); it != toV.end(); it++)
		for (int i = 0; i + 1 < it->second.size(); i++) if (it->second[i].second == it->second[i + 1].second) {
			int x1 = it->first, y1 = it->second[i].first;
			int y2 = it->second[i + 1].first;
			int ind = lower_bound(toH[y1].begin(), toH[y1].end(), ii(x1, 0)) - toH[y1].begin();
			int ind2 = lower_bound(toH[y2].begin(), toH[y2].end(), ii(x1, 0)) - toH[y2].begin();
			if (ind + 1 == toH[y1].size() || toH[y1][ind].second != toH[y1][ind + 1].second ||
				ind2 + 1 == toH[y2].size() || toH[y2][ind2].second != toH[y2][ind2 + 1].second) continue;
			int x2 = max(toH[y1][ind + 1].first, toH[y2][ind2 + 1].first);
			int ind3 = lower_bound(toH[y1].begin(), toH[y1].end(), ii(x2, 0)) - toH[y1].begin();
			int ind4 = lower_bound(toH[y2].begin(), toH[y2].end(), ii(x2, 0)) - toH[y2].begin();
			if (ind3 == toH[y1].size() || toH[y1][ind3].first != x2 || toH[y1][ind].second != toH[y1][ind3].second ||
				ind4 == toH[y2].size() || toH[y2][ind4].first != x2 || toH[y2][ind2].second != toH[y2][ind4].second) continue;
			return true;
		}
	for (map <int, vector <ii> >::iterator it = toH.begin(); it != toH.end(); it++)
		for (int i = 0; i + 1 < it->second.size(); i++) if (it->second[i].second == it->second[i + 1].second) {
			int y1 = it->first, x1 = it->second[i].first;
			int x2 = it->second[i + 1].first;
			int ind = lower_bound(toV[x1].begin(), toV[x1].end(), ii(y1, 0)) - toV[x1].begin();
			int ind2 = lower_bound(toV[x2].begin(), toV[x2].end(), ii(y1, 0)) - toV[x2].begin();
			if (ind + 1 == toV[x1].size() || toV[x1][ind].second != toV[x1][ind + 1].second ||
				ind2 + 1 == toV[x2].size() || toV[x2][ind2].second != toV[x2][ind2 + 1].second) continue;
			int y2 = max(toV[x1][ind + 1].first, toV[x2][ind2 + 1].first);
			int ind3 = lower_bound(toV[x1].begin(), toV[x1].end(), ii(y2, 0)) - toV[x1].begin();
			int ind4 = lower_bound(toV[x2].begin(), toV[x2].end(), ii(y2, 0)) - toV[x2].begin();
			if (ind3 == toV[x1].size() || toV[x1][ind3].first != y2 || toV[x1][ind].second != toV[x1][ind3].second || 
				ind4 == toV[x2].size() || toV[x2][ind4].first != y2 || toV[x2][ind2].second != toV[x2][ind4].second) continue;
			return true;
		}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &bx[i], &by[i]);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &rx[i], &ry[i]);
	int l = 0, r = lim;
	int res = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Enough(mid)) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	if (res == -1) printf("Poor Sereja!\n");
	else printf("%d\n", res);
	return 0;
}