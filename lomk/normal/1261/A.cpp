/*input
4
8 2
()(())()
10 3
))()()()((
2 1
()
2 1
)(

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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int cT = 1; cT <= T; cT++) {
		int n, need;
		cin >> n >> need;
		string s; cin >> s;
		int len = n + 2 - need * 2;
		string t; loop(i, 1, len / 2) t += '('; loop(i, 1, len / 2) t += ')';
		loop(i, 1, need - 1) t += "()";
		vector<pair<int, int> > order;
		loop(i, 0, n - 1) {
			if (s[i] != t[i]) {
				int p = -1;
				loop(j, i + 1, n - 1) {
					if (s[j] == t[i]) {
						p = j; break;
					}
				}
				reverse(s.begin() + i, s.begin() + p + 1);
				order.push_back(mp(i, p));
			}
		}
		cout << order.size() << endl;
		for (auto it : order) cout << it.fi + 1 << sp << it.se + 1 << endl;
	}
}