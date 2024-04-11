#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+18;

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first < b.first;
}

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, i;
	cin >> n;
	vector<ll> x(n);
	vector<ll> h(n);
	vector<pair<ll, ll> > segment;
	for (i = 0; i < n; i++)
		cin >> x[i] >> h[i];
	for (i = 0; i < n; i++) {
		if ((i == 0) || (x[i] - h[i] > x[i - 1]))
			segment.push_back(make_pair(x[i], x[i] - h[i]));
		if ((i == n - 1) || (x[i] + h[i] < x[i + 1]))
			segment.push_back(make_pair(x[i] + h[i], x[i]));
	}

	sort(segment.begin(), segment.end(), comp);
	ll m = segment.size();
	vector<ll> dp(m);
	for (i = 0; i < m; i++) {
		if (!i)
			dp[i] = 1;
		else {
			auto it = upper_bound(segment.begin(),
				segment.end(), make_pair(segment[i].second - 1, 0), comp);
			if (it == segment.begin())
				dp[i] = 1;
			else
				dp[i] = max(dp[i - 1], 1 + dp[distance(segment.begin(), it) - 1]);
		}
	}

	cout << dp[m - 1];

	return 0;
}