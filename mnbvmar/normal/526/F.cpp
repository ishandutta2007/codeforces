#include <bits/stdc++.h>
 
using namespace std;
 
class MinSegTree {
public:
	// Creates a segment tree containing at least [size] elements
	MinSegTree(int size) : base(1) {
		while (base < size) { base *= 2; }
		tree.resize(base * 2);
		// Initialize the tree with the last minimum in each node.
		for (int i = 0; i < base; ++i) {
			tree[base + i].last_min = i;
		}
		for (int v = base - 1; v > 0; --v) {
			tree[v].last_min = tree[v * 2 + 1].last_min;
		}
	}
	
	// Adds [val] to the interval [L, R)
	void AddIntv(int L, int R, int val) {
		AddIntvRec(L, R, 0, base, 1, val);
	}
	
	// Returns {the minimum in interval [L, R), the latest minimum in the interval}
	pair<int, int> GetMin(int L, int R) {
		return GetMinRec(L, R, 0, base, 1);
	}
 
	// Disable the index [idx]. It will never show up again as a viable left endpoint of an interval.
	void Disable(int idx) {
		AddIntv(idx, idx + 1, 1);
	}
 
private:
	// A structure kept in each node of the segment tree.
	struct Node {
		int min_val;   // Minimum value in the base interval.
		int last_min;  // The position of the last occurrence of this minimum.
		int push_add;  // The value that will need to be lazily added (pushed) to children
		               //   upon entry to this node.
 
		Node() : min_val(0), last_min(0), push_add(0) {}
	};
 
	vector<Node> tree;
	int base;
 
	void PushLazy(int v) {
		if (v < base) {
			for (int child : {v * 2, v * 2 + 1}) {
				tree[child].push_add += tree[v].push_add;
				tree[child].min_val += tree[v].push_add;
			}
		}
		tree[v].push_add = 0;
	}
 
	void Update(int v) {
		assert(v < base);
		tree[v].min_val = min(tree[v * 2].min_val, tree[v * 2 + 1].min_val);
		tree[v].last_min = base;
		for (int child : {v * 2, v * 2 + 1}) {
			if (tree[v].min_val == tree[child].min_val) {
				tree[v].last_min = tree[child].last_min;
			}
		}
	}
 
	void AddIntvRec(int lq, int rq, int lbase, int rbase, int v, int val) {
		if (lq >= rbase || rq <= lbase) { return; }
		PushLazy(v);
		if (lq <= lbase && rbase <= rq) {
			tree[v].min_val += val;
			tree[v].push_add += val;
			return;
		}
 
		const int mid = (lbase + rbase) / 2;
		AddIntvRec(lq, rq, lbase, mid, v * 2, val);
		AddIntvRec(lq, rq, mid, rbase, v * 2 + 1, val);
		Update(v);
	}
 
	pair<int, int> GetMinRec(int lq, int rq, int lbase, int rbase, int v) {
		if (lq >= rbase || rq <= lbase) { return {2e9, 0}; }
		PushLazy(v);
		if (lq <= lbase && rbase <= rq) {
			return {tree[v].min_val, tree[v].last_min};
		}
 
		const int mid = (lbase + rbase) / 2;
		const auto ans_left = GetMinRec(lq, rq, lbase, mid, v * 2);
		const auto ans_right = GetMinRec(lq, rq, mid, rbase, v * 2 + 1);
		const int min_val = min(ans_left.first, ans_right.first);
		const int cnt_min = max(
			(ans_left.first == min_val ? ans_left.second : 0),
			(ans_right.first == min_val ? ans_right.second : 0));
		return {min_val, cnt_min};
	}
};
 
struct DivideCombineTree {
	// The node structure. All nodes will be stored in [nodes] and
	//   can be identified with their ids.
	// Note that the interval here is p[left, right).
	struct Node {
		bool is_ordered;
		int left, right;
		vector<int> children;
 
		// Create a leaf node.
		static Node MakeLeaf(int idx) {
			return Node{false, idx, idx + 1, {}};
		}
	};
 
	vector<Node> nodes;
	int root;
 
