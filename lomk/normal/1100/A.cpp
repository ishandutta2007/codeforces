/*input
14 3
-1 1 -1 -1 1 -1 -1 1 -1 -1 1 -1 -1 1

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

int n, k;
vector<int> a;
signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n >> k;
	loop(i, 1, n) {
		a.push_back(read());
	}
	int INF = 1e9; int ans = 0;
	loop(b, 0, k - 1) {
		vector<int> x = a;
		loop(i, 0, INF) {
			if (b - i * k < 0) break;
			x[b - i * k] = 0;
		}
		loop(i, 0, INF) {
			if (b + i * k >= n) break;
			x[b + i * k] = 0;
		}
		int cur = 0;
		for (auto it : x) cur += it;
		ans = max(ans, abs(cur));
	}
	cout << ans << endl;
}