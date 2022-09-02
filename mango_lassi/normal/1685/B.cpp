#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	string str;
	cin >> str;
	int n = str.size();

	int tot_a = 0;
	for (auto c : str) tot_a += (c == 'A');
	if (tot_a != a + c + d || (n - tot_a) != b + c + d) {
		cout << "NO\n"; // Count of A, B does not match
		return;
	}

	string aux = "0";
	for (int i = 1; i < n; ++i) {
		if (str[i-1] == 'A' && str[i] == 'B') aux.push_back('A');
		else if (str[i - 1] == 'B' && str[i] == 'A') aux.push_back('B');
		else if (aux.empty() || aux.back() != '0') aux.push_back('0');
	}
	aux.push_back('0');
	
	// cout << aux << '\n';

	int base_as = 0, base_bs = 0;
	vector<pair<int, int>> off_as, off_bs;

	for (int i = 0; i < aux.size(); ++i) {
		if (aux[i] != '0') {
			int j = i + 1;
			while(j < aux.size() && aux[j] != '0') ++j;
			int len = j - i;
			if (aux[i] == 'A') {
				base_as += (len + 1) / 2;
				off_bs.emplace_back((len & 1), -len / 2);
			} else {
				base_bs += (len + 1) / 2;
				off_as.emplace_back((len & 1), -len / 2);
			}
			i = j;
		}
	}
	sort(off_as.begin(), off_as.end());
	sort(off_bs.begin(), off_bs.end());
	for (auto& pr : off_as) pr.second *= -1;
	for (auto& pr : off_bs) pr.second *= -1;
	int tar_as = c, tar_bs = d;

	/*
	cout << base_as << ' ' << base_bs << ' ' << tar_as << ' ' << tar_bs << '\n';
	for (auto pr : off_as) cout << "{" << pr.first << ' ' << pr.second << "} "; cout << '\n';
	for (auto pr : off_bs) cout << "{" << pr.first << ' ' << pr.second << "} "; cout << '\n';
	*/

	if (base_as >= tar_as && base_bs >= tar_bs) {
		cout << "YES\n";
	} else {
		if (base_bs < tar_bs) {
			swap(base_as, base_bs);
			swap(tar_as, tar_bs);
			swap(off_as, off_bs);
		}

		for (auto pr : off_as) {
			int add = min(pr.second, tar_as - base_as);
			base_as += add;
			base_bs -= add + pr.first;
			if (base_as >= tar_as) break;
		}

		if (base_as >= tar_as && base_bs >= tar_bs) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}