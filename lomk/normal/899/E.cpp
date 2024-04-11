/*input
6
10 10 50 10 50 50
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 200005
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}
struct data {
	int len, l;
	data(int _len, int _l): len(_len), l(_l) {};
};

bool operator < (data x, data y) {
	if (x.len != y.len) return x.len > y.len;
	return x.l < y.l;
}

int n;
int a[N];
set<data> mxlen;
set<pair<int, int> > seg;

void insert(int l, int len) {
	mxlen.insert(data(len, l));
	seg.insert(mp(l, len));
}

#define delete delete__

void delete(int l, int len, int spec = 0) {
	if (spec == 0)
		mxlen.erase(data(len, l));
	else if (spec == 1)
		seg.erase(mp(l, len));
	else {
		mxlen.erase(data(len, l));
		seg.erase(mp(l, len));
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int it = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			insert(it, i - 1 - it + 1);
			it = i;
		}
	}
	insert(it, n - it + 1);
	int ans = 0;
	while (!mxlen.empty()) {
		ans++;
		data cur = *mxlen.begin();
		delete(cur.l, cur.len, 0);
		auto it = seg.find(mp(cur.l, cur.len));
		if (it == seg.begin()) {
			delete(cur.l, cur.len, 1);
			continue;
		}
		it++;
		if (it == seg.end()) {
			delete(cur.l, cur.len, 1);
			continue;
		}
		it--;
		it--;
		pair<int, int> left = *it;
		it++; it++;
		pair<int, int> right = *it;
		delete(cur.l, cur.len, 1);
		if (a[left.fi] != a[right.fi]) continue;
		delete(left.fi, left.se, 2); delete(right.fi, right.se, 2);
		insert(left.fi, right.se + left.se);
	}
	cout << ans << endl;
}