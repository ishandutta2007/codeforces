#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 100;
const int M = 100;
int dh[N];
int tmp[N];
ll cost[N];

int h_x[M];
int h_hp[M];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		cin >> h_x[i] >> h_hp[i];
		--h_x[i];
	}

	for (int i = 0; i < n; ++i) cin >> dh[i];

	bool fail = false;
	for (int t = 0; t < n; ++t) {
		for (int i = 0; i < n; ++i) tmp[i] = dh[i];

		vector<int> act(m);
		for (int i = 0; i < m; ++i) act[i] = i;
		vector<int> ans;

		fail = false;
		while(! act.empty()) {
			ll res = 0;
			for (int j = t; j < n; ++j) {
				res = max(res, (ll)0);
				res -= tmp[j];
				cost[j] = res;
			}

			res = 0;
			for (int j = t; j >= 0; --j) {
				res = max(res, (ll)0);
				res -= tmp[j];
				cost[j] = res;
			}

			bool found = false;
			for (int j = 0; j < act.size(); ++j) {
				int i = act[j];
				if (cost[h_x[i]] <= h_hp[i]) {
					act[j] = act.back();
					act.pop_back();

					ans.push_back(i);

					for (int c = min(h_x[i], t); c <= max(h_x[i], t); ++c) tmp[c] = 0;
					
					found = true;
					break;
				}
			}
			if (! found) {
				fail = true;
				break;
			}
		}
		if (fail) continue;

		cout << t+1 << '\n';
		for (auto it : ans) cout << it+1 << ' '; cout << '\n';
		break;
	}

	if (fail) {
		cout << "-1\n";
	}
}