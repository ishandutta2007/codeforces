#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4 * 1e6;
bool wall[N][2];
int next_wall[N][2];
pair<int, pair<int, int>> best[N][2];

int bin(int v, vector<int>& vals) {
	int low = 0;
	int high = vals.size() - 1;
	while(low < high) {
		int mid = (low + high) >> 1;
		if (v > vals[mid]) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	// cout << "bin " << v << ' ' << low << '\n';
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, xc, yc, rel;
	cin >> n >> xc >> yc >> rel;
	vector<int> xs (xc);
	vector<int> ys (yc);
	vector<int> tmp1 = {0};
	vector<int> tmp2;
	for (int i = 0; i < xc; ++i) {
		cin >> xs[i];
		if (i > 0) {
			if (xs[i-1] + 2 <= xs[i]) {
				tmp1.push_back(xs[i-1] + 1);
			}
			if (xs[i-1] + 3 <= xs[i]) {
				tmp1.push_back(xs[i]-1);
			}
		}
	}
	for (int i = 0; i < yc; ++i) {
		cin >> ys[i];
		if (i > 0) {
			if (ys[i-1] + 2 <= ys[i]) {
				tmp2.push_back(ys[i-1] + 1);
			}
			if (ys[i-1] + 3 <= ys[i]) {
				tmp2.push_back(ys[i]-1);
			}
		}
	}
	vector<int> tmp3, tmp4, comp;
	merge(xs.begin(), xs.end(), tmp1.begin(), tmp1.end(), back_inserter(tmp3));
	merge(ys.begin(), ys.end(), tmp2.begin(), tmp2.end(), back_inserter(tmp4));
	merge(tmp3.begin(), tmp3.end(), tmp4.begin(), tmp4.end(), back_inserter(comp));
	// only n log n part
	// sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	
	/*
	cout << comp.size() << '\n';
	for (int i = 0; i < comp.size(); ++i) cout << comp[i] << ' '; cout << '\n';
	*/
	
	int curin = 0;
	for (int i = 0; i < xc; ++i) {
		while(comp[curin] < xs[i]) ++curin;
		xs[i] = curin;
	}
	curin = 0;
	for (int i = 0; i < yc; ++i) {
		while(comp[curin] < ys[i]) ++curin;
		ys[i] = curin;
	}
	// end of only n log n part

	/*
	cout << xc << ' ' << yc << '\n';
	for (int i = 0; i < xc; ++i) cout << xs[i] << ' '; cout << '\n';
	for (int i = 0; i < yc; ++i) cout << ys[i] << ' '; cout << '\n';
	*/

	for (int i = 0; i < xc; ++i) wall[xs[i]][0] = true;
	for (int i = 0; i < yc; ++i) wall[ys[i]][1] = true;
	
	// update n
	n = comp.size();

	for (int j = 0; j < 2; ++j) {
		next_wall[n-1][j] = n;
		for (int i = n-2; i >= 0; --i) {
			next_wall[i][j] = (wall[i+1][j] ? i+1 : next_wall[i+1][j]);
		}
		// for (int i = 0; i < n; ++i) cout << next_wall[i][j] << ' '; cout << '\n';
	}
	for (int i = 0; i < n; ++i) {
		best[i][0] = {-1, {-1, -1}};
		best[i][1] = {-1, {-1, -1}};
	}

	// place tank
	if (! wall[0][0]) best[0][0] = {0, {0,0}};

	int winx = -1;
	int winy = -1;
	
	vector<pair<int, pair<int, int>>> currs = {{-1, {-1,-1}},{-1,{-1,-1}}};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (currs[j].first != -1) {
				currs[j] = {currs[j].first + (comp[i] - comp[i-1]), {currs[j].second.first, currs[j].second.second}};
			}
			if (wall[i][j]) currs[j] = {-1, {-1, -1}};
		}
		for (int j = 0; j < 2; ++j) {
			best[i][j] = max(best[i][j], currs[j]);
		}

		// swapping lanes
		for (int j = 0; j < 2; ++j) {
			if ((! wall[i][j]) && (best[i][j^1].first != -1) && (best[i][j].first < best[i][j^1].first)) {
				best[i][j] = max(best[i][j], {min(rel, best[i][j^1].first), {i,j^1}});
			}
		}

		for (int j = 0; j < 2; ++j) {
			currs[j] = max(currs[j], {best[i][j].first, {i, j}});
		}

		// cout << best[i][1].first << ' ';
		int cx = comp[i];
		//cout << "(";
		for (int j = 0; j < 2; ++j) {
			auto p = best[i][j];
			//cout << p.first << ' ' << p.second.first << ' ' << p.second.second << ",";
			if (p.first == -1) continue;
			int nwi = next_wall[i][j];
			if (nwi == n) {
				winx = i;
				winy = j;
				break;
			} else {
				int wx = comp[nwi];
				int t = (wx - cx + p.first);
				// cout << wx << ' ' << cx << ' ' << p.first << ' ' << rel << '\n';
				if (t > rel) {
					best[nwi][j] = max(best[nwi][j], {t-rel, {i, j}});
				}
			}
		}
		//cout << ") ";
		if (winx != -1) break;
	}
	// cout << "\n";
	
	if (winx == -1) {
		cout << "No\n";
	} else {
		vector<pair<int, int>> shots;
		vector<int> moves;
		int x = winx;
		int y = winy;
		while(x != 0 || y != 0) {
			// cout << x << ' ' << y << '\n';
			auto p = best[x][y];
			auto pp = best[p.second.first][p.second.second];
			if ((p.second.second == y) && (wall[x][y])) {
				// x = spot where (prev.first + x - comp[prev]) = rel
				// x = comp[prev]+rel-prev.first
				shots.push_back({ comp[p.second.first]+rel - pp.first, y+1});
			} else if (p.second.second != y) {
				// cout << "Swap\n";
				moves.push_back(comp[x]);
			}
			x = p.second.first;
			y = p.second.second;
		}

		cout << "Yes\n";
		cout << moves.size() << '\n';
		for (int i = (int)moves.size() - 1; i >= 0; --i) cout << moves[i] << ' '; cout << '\n';
		cout << shots.size() << '\n';
		for (int i = (int)shots.size() - 1; i >= 0; --i) cout << shots[i].first << ' ' << shots[i].second << '\n';
	}
	
}