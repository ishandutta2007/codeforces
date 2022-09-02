#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> vert(n);
	vector<int> hori;
	for (int i = 0; i < n; ++i) cin >> vert[i];
	for (int i = 0; i < m; ++i) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if (x1 == 1) hori.push_back(x2);
	}

	sort(vert.begin(), vert.end());
	sort(hori.begin(), hori.end());
	
	int res = INF;
	int cur = 0;
	while(true) {
		if (hori.empty()) {
			res = min(res, cur);
			break;
		} else {
			int lx = hori.back();
			if (lx < INF) {
				int low = 0;
				int high = n;
				while(low != high) {
					int mid = (low + high) >> 1;
					if (vert[mid] > lx) high = mid;
					else low = mid + 1;
				}
				
				int offer = cur + low;
				res = min(res, offer);
			}
		}

		hori.pop_back();
		++cur;
	}
	cout << res << '\n';
}