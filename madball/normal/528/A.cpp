#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef long long ll;

struct Tree {
	ll n, size;
	vector<ll> tree;
	Tree() {}
	Tree(ll n): n(n), tree(n * 2, 0), size(1) {}
	void set(ll index, ll value) {
		index += n;
		tree[index] = value;
		while (index > 1) {
			index >>= 1;
			tree[index] = max(tree[index << 1], tree[(index << 1) + 1]);
		}
	}
	ll get() {
		return tree[1];
	}
};

struct Segment {
	ll size, ind;
	Segment() {}
	Segment(ll s, ll i): size(s), ind(i) {}
	bool operator < (Segment const &s) const {
		return size < s.size;
	}
};

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	ll w, h, n, i, cur;
	vector<ll> cut1, cut2;
	vector<char> order;
	char c;
	cin >> w >> h >> n;
	for (i = 0; i < n; i++) {
		cin >> c >> cur;
		if (c == 'H')
			cut1.push_back(cur);
		else
			cut2.push_back(cur);
		order.push_back(c);
	}

	set<Segment> seg1, seg2;
	seg1.insert(Segment(h, 0));
	seg2.insert(Segment(w, 0));

	Tree tree1(cut1.size() + 1), tree2(cut2.size() + 1);
	tree1.set(0, h);
	tree2.set(0, w);

	ll ind1 = 0, ind2 = 0, ws, max1 = h, max2 = w;

	for (i = 0; i < n; i++) {
		c = order[i];
		if (c == 'H') {
			cur = cut1[ind1++];
			auto it = seg1.lower_bound(Segment(cur, 0));
			ws = tree1.tree[(*it).ind + tree1.n];
			tree1.set(tree1.size, ws - ((*it).size - cur));
			tree1.set((*it).ind, (*it).size - cur);
			seg1.insert(Segment(cur, tree1.size++));
			max1 = tree1.get();
		}
		else {
			cur = cut2[ind2++];
			auto it = seg2.lower_bound(Segment(cur, 0));
			ws = tree2.tree[(*it).ind + tree2.n];
			tree2.set(tree2.size, ws - ((*it).size - cur));
			tree2.set((*it).ind, (*it).size - cur);
			seg2.insert(Segment(cur, tree2.size++));
			max2 = tree2.get();
		}
		cout << max1 * max2 << '\n';
	}

	return 0;
}