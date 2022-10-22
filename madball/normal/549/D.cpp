#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef long long ll;

struct Tree {
	ll n;
	vector<ll> tree;
	Tree() {}
	Tree(ll n): n(n), tree(n * 2, 0) {}
	ll get(ll i) {
		ll res = 0;
		for (i += n; i; i >>= 1)
			res += tree[i];
		return res;
	}
	void add(ll l, ll r, ll val) {
		for (l += n, r += n; r > l; r >>= 1, l >>= 1) {
			if (l & 1)
				tree[l++] += val;
			if (r & 1)
				tree[--r] += val;
		}
	}
};

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, m, i, j, k;
	char inp;
	cin >> n >> m;
	vector<Tree> val(n, Tree(m));
	vector<vector<ll> > need(n, vector<ll>(m));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			cin >> inp;
			need[i][j] = (inp == 'W' ? 1 : -1);
		}

	ll cur, res = 0;
	for (i = n - 1; i >= 0; i--)
		for (j = m - 1; j >= 0; j--) {
			cur = val[i].get(j);
			if (cur != need[i][j]) {
				res++;
				for (k = i; k >= 0; k--)
					val[k].add(0, j + 1, need[i][j] - cur);
			}
		}

	cout << res;

	return 0;
}