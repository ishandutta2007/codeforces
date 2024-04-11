#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 3e5 + 100;
int n, l[MAXN], r[MAXN];


using pii = pair<int, int>;

template<class TIn, class TOut> // key, value types. TOut can be null_type
using order_tree = tree<TIn, TOut, less<TIn>,
	rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(int r) (0-based)
// order_of_key(TIn v)
// use key pair<Tin,int> {value, counter} for multiset/multimap
template<class T>
using stat_set = order_tree<T, null_type>;

/*
struct cmp1 {
	bool operator()(const int &a, const int &b) const {
		if (r[a] != r[b]) return r[a] < r[b];
		if (l[a] != l[b]) return l[a] > l[b];
		return a < b;
	}
};
*/

struct cmp2 {
	bool operator()(const pii &a, const pii &b) const {
		int xa = (a.second == 1 ? r[a.first] : l[a.first]);
		int xb = (b.second == 1 ? r[b.first] : l[b.first]);
		// sort on smaller index.
		if (xa != xb) return xa > xb;
		// first handle 1 (r), then 0 (l)
		if (a.second != b.second) return a.second > b.second;
		return a.first > b.first;
	}
};

stat_set<pii> active;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> n >> k;

	priority_queue< pii, vector<pii>, cmp2 > q;

	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		r[i]++;
		q.push(pii(i, 0)); // enter: 0
		q.push(pii(i, 1)); // leave: 1
	}

	int best = 0, al, ar;
	while (!q.empty()) {
		int cur = q.top().first;
		int op = q.top().second;
		q.pop();

		pii pr = pii(l[cur], cur);
		if (op == 0) {
			active.insert(pr);
		} else {
			if (active.size() >= k) {
				// cerr << "REMOVE " << cur << ": " << r[cur] << endl;
				auto it = active.find_by_order(k - 1);
				// cerr << "ITERATOR: " << it->first << ", " << it->second << endl;
				int leftSide = it->first;
				int rightSide = r[cur];
				// cerr << leftSide << " - " << rightSide << endl;
				best = max(best, rightSide - leftSide);
				if (best == rightSide - leftSide) {
					al = leftSide;
					ar = rightSide;
				}
			}
			active.erase(pr);
		}
	}

	if (best == 0) {
		cout << "0" << endl;
		for (int i = 0; i < k; i++) {
			if (i > 0) cout << " ";
			cout << (i + 1);
		}
		cout << endl;
		return 0;
	}

	cout << best << endl;

	int nDone = 0;
	for (int i = 0; i < n; i++) {
		if (l[i] <= al && ar <= r[i]) {
			if (nDone > 0) cout << " ";
			cout << (i + 1);
			nDone++;
			if (nDone == k) break;
		}
	}
	cout << endl;

	return 0;
}