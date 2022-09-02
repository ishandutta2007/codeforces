#include <iostream>
#include <queue>
using namespace std;

const int Q = 2 * (int)1e5;
const int N = 2 * (int)1e5;
int min_ind[Q];
int max_ind[Q];
int vals[N];
int rec[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		min_ind[i] = n;
		max_ind[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		--vals[i];
		if (vals[i] != -1) {
			min_ind[vals[i]] = min(min_ind[vals[i]], i);
			max_ind[vals[i]] = max(max_ind[vals[i]], i);
		}
	}

	for (int i = 0; i < n; ++i) {
		rec[i] = -1;
	}
	priority_queue<int> actives;
	for (int i = 0; i < n; ++i) {
		if (vals[i] != -1) {
			if (min_ind[vals[i]] == i) {
				actives.push(vals[i]);
			}
		}
		while((! actives.empty()) && (max_ind[actives.top()] < i)) {
			actives.pop();
		}
		if (! actives.empty()) {
			rec[i] = actives.top();
		}
	}

	bool fail = false;
	for (int i = 0; i < n; ++i) {
		if (vals[i] != -1 && vals[i] != rec[i]) fail = true;
	}
	if (!fail) {
		if (min_ind[q-1] == n) {
			fail = true;
			for (int i = 0; i < n; ++i) {
				if (vals[i] == -1) {
					rec[i] = q-1;
					fail = false;
					break;
				}
			}
		}
	}
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 1; i < n; ++i) {
			if (rec[i] == -1 && rec[i-1] != -1) rec[i] = rec[i-1];
		}
		for (int i = n-2; i >= 0; --i) {
			if (rec[i] == -1 && rec[i+1] != -1) rec[i] = rec[i+1];
		}
		for (int i = 0; i < n; ++i) {
			cout << rec[i] + 1 << ' ';
		}
		cout << '\n';
	}
}