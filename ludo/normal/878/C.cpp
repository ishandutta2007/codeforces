#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
int K, S[10];

struct Group {
	int n, mins[10], maxs[10];
	Group() : n(1) {}
};

bool operator<(const Group &a, const Group &b) {
	for (int i = 0; i < K; i++)
		if (a.maxs[i] > b.mins[i]) return false;
	return true;
}

Group& operator+=(Group &lhs, const Group &rhs) {
	lhs.n += rhs.n;
	rep(i, 0, K) lhs.mins[i] = min(lhs.mins[i], rhs.mins[i]);
	rep(i, 0, K) lhs.maxs[i] = max(lhs.maxs[i], rhs.maxs[i]);
	return lhs;
}

set<Group> gs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	int N;
	cin >> N >> K;
	while (N--) {
		Group g;
		rep(i,0,K) cin >> g.mins[i], g.maxs[i] = g.mins[i];

		auto it1 = gs.lower_bound(g), it2 = gs.upper_bound(g);
		while (it1 != it2) g += *it1, it1 = gs.erase(it1);
		gs.insert(g);
		cout << gs.rbegin()->n << endl;
	}
	return 0;
}