#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool diffBit(int a, int b) {
	return min(a, b) < (a ^ b);
}
int highBit(int v) {
	if (v == 0) return 0;
	int res = 1;
	while((2*res) <= v) res *= 2;
	return res;
}

int solve(vector<int>& vals) {
	// cerr << "solve(";
	// for (auto v : vals) cerr << v << ' '; cerr << ")\n";

	if (vals.size() <= 1) return vals.size();
	sort(vals.begin(), vals.end());

	int cou = 1;
	for (int i = 1; i < vals.size(); ++i) {
		if (diffBit(vals[i], vals[i-1])) ++cou;
	}
	// cerr << cou << '\n';
	
	int res = cou;
	int cur = 0;
	for (int i = 0; i < vals.size();) {
		int j = i;
		int bit = highBit(vals[i]);
		vector<int> sub;
		while(j < vals.size() && !diffBit(vals[i], vals[j])) {
			sub.push_back(vals[j] ^ bit);
			++j;
		}
		res = max(res, (cou - max(1, cur)) + solve(sub));
		i = j;
		++cur;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;
	
	int res = solve(vals);
	cout << n - res << '\n';
}