/*input
10
onetwonetwooneooonetwooo
two
one
twooooo
ttttwo
ttwwoo
ooone
onnne
oneeeee
oneeeeeeetwooooo


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
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		string tmp;
		vector<int> order;
		vector<bool> mark(s.size(), 0);
		loop(i, 0, s.size() - 1) {
			tmp.push_back(s[i]);
			if (tmp.size() >= 5) {
				if (tmp.substr(tmp.size() - 5, 5) == "twone") {
					tmp[tmp.size() - 3] = '!';
					mark[i - 2] = true; order.push_back(i - 2);
				}
			}
		}
		s = tmp; tmp = "";
		loop(i, 0, s.size() - 1) {
			tmp.push_back(s[i]);
			if (tmp.size() >= 3) {
				if (tmp.substr(tmp.size() - 3, 3) == "one") {
					tmp.erase(tmp.begin() + tmp.size() - 2);
					order.push_back(i - 1);
				}
				else if (tmp.substr(tmp.size() - 3, 3) == "two") {
					tmp.erase(tmp.begin() + tmp.size() - 2);
					order.push_back(i - 1);
				}
			}
		}
		cout << order.size() << endl;
		for (auto it : order) cout << it + 1 << sp;
		cout << endl;
	}
}