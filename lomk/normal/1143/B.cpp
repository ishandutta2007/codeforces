/*input
1000000000
7
390
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
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
int read() {
	int x; cin >> x; return x;
}
string s;
int ans = 1;

void back(int pos, bool fre, int prod) {
	if (pos == s.size()) {
		ans = max(ans, prod);
		return;
	}
	int hi = s[pos] - '0';
	if (!fre) {
		back(pos + 1, 0, prod * hi);
		if (hi >= 1)
			back(pos + 1, 1, prod * (hi - 1));
	}
	else {
		back(pos + 1, 1, prod * 9);
	}
}

#define pow binPow
int binPow(int a, int q) {
	int ret = 1;
	while (q) {
		if (q & 1) ret = ret * a;
		a = a * a;
		q >>= 1LL;
	}
	return ret;
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> s;
	back(0, 0, 1);
	ans = max(ans, binPow(9, s.size() - 1));
	cout << ans << endl;
}