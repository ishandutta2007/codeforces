/*input
3 8
6 5 8


*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define loop(x) for(int xv=1; xv<=x; xv++)

#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
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
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
	os << '{';
	for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
		typename set<T>::iterator jt = it;
		os << *it << (++jt != a.end() ? ", " : "");
	}
	os << '}';
	return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
	os << "{\n";
	for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
		typename map<T1, T2>::iterator jt = it;
		os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
	}
	os << '}';
	return os;
}

vector<int> a;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < a.size() / 2; i++) {
		if (a[i] > k) ans += a[i] - k;
	}
	for (int i = a.size() / 2 + 1; i < a.size(); i++) {
		if (a[i] < k) ans += k - a[i];
	}
	if (a[a.size() / 2] != k) ans += abs(k - a[a.size() / 2]);
	cout << ans << endl;
}