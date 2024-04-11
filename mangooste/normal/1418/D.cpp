#include <bits/stdc++.h>

using namespace std;

template<class T>
string to_string(T v);

string to_string(string s) {
	return "\"" + s + "\"";
}

string to_string(bool b) {
	return b ? "true" : "false";
}

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T>
string to_string(T v) {
	string s = "{";
	bool first = true;
	for (auto x : v) {
		if (!first)
			s += ", ";
		first = false;
		s += to_string(x);
	}
	return s + "}";
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}

#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

template<class T>
inline void set_max(T& val, T mb) {
	if (val < mb)
		val = mb;
}

mt19937 rng(time(NULL));

struct Node {
	int val;
	int y;
	int max_x;
	int min_x;
	Node* left;
	Node* right;
	int max_delta;

	Node() : 
		val(0), y((int) rng()), max_x(0), min_x(0), left(nullptr), right(nullptr), max_delta(0)
	{}
};

inline void relax(Node* v) {
	assert(v);
	Node* left = v->left;
	Node* right = v->right;
	v->min_x = (left ? left->min_x : v->val);
	v->max_x = (right ? right->max_x : v->val);
	v->max_delta = 0;
	if (left)
		set_max(v->max_delta, v->val - left->max_x);
	if (right)
		set_max(v->max_delta, right->min_x - v->val);
	if (left)
		set_max(v->max_delta, left->max_delta);
	if (right)
		set_max(v->max_delta, right->max_delta);
}

pair<Node*, Node*> split(Node* v, int x) {
	if (!v)
		return {v, v};
	if (x <= v->val) {
		pair<Node*, Node*> now = split(v->left, x);
		v->left = now.second;
		relax(v);
		return {now.first, v};
	} else {
		pair<Node*, Node*> now = split(v->right, x);
		v->right = now.first;
		relax(v);
		return {v, now.second};
	}
}

Node* merge(Node* left, Node* right) {
	if (!left)
		return right;
	if (!right)
		return left;
	// debug(228);
	if (left->y > right->y) {
		left->right = merge(left->right, right);
		relax(left);
		return left;
	} else {
		right->left = merge(left, right->left);
		relax(right);
		return right;
	}
}

Node* root = nullptr;

inline void insert(int x) {
	// debug(x);
	Node* cur = new Node();
	cur->val = cur->max_x = cur->min_x = x;
	pair<Node*, Node*> now = split(root, x);
	root = merge(merge(now.first, cur), now.second);
}

inline void erase(int x) {
	pair<Node*, Node*> now1 = split(root, x);
	pair<Node*, Node*> now2 = split(now1.second, x + 1);
	root = merge(now1.first, now2.second);
}

inline void solve() {
	if (root == nullptr)
		return cout << 0 << '\n', void();
	cout << root->max_x - root->min_x - root-> max_delta << '\n';
}

void print(Node* v) {
	if (!v)
		return;
	print(v->left);
	cout << v->val << ' ';
	print(v->right);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	set<int> was;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!was.count(x))
			insert(x);
		was.insert(x);
	}
	// print(root);
	// cout << endl;
	solve();
	while (q--) {
		int op, x;
		cin >> op >> x;
		if (op == 0)
			erase(x);
		else
			insert(x);
		// print(root);
		// cout << endl;
		// debug(root->max_delta);
		solve();
	}
}