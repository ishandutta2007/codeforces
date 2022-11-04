#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int acu[256], res = 1e9;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;

	if (s.size() % 2) {
		cout << -1 << endl;
		return 0;
	}

	for (char c : s)
		acu[c]++;

	for (int i = 0; i <= s.size(); i += 2) {
		int x = i / 2, y = ((int)s.size() - i) / 2;
		res = min(res, abs(acu['L'] - x) + abs(acu['R'] - x) + abs(acu['U'] - y) + abs(acu['D'] - y));
	}

	cout << res / 2 << endl;

	return 0;
}