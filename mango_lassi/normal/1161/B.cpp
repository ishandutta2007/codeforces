#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// TCR
// Computes the Z array in linear time
// z[i] is the length of the longest common prefix of substring
// starting at i and the string
// You can use string s instead of vector<int> s
// z[0]=0 by definition
vector<int> zAlgo(vector<int> s) {
	int n=s.size();
	vector<int> z(n);
	int l=0;int r=0;
	for (int i=1;i<n;i++) {
	z[i]=max(0, min(z[i-l], r-i));
	while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]>r) {
			l=i;r=i+z[i];
		}
	}
	return z;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lca(ll a, ll b) {
	return (a * b) / gcd(a, b);
}

const int N = (int)1e5;
vector<int> starts[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			starts[n-a+b].push_back(a);
			starts[a-b].push_back(b);
		} else {
			starts[b-a].push_back(a);
			starts[n-b+a].push_back(b);
		}
	}

	ll ans = 1;
	for (int j = 0; j < n; ++j) {
		// Find which shifts work for segs of length j
		int k = starts[j].size();
		if (k == 0) continue;

		sort(starts[j].begin(), starts[j].end());

		vector<int> dists(k);
		for (int i = 0; i < k; ++i) {
			if (i+1 == k) {
				dists[i] = (n - starts[j][i]) + starts[j][0];
			} else {
				dists[i] = starts[j][i+1] - starts[j][i];
			}
		}
		for (int i = 0; i < k; ++i) {
			dists.push_back(dists[i]);
		}

		// Do z-algo on dists
		vector<int> z = zAlgo(dists);
		ll sub = -1;
		for (int i = 1; i < k; ++i) {
			if (z[i] >= k) {
				sub = starts[j][i] - starts[j][0];
				break;
			}
		}

		/*
		cout << "len " << j << ", sub=" << sub << '\n';
		for (int i = 0; i < k; ++i) cout << dists[i] << ' '; cout << '\n';
		for (int i = 0; i < k; ++i) cout << z[i] << ' '; cout << '\n';
		*/

		if (sub == -1) {
			ans = n;
			break;
		}
		ans = lca(ans, sub);
		if (ans >= n) break;
	}
	if (ans >= n) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}