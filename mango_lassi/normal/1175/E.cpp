#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

// Finds last with value <= val
template<class T>
int bins(const vector<T>& vec, T val) {
	int low = -1;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (vec[mid] <= val) low = mid;
		else high = mid - 1;
	}
	return low;
}

const int H = 18;
const int N = 1<<H;
int nxt[N][H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Optimal to pick interval with a <= x, with maximum b
	// Find for every interval the best next interval. Do jump array.
	// Remove useless intervals for easy handling

	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		vec[i] = {a, -b};
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; ++i) vec[i].second *= -1;
	
	// Remove useless intervals
	int r = 0;
	for (int i = 0; i+r < n; ++i) {
		swap(vec[i], vec[i+r]);
		if (i > 0 && vec[i-1].second >= vec[i].second) {
			++r;
			--i;
		}
	}
	n -= r;
	vec.resize(n);

	// for (auto pr : vec) cout << pr.first << ' ' << pr.second << "; "; cout << endl;

	// Find next intervals
	for (int i = 0; i < n; ++i) {
		nxt[i][0] = bins(vec, {vec[i].second, INF});
	}
	for (int h = 1; h < H; ++h) {
		for (int i = 0; i < n; ++i) {
			nxt[i][h] = nxt[nxt[i][h-1]][h-1];
		}
	}

	for (int qi = 0; qi < q; ++qi) {
		int x, y;
		cin >> x >> y;
		int i = bins(vec, {x, INF});
		int res = -1;
		if (i != -1) {
			res = 1;
			for (int h = H-1; h >= 0; --h) {
				int j = nxt[i][h];
				if (vec[j].second < y) {
					res += (1<<h);
					i = j;
				}
			}
			if (vec[i].second < y) {
				++res;
				i = nxt[i][0];
			}
			if (vec[i].second < y) res = -1;
		}
		cout << res << '\n';
	}
}