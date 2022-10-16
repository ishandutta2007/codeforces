/*input
3
120
120
120


3
10
10
10

3
10
20
30
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

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	int n;
	cin >> n;
	vector<int> a;
	loop(i, 1, n) {
		int t; cin >> t;
		a.push_back(t);
	}
	loop(mask, 0, (1 << n) - 1) {
		int sum = 0;
		loop(i, 0, n - 1) {
			if (bit(mask, i)) sum += a[i];
			else sum -= a[i];
		}
		if (sum % 360 == 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}