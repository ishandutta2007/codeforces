#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Tree {
	ll n;
	vector<ll> tree;
	Tree() {}
	Tree(ll n): n(n), tree(n * 2, 0) {}
	void set(ll index, ll value) {
		index += n;
		tree[index] = max(tree[index], value);
		for (index >>= 1; index > 0; index >>= 1)
			tree[index] = max(tree[index], value);
	}
	ll get(ll l, ll r) {
		ll res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1)
				res = max(res, tree[l++]);
			if (r & 1)
				res = max(res, tree[--r]);
		}
		return res;
	}
};

bool comp(pair<ll, ll> const &a, pair<ll, ll> const &b) {
	return (a.first < b.first);
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/
	
	ll n, i, j, k, x, w;
	cin >> n;
	vector<pair<ll, ll> > starts(n);
	vector<pair<ll, ll> > ends(n);
	vector<ll> movedto(n);
	for (i = 0; i < n; i++) {
		cin >> x >> w;
		starts[i] = make_pair(x - w, i);
		ends[i] = make_pair(x + w, i);
	}

	sort(starts.begin(), starts.end(), comp);
	sort(ends.begin(), ends.end(), comp);
	for (i = 0; i < n; i++)
		movedto[starts[i].second] = i;
	for (i = 0; i < n; i++)
		starts[movedto[ends[i].second]].second = i;
	for (i = 1, j = 0, k = 0; i <= n; i++)
		if ((i == n) || (ends[i].first != ends[i - 1].first)) {
			for (; j < i; j++)
				ends[j].second = k;
			k++;
			j = i;
		}

	Tree tree(k);
	for (i = 0; i < n; i++) {
		auto it = upper_bound(ends.begin(), ends.end(), starts[i], comp);
		if (it == ends.begin())
			j = -1;
		else
			j = (--it)->second;
		tree.set(ends[starts[i].second].second, tree.get(0, j + 1) + 1);
	}

	cout << tree.get(0, k);

	return 0;
}