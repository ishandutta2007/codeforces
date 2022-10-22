#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+9;

ll max(ll a, ll b) {
	return (a > b ? a : b);
}

struct Tree {
	ll n;
	vector<ll> val;
	vector<ll> sum;
	vector<ll> left;
	vector<ll> right;
	vector<ll> mid;
	Tree() {}
	Tree(ll n): n(n), val(n, -inf), sum(n * 2, -inf), left(n * 2, -inf), right(n * 2, -inf), mid(n * 2, -inf) {
		for (ll i = n - 1; i; i--)
			sum[i] = sum[i * 2] + sum[i * 2 + 1];
	}
	void set(ll i) {
		val[i] = 1;
		for (i += n; i; i >>= 1) {
			sum[i] += 1 + inf;
			if (i >= n) {
				left[i] = 1;
				right[i] = 1;
				mid[i] = 1;
			}
			else {
				left[i] = max(left[i * 2], sum[i * 2] + left[i * 2 + 1]);
				right[i] = max(right[i * 2 + 1], sum[i * 2 + 1] + right[i * 2]);
				mid[i] = max(max(mid[i * 2], mid[i * 2 + 1]), right[i * 2] + left[i * 2 + 1]);
			}
		}
	}
	ll res() {
		return mid[1];
	}
};

struct Elem {
	ll val, index;
	Elem() {}
	Elem(ll v, ll i): val(v), index(i) {}
	bool operator < (Elem const &e) const {
		return val > e.val;
	}
};

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, cur, i, res, x, n2 = 1;
	cin >> n;
	vector<Elem> elems(n);
	for (i = 0; i < n; i++) {
		cin >> cur;
		//cout << cur << ' ';
		elems[i] = Elem(cur, i);
	}
	sort(elems.begin(), elems.end());
	
	while (n2 < n)
		n2 <<= 1;
	Tree tree(n2);
	x = 1;
	for (i = 0; i < n; i++) {
		tree.set(elems[i].index);
		if ((i == n - 1) || (elems[i + 1].val != elems[i].val))
			for (res = tree.res(); res >= x; x++)
				cout << elems[i].val << ' ';
	}

	return 0;
}