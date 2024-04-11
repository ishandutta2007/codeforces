#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


void work() {
	int n;
	string t;
	vector <string> s;
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string w; cin >> w; s.push_back(w);
	}
	vector <int> dp(t.size() + 1, 0x3f3f3f3f);
	vector <pair <int, int> > fr(t.size() + 1, {-1, -1});
	dp[0] = 0;
	for (int i = 0; i < t.size(); i++) {
		int idx = -1;
		for (auto j : s) {
			idx ++;
			if (t.substr(i, j.size()) == j) {
				for (int w = 0; w < j.size(); w++) {
					int k = i + w + 1;
					if (dp[k] > dp[i] + 1) {
						dp[k] = dp[i] + 1;
						fr[k] = {i, idx};
					}
				}
			}
		}
	}
	if (dp[t.size()] > t.size()) {
		puts ("-1");
	} else {
		printf("%d\n", dp[t.size()]);
		int x = t.size();
		while (x > 0) {
			printf("%d %d\n", fr[x].second + 1, fr[x].first + 1);
			x = fr[x].first;
		}
	}
}

int main() {
	int T;
	read(T);
	while (T--) work();

}