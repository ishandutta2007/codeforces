#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;
	
		vector<array<int, 5>> ranks(n);
		for (int i = 0; i < n; ++i) {
			cin >> ranks[i][0] >> ranks[i][1] >> ranks[i][2] >> ranks[i][3] >> ranks[i][4];
		}

		vector<bool> works(n, 1);
		for (int mask = 0; mask < (1 << 5); ++mask) {
			vector<int> inds;
			for (int j = 0; j < 5; ++j) {
				if (mask & (1 << j)) inds.push_back(j);
			}
			if (inds.size() != 3) continue;

			vector<pair<int, int>> ord(n);
			for (int i = 0; i < n; ++i) {
				ord[i] = {ranks[i][inds[0]], i};
			}
			sort(ord.begin(), ord.end());

			set<pair<int, int>> prs;
			for (auto ipr : ord) {
				int i = ipr.second;
				pair<int, int> vals = {-ranks[i][inds[1]], -ranks[i][inds[2]]};
				auto it = prs.lower_bound(vals);

				/*
				cerr << mask << ' ' << i << ' ' << vals.first << ' ' << vals.second << ": ";
				for (auto pr : prs) cerr << "(" << pr.first << ' ' << pr.second << ") ";
				if (it == prs.end()) {
					cerr << "best in " << inds[1] << '\n';
				} else {
					cerr << (*it).first << ' ' << (*it).second << '\n';
				}
				*/

				if (it != prs.end() && (*it).first > vals.first && (*it).second > vals.second) {
					works[i] = 0;
				} else {
					// cerr << "Works!\n";
					while(it != prs.begin()) {
						--it;
						if ((*it).first <= vals.first && (*it).second <= vals.second) {
							prs.erase(it);
							it = prs.lower_bound(vals);
						} else {
							break;
						}
					}
					prs.insert(vals);
				}
			}
		}

		bool found = 0;
		for (int i = 0; i < n; ++i) {
			if (works[i]) {
				cout << i + 1;
				found = 1;
			}
		}
		if (! found) cout << -1;
		cout << '\n';
	}

}