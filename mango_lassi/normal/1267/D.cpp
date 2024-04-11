#include <iostream>
#include <vector>
using namespace std;
const int M = 264;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Server i needs need[i] and creates need[i] or need[i] & test[i]
	// Initially deploy to all servers that need all features, and put testing on
	// in all of these servers. Now we can produce some set of masks. Connect to all
	// servers that only need a single mask, and put testing on on them. Now all remaining
	// servers need at least two masks, and for at least one we have those masks. Assume we
	// have 100 and 010. Connect both to one of the 110 needing servers, and DO NOT TEST
	// on that machine, as that could only create 100 or 010, which we already have.
	// Then connect that machine to all ofther 110 needing servers. 

	int n;
	cin >> n;
	vector<int> need(n), test(n);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		need[i] = a + 2*b + 4*c;
	}
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		test[i] = a + 2*b + 4*c;
	}
	
	vector<pair<int, int>> res;
	vector<int> can(8, -1);
	vector<bool> done(n, 0);
	vector<bool> ct(n, 0);
	can[7] = 0;
	done[0] = 1;

	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < n; ++i) {
			if (done[i]) continue;
			done[i] = true;
			if (need[i] == 0) continue;

			if (can[need[i]] != -1) {
				res.push_back({can[need[i]], i});
				can[need[i] & test[i]] = i;
				ct[i] = 1;
			} else if (need[i] == 3 && can[1] != -1 && can[2] != -1) {
				res.push_back({can[1], i});
				res.push_back({can[2], i});
				can[need[i]] = i;
			} else if (need[i] == 5 && can[1] != -1 && can[4] != -1) {
				res.push_back({can[1], i});
				res.push_back({can[4], i});
				can[need[i]] = i;
			} else if (need[i] == 6 && can[2] != -1 && can[4] != -1) {
				res.push_back({can[2], i});
				res.push_back({can[4], i});
				can[need[i]] = i;
			} else {
				done[i] = false;
			}
		}
	}

	bool fail = false;
	for (int i = 0; i < n; ++i) {
		if (! done[i]) fail = true;
	}

	if (fail) cout << "Impossible\n";
	else {
		cout << "Possible\n";
		for (int i = 0; i < n; ++i) cout << ct[i] << ' '; cout << '\n';

		cout << res.size() << '\n';
		for (auto pr : res) cout << pr.first + 1 << ' ' << pr.second + 1 << '\n';
	}
}