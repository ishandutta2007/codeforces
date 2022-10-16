/*input
99871 99877
5273 34727

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
int a, b;

int disRes(int X) {
	int lo = (X - 1) / k * k + 1;
	int ret = (X - lo);
	int hi = ((X - 1) / k + 1) * k + 1;
	ret = min(ret, hi - X);
	return ret;
}

int gcd(int a , int b) {
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}

int cal(int X, int Y) {
	int x = gcd(X, Y);
	return Y / x;
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n >> k;
	cin >> a >> b;
	vector<int> satA;
	vector<int> satB;
	loop(i, 1, n * k) {
		if (disRes(i) == a) satA.push_back(i);
		if (satA.size() == 2) break;
	}
	loop(i, 1, n * k) {
		if (disRes(i) == b) satB.push_back(i);
		if (satB.size() == 2) break;
	}
	int mn = 1e18, mx = 0;
	for (auto it : satA) {
		for (auto it2 : satB) {
			int l = it2 - it;
			if (l <= 0) l += n * k;
			loop(i, 0, n) {
				l += k;
				if (l > n * k) l -= n * k;
				mn = min(mn, cal(l, n * k));
				mx = max(mx, cal(l, n * k));
			}
		}
	}
	cout << mn << sp << mx << endl;
}