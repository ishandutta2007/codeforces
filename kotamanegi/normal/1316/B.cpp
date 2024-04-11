#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<pair<string, int>> inputs;
	string b = s;
	s.clear();
	for (int i = 0; i < n; ++i) {
		string c = s;
		if ((n - c.length()) % 2 == 1) {
			reverse(ALL(c));
		}
		inputs.push_back(mp(b+c, i + 1));
		if (b != "") {
			s.push_back(b.front());
			b.erase(b.begin());
		}
	}
	sort(ALL(inputs));
	cout << inputs[0].first << endl;
	cout << inputs[0].second << endl;
}
#undef int

int main() {
	init();
	int t;
	cin >> t;
	REP(tea,t)
	solve();
}