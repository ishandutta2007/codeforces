#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// z[i] := max_{k} s.t. str[0, k) = str[i, i+k)}
vector<int> zAlgo(const string& str) {
	int n = str.size();
	vector<int> z(n, 0);
	int l = 0, r = 0; // l and r give interval such that r is maximized, l < i, and r = l + z[l].
	for (int i = 1; i < n; ++i) {
		z[i] = max(0, min(z[i-l], r-i));
		while((i+z[i] < n) && (str[z[i]] == str[i+z[i]])) ++z[i];
		if (i+z[i] > r) {
			l = i;
			r = i+z[i];
		}
	}
	return z;
}

// Length of longest palindromic prefix
int prefPali(const string& str) {
	int n = str.size();

	string tmp(2*n+1, '#');
	for (int i = 0; i < n; ++i) {
		tmp[i] = str[i];
		tmp[2*n-i] = str[i];
	}

	auto z = zAlgo(tmp);
	for (int i = 0; i < n; ++i) {
		if (i + z[n+1+i] >= n) return z[n+1+i];
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		string str;
		cin >> str;
		int n = str.size();

		string ini;
		for (int i = 0; i < (n-1-i); ++i) {
			if (str[i] == str[n-1-i]) ini.push_back(str[i]);
			else break;
		}
		int m = n - 2*(int)ini.size();

		string mid(m, '_');
		for (int j = 0; j < m; ++j) mid[j] = str[ini.size() + j];

		int a = prefPali(mid);
		reverse(mid.begin(), mid.end());
		int b = prefPali(mid);
		if (a > b) {
			swap(a, b);
			reverse(mid.begin(), mid.end());
		}

		cout << ini;
		for (int i = 0; i < b; ++i) cout << mid[i];
		reverse(ini.begin(), ini.end());
		cout << ini << '\n';
	}
}