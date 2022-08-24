#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MX = 257;
int cnt[MX];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (char c : s) {
		cnt[c]++;
	}
	vector<int> g0, g1;
	for (int i = 0; i < MX; i++) {
		if (cnt[i] % 2 == 1) {
		 	g1.push_back(i);
			cnt[i]--;
		} 
		for (int j = 0; j < cnt[i] / 2; j++) {
			g0.push_back(i);
		}
	}
	if (g1.size() == 0) {
		cout << 1 << "\n";
		string hf;
		for (int i = 0; i < g0.size(); i++) {
			hf += (char)(g0[i]);
		}
		cout << hf;
		reverse(hf.begin(), hf.end());
		cout << hf << "\n";
		return 0;
	}
	while (n % g1.size() || n / g1.size() % 2 == 0) {
		g1.push_back(g0.back());
		g1.push_back(g0.back());
		g0.pop_back();
	}
	int len = n / g1.size();
	cout << g1.size() << "\n";
	int sz = g1.size();
	for (int i = 0; i < sz; i++) {
		string hf;
		for (int j = 0; j < (len - 1) / 2; j++) {
			hf += (char)(g0.back());
			g0.pop_back();
		}
		cout << hf;
		cout << (char)g1.back();
		g1.pop_back();
		reverse(hf.begin(), hf.end());
		cout << hf << " ";
	}
	cout << "\n";
	return 0;
}