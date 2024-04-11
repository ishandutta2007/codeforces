/*input
4
(
((
(((
(())

7
)())
)
((
((
(
)
)

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
struct data {
	int mini, sum;
	data(int _mini, int _sum): mini(_mini), sum(_sum) {};
};

int n;
signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	vector<data > close;
	multiset<int> open;
	loop(i, 1, n) {
		string s; cin >> s;
		int mini = 0, sum = 0;
		for (auto it : s) {
			if (it == '(') sum++;
			else sum--;
			mini = min(mini, sum);
		}
		if (mini >= 0) open.insert(sum);
		else close.push_back(data(mini, sum));
	}
	sort(close.begin(), close.end(), [&](data x, data y) {
		return x.mini < y.mini;
	});
	int ans = 0;
	for (auto it : close) {
		auto iter = open.find(-it.sum);
		if (iter == open.end()) continue;
		if (-it.sum + it.mini < 0) continue;
		open.erase(iter); ans++;
	}
	int cnt = 0;
	for (auto it : open) if (it == 0) cnt++;
	ans += cnt / 2;
	cout << ans << endl;
}