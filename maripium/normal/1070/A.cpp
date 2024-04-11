#include <bits/stdc++.h>
using namespace std;

int d, s;
int f[5005][505];
pair<int,int> g[5005][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> d >> s;
	memset(f, -1, sizeof f);
	queue<pair<int,int>> q;
	f[0][0] = 0; q.push({0, 0});
	while (!q.empty()) {
		int sum = q.front().first;
		int rem = q.front().second;
		q.pop();
		for (int i = 0; i <= 9; ++i) {
			int nsum = sum + i;
			int nrem = (rem * 10 + i) % d;
			if (nsum <= s && f[nsum][nrem] == -1) {
				f[nsum][nrem] = f[sum][rem] + 1;
				q.push({nsum, nrem});
				g[nsum][nrem] = {sum, rem};
			}
		}
	}
	if (f[s][0] == -1) return cout << -1 << '\n',0;
	int sum = s;
	int rem = 0;
	deque<int> dq;
	while (true) {
		if (sum == 0 && rem == 0) break;
		int nsum = g[sum][rem].first;
		int nrem = g[sum][rem].second;
		dq.push_front(sum - nsum);
		sum = nsum;
		rem = nrem;
	}
	for (int x : dq) cout << x;
}