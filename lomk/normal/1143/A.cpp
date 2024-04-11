/*input
4
1 0 0 1


5
0 0 1 0 0

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
const int N = 2e5 + 5;
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

int n;
int a[N];
signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	int cnt[2]; memset(cnt, 0, sizeof(cnt));
	loop(i, 1, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	loop(i, 1, n) {
		cnt[a[i]]--;
		if (cnt[a[i]] == 0) {
			cout << i << endl;
			return 0;
		}
	}
}