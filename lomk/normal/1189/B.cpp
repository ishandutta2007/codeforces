/*input
5
1 2 3 4 4

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
	int n;
	cin >> n;
	vector<int> a;
	loop(i, 1, n) {
		int t; cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	if (a[a.size() - 1] >= a[a.size() - 2] + a[a.size() - 3]) {
		cout << "NO" << endl;
		return 0;
	}
	int x = a[a.size() - 3];
	a.erase(a.begin() + a.size() - 3); a.insert(a.begin(), x);
	cout << "YES" << endl;
	for (auto it : a) cout << it << sp;
	cout << endl;
}