/*input
30
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)

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

int n;
#define rand rd
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int INF = 1e9;
int ask(int X) {
	cout << X << sp << 1 << endl;
	string s; cin >> s;
	if (s == "black") return 0;
	return 1;
}

int oriColor;
void solve(int L, int R, int pos) {
	if (pos == 0) {
		cout << L - 1 << sp << 0 << sp << L << sp << 2 << endl;
		exit(0);
	}
	if (pos == n) {
		oriColor = ask(L);
		solve(L + 1, R, pos - 1);
	}
	int mid = (L + R) / 2;
	auto rec = ask(mid);
	if (rec == oriColor) solve(mid + 1, R, pos - 1);
	else solve(L, mid - 1, pos - 1);
}

signed main() {
	cin >> n;
	solve(0, INF, n);
}