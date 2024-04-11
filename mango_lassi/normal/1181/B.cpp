#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// a < b?
bool compStr(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

string addStr(const string& a, const string& b) {
	int as = (int)a.size() - 1;
	int bs = (int)b.size() - 1;
	string res;
	int carry = 0;
	for (int i = 0;; ++i) {
		int v = carry;
		carry = 0;
		if (i <= as) v += a[as-i] - '0';
		if (i <= bs) v += b[bs-i] - '0';
		if (v >= 10) {
			v -= 10;
			carry = 1;
		}
		if (i > as && i > bs && v == 0) break;
		res.push_back(v + '0');
	}
	reverse(res.begin(), res.end());
	return res;
}

pair<string, string> splitStr(const string& str, int i) {
	int n = str.size();
	string a, b;
	for (int j = 0; j < i; ++j) a.push_back(str[j]);
	for (int j = i; j < n; ++j) b.push_back(str[j]);
	return {a, b};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;
	
	string res = str;
	for (int i = (n+1)/2; i < n; ++i) {
		if (str[i] != '0') {
			auto sub = splitStr(str, i);
			string off = addStr(sub.first, sub.second);
			if (compStr(off, res)) res = off;
			break;
		}
	}
	for (int i = (n-1)/2; i > 0; --i) {
		if (str[i] != '0') {
			auto sub = splitStr(str, i);
			string off = addStr(sub.first, sub.second);
			if (compStr(off, res)) res = off;
			break;
		}
	}
	cout << res << '\n';
}