	// Accepts permutations of both (0..n-1) and (1..n).
	// Important note: indices of the permutation are 0-based,
	//   so the code will differ slightly from the article.
	DivideCombineTree(const vector<int> &p) {
		assert(!p.empty());
		
		// Ids of current root nodes, from left to right.
		vector<int> stk_roots{0};
		
		// Initialize with p[0, 0].
		nodes.push_back(Node::MakeLeaf(0));
 
		const int n = p.size();
		MinSegTree tree(n);
		tree.AddIntv(0, 1, -1);
 
		vector<pair<int, int>> stk_max{{n + 1, -1}, {p[0], 0}};
		vector<pair<int, int>> stk_min{{-1, -1}, {p[0], 0}};
		
		// In this loop we add p[rgt] to the structure.
		for (int rgt = 1; rgt < n; ++rgt) {
			// Similarly to counting the intervals using a normal segment tree,
			// maintain max(I) for each suffix [i, rgt].
			int range_max = rgt;
			while (p[rgt] > stk_max.back().first) {
				tree.AddIntv(stk_max.back().second, range_max,
				             p[rgt] - stk_max.back().first);
				range_max = stk_max.back().second;
				stk_max.pop_back();
			}
			stk_max.emplace_back(p[rgt], range_max);
 
			// Maintain -min(I).
			int range_min = rgt;
			while (p[rgt] < stk_min.back().first) {
				tree.AddIntv(stk_min.back().second, range_min,
				             stk_min.back().first - p[rgt]);
				range_min = stk_min.back().second;
				stk_min.pop_back();
			}
			stk_min.emplace_back(p[rgt], range_min);
 
			// Maintain -length(I).
			tree.AddIntv(0, rgt + 1, -1);
			
			// At this moment, [tree] can be queried to find the non-disabled
			//   left ends of intervals whose right end is in [rgt].
 
			// Create the right-most root node p[rgt, rgt]. In the implementation, we will
			//   put it on the stack only in the very end, after all the merges.
			int rgt_node = nodes.size();
			nodes.push_back(Node::MakeLeaf(rgt));
			
			while (true) {
				// We take the right-most root node p[l, rgt]; Here, end_query == l.
				const int end_query = nodes[rgt_node].left;
 
				// We ask Tree[0, end_query) for the last active [s] s.t. p[s, rgt] is an interval.
				int min_val, last_min;
				tie(min_val, last_min) = tree.GetMin(0, end_query);
 
				// If no such [s] exists, we're done.
				if (min_val >= 0) { break; }
 
				int last_idx = stk_roots.back();
				auto &last_stk = nodes[last_idx];
 
				// Is p[s, l-1] the last node on the stack?
				if (last_min == last_stk.left) {
					// If so, we will create an ordered node or amend one of the nodes.
					
					// Don't forget to disable the left endpoint of the right-most node.
					tree.Disable(nodes[rgt_node].left);
					
					// Verify order.
					stk_roots.pop_back();
					bool is_good_order;
					if (!last_stk.is_ordered) {
						// That's an unordered node. We will always need to create a new
						//   ordered node parenting this node and the right-most node.
						is_good_order = false;
					} else {
						// That's an ordered node. We might append ourselves as the
						//   last child of p[s, l-1], but only if p[s, rgt] would be
						//   ordered the same way as p[s, l-1].
						const auto &fst = nodes[last_stk.children[0]];
						const auto &snd = nodes[last_stk.children[1]];
						const bool is_inc = p[fst.left] < p[snd.left];
						const bool my_inc = p[fst.left] < p[rgt];
						is_good_order = (is_inc == my_inc);
					}
 
					if (is_good_order) {
						// If the checks succeeded, we extend p[s, l-1] to p[s, rgt].
						last_stk.children.push_back(rgt_node);
						last_stk.right = rgt + 1;
						rgt_node = last_idx;
					} else {
						// If some checks failed, we create a new ordered node with
						//   p[s, l-1] and p[l, rgt] as children.
						Node parent{true, last_stk.left, rgt + 1, {last_idx, rgt_node}};
						rgt_node = nodes.size();
						nodes.push_back(parent);
					}
				} else {
					// We will create an unordered node p[s, rgt]. All current root nodes
					//   within p[s, rgt] will become children of this node.
					Node parent{false, last_min, rgt + 1, {}};
					vector<int> children;
					do {
						children.push_back(stk_roots.back());
						stk_roots.pop_back();
					} while (nodes[children.back()].left != last_min);
					reverse(children.begin(), children.end());
					children.push_back(rgt_node);
					parent.children = children;
 
					// Do not forget to disable all necessary endpoints in the segment tree.
					for (int i = 1; i < int(children.size()); ++i) {
						tree.Disable(nodes[children[i]].left);
					}
 
					rgt_node = nodes.size();
					nodes.push_back(parent);
				}
			}
			stk_roots.push_back(rgt_node);
		}
 
		// Final sanity checks.
		assert(stk_roots.size() == 1);
		root = stk_roots[0];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;

	vector<int> perm(n);

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		perm[x - 1] = y - 1;
	}

	DivideCombineTree ptree(perm);

	long long num_intvs = 0;
	for (auto &node : ptree.nodes) {
		const int num_ch = node.children.size();
		if (node.is_ordered) {
			num_intvs += (long long)num_ch * (num_ch - 1) / 2;
		} else {
			num_intvs += 1;
		}
	}

	cout << num_intvs << "\n";
}