#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;
const int H = N / 2;
bitset<H + 1> can;
vector<int> g[N];
int siz[N];
ll ans[N];

int findCentroid(int i, int p, int n) {
	int res = -1;
	siz[i] = 1; ans[i] = 1;
	for (int t : g[i]) {
		if (t == p) continue;
		int x = findCentroid(t, i, n);
		if (x != -1) res = x;
		siz[i] += siz[t];
		ans[i] += siz[t] + ans[t];
	}
	if (res == -1 && 2 * siz[i] >= n) res = i;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int h = n/2;
	
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		g[p-1].push_back(i);
		g[i].push_back(p-1);
	}

	int ctr = findCentroid(0, -1, n);
	findCentroid(ctr, -1, n);

	vector<int> ws;
	for (int t : g[ctr]) ws.push_back(siz[t]);
	sort(ws.begin(), ws.end());

	can[0] = 1;
	for (int i = 0; i < ws.size();) {
		int v = ws[i], j = i;
		while(j < ws.size() && ws[j] == v) ++j;

		int cou = j - i;
		if (cou <= 10) {
			for (; i < j; ++i) can |= can << v;
		} else {
			for (int r = 0; r < v; ++r) {
				int dist = cou + 1;
				for (int x = r; x <= h; x += v) {
					if (can[x]) dist = 0;
					if (dist <= cou) can[x] = 1;
					++dist;
				}
			}
			i = j;
		}
	}

	ll res = ans[ctr];
	for (int x = h; x >= 0; --x) {
		if (can[x]) {
			res += (ll)(n-1 - x) * x;
			break;
		}
	}
	cout << res << '\n';
}