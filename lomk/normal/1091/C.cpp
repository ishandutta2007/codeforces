/*input
1000000000
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
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
int n;

// add 1LL
long long cal(int dis) {
	if (dis == n)
		return 1;
	long long ret = 0; int cur = 1;
	while (true) {
		int end = (n - 1) / dis * dis + 1;
		int start = cur;
		ret += (start + end) * 1LL * ((end - start) / dis + 1) / 2;
		cur = end + dis; cur -= n; if (cur == 1) break;
		// 	cur += dis; if (cur > n) cur -= n;
		// if (cur == 1) break; ret += cur;
	}
	return ret;
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	vector<long long> ans;
	loop(i, 1, sqrt(n)) {
		if (n % i == 0) ans.push_back(cal(i)), ans.push_back(cal(n / i));
	}
	sort(ans.begin(), ans.end()); ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
	for (auto it : ans) cout << it << sp;
	cout << endl;
}