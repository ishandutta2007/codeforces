/*input
4
2 2
8 2
-7 0
-2 6
1 -14
16 -12
11 -18
7 -14


2
2 5
-6 4
7 -2
-1 -3
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

vector<pair<int, int> > a, b;
int n;

bool check(pair<int, int> key) {
	vector<bool> used(a.size(), 0);
	for (auto it : a) {
		bool ok = false;
		loop(i, 0, n - 1) {
			if (used[i]) continue;
			if (mp(it.fi + b[i].fi, it.se + b[i].se) == key) {
				used[i] = true; ok = true;
				break;
			}
		}
		if (!ok) return false;
	}
	return true;
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	loop(i, 1, n) {
		int x, y; cin >> x >> y;
		a.push_back(mp(x, y));
	}
	loop(i, 1, n) {
		int x, y; cin >> x >> y;
		b.push_back(mp(x, y));
	}
	loop(i, 0, n - 1) {
		if (check(mp(a[0].fi + b[i].fi, a[0].se + b[i].se))) {
			cout << a[0].fi + b[i].fi << sp << a[0].se + b[i].se << endl;
			return 0;
		}
	}
	assert(false);
}