/*input
(#)

#

()((#((#(#()

(((#)((#)
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
	string s;
	cin >> s;
	int sum = 0;
	for (auto it : s) {
		if (it == '(') sum++;
		else sum--;
		if (sum < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	vector<int> order;
	bool first = true;
	for (auto &it : s) {
		if (it != '#') continue;
		if (first) {
			order.push_back(1 + sum);
			first = false;
		}
		else {
			order.push_back(1);
		}
	}
	reverse(order.begin(), order.end());
	int cnt = 0; sum = 0;
	for (auto it : s) {
		if (it == '(') sum++;
		else if (it == ')') sum--;
		else {
			sum -= order[cnt++];
		}
		if (sum < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (auto it : order) cout << it << endl;
}