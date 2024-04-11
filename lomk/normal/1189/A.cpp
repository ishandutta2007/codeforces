/*input
6
100011

2
10

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

bool good(string s) {
	int cnt[2]; memset(cnt, 0, sizeof(cnt));
	for (auto it : s) {
		cnt[it - '0']++;
	}
	if (cnt[0] != cnt[1]) return true;
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s; cin >> s;
	int cnt[2]; memset(cnt, 0, sizeof(cnt));
	if (good(s.substr(0, s.size()))) {
		cout << 1 << endl;
		cout << s << endl;
		return 0;
	}
	loop(i, 0, (int)s.size() - 2) {
		if (good(s.substr(0, i + 1)) && good(s.substr(i + 1, s.size() - i - 1))) {
			cout << 2 << endl;
			cout << s.substr(0, i + 1) << sp << s.substr(i + 1, s.size() - i - 1) << endl;
			return 0;
		}
	}
}