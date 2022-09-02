#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int C = 26;
const int SIG = 38;
const int N = 1e4;

int encChar(char c) {
	if ('a' <= c && c <= 'z') return c - 'a';
	if ('0' <= c && c <= '9') return c - '0' + C;
	if ('.' == c) return SIG - 2;
	return SIG - 1; // Null char
}

ll hashInt(const string& str, int a, int b) {
	ll res = 0;
	ll mult = 1;
	for (int i = a; i <= b; ++i) {
		res += encChar(str[i]) * mult;
		mult *= SIG;
	}
	res += mult * (SIG - 1);
	return res;
}

string strs[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<ll, pair<int, int>> mp;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> strs[i];
	
		vector<ll> matches;
		for (int a = 0; a < strs[i].size(); ++a) {
			for (int b = a; b < strs[i].size(); ++b) {
				ll code = hashInt(strs[i], a, b);
				matches.push_back(code);
			}
		}
		sort(matches.begin(), matches.end());
		matches.erase(unique(matches.begin(), matches.end()), matches.end());
		for (auto v : matches) {
			++mp[v].first;
			mp[v].second = i;
		}
	}
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string str;
		cin >> str;
		ll code = hashInt(str, 0, (int)str.size() - 1);
		ll cou = mp[code].first;
		int ent = mp[code].second;
		if (cou > 0) {
			cout << cou << ' ' << strs[ent] << '\n';
		} else {
			cout << "0 -\n";
		}
	}
}