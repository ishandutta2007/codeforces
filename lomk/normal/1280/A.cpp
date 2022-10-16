/*input
1
5
11122

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define int long long
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
//const int N=;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef in1code
	freopen("1test.inp", "r", stdin);
#endif
	int T; cin >> T;
	while (T--) {
		int n; string s;
		cin >> n;
		cin >> s;
		int len = s.size();
		loop(i, 0, n - 1) {
			assert(s.size() >= i);
			char c = s[i];
			// cout << c - '0' - 1 << sp << len - i - 1 << endl;
			if (s.size() < n) {
				string str = s.substr(i + 1);
				loop(j, 1, c - '0' - 1) {
					for (auto &it : str) {
						if (s.size() >= n) break;
						s += it;
					}
				}
			}
			len = (len + (c - '0' - 1) * (len - i - 1)) % mod;
			if (len < 0) len += mod;
		}
		cout << len % mod << endl;
	}

}