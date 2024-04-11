#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

// Struct for priority queue operations on index set [1, n]
// push(i, v) overwrites value at position i if one already exists
// decKey is faster but requires that the new key is smaller than the old one
struct Prique {
	const ll INF = 4 * (ll)1e18;
	vector<pair<ll, int>> data;
	const int n;

	Prique(int siz) : n(siz), data(2*siz, {INF, -1}) { data[0] = {-INF, -1}; }
	void push(int i, ll v) {
		data[i+n] = {v, (v >= INF ? -1 : i)};
		for (i += n; i > 1; i >>= 1) data[i>>1] = min(data[i], data[i^1]);
	}
	void decKey(int i, ll v) {
		for (int j = i+n; data[j].first > v; j >>= 1) data[j] = {v, i};
	}
	pair<ll, int> pop() {
		auto res = data[1];
		push(res.second, INF);
		return res;
	}
	bool empty() {
		return data[1].first >= INF;
	}
};

class AhoCora {
	private:
		vector<int> pat_ind; // Index of pattern at this node (-1 if none)
		vector<int> suf_link; // Longest string in automata that is this one's true suffix
		vector<int> pat_link; // Index of next pattern when following suffix links
		vector<map<char, int>> conns; // Edges to children from this node

		// Alloc a new node
		int makeNode() {
			pat_ind.push_back(-1);
			suf_link.push_back(-1);
			pat_link.push_back(-1);
			conns.emplace_back();
			return (int)pat_ind.size() - 1;
		}

		// Get target of edge from node i, labeled with char c. -1 if none.
		int get(int i, char c) {
			auto it = conns[i].find(c);
			if (it == conns[i].end()) return -1;
			else return (*it).second;
		}

		// Set target of edge from node i, labeled with char c
		void set(int i, char c, int t) {
			conns[i][c] = t;
		}

		// Extends the suffix by the given character
		int extend(int i, char c) {
			int res = -1;
			while((i != -1) && (res == -1)) {
				res = get(i, c);
				i = suf_link[i];
			}
			return max(res, 0); // root always works
		}

	public:
		AhoCora() {
			makeNode(); // make root
		}

		// Adds the string to the automata
		// Time complexity: O(|pat| log C)
		void addPattern(const string& pat) {
			int i = 0; // current node
			for (char c : pat) {
				if (get(i, c) == -1) set(i, c, makeNode());
				i = get(i, c);
			}
			pat_ind[i] = 1;
		}

		// Build suf_link and pat_link. Call after inserting all patterns, before matching
		// Time complexity: O(\sum |pat| log C)
		void buildLinks() {
			vector<int> que;
			que.push_back(0);
			for (int j = 0; j < que.size(); ++j) {
				int i = que[j];
				for (auto pr : conns[i]) {
					char c = pr.first;
					int t = pr.second;
					suf_link[t] = extend(suf_link[i], c);
					if (pat_ind[suf_link[t]] != -1) pat_link[t] = suf_link[t];
					else pat_link[t] = pat_link[suf_link[t]];
					que.push_back(t);
				}
			}
		}

		int addChar(int i, char c) {
			int t = extend(i, c);
			if (pat_ind[t] != -1 || pat_link[t] != -1) return -1;
			else return t;
			
		}

		int size() {
			return pat_ind.size();
		}
};


const int G = 102;
const int N = 100;
const int M = 50;

vector<int> apps[G]; // Patterns where g appears
vector<int> mts[N]; // Patterns
ll moves[G][M+1][M+1]; // What which symbol can transform to and how fast?
ll cur[2][M+1][M+1];

vector<int> ss, tt;

void clearCur(int d, int k) {
	for (int s = 0; s < k; ++s) {
		for (int t = 0; t < k; ++t) cur[d][s][t] = INF;
	}
}

void updateVal(int i, int s, int t, ll v, Prique& que) {
	if (moves[i][s][t] > v) {
		moves[i][s][t] = min(moves[i][s][t], v);
		que.decKey(i, v);
		// cerr << "updateVal(" << i << ' ' << s << ' ' << t << ' ' << v << ")\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int g, n, m;
	cin >> g >> n >> m;

	// read mutations
	for (int j = 0; j < n; ++j) {
		int i, len;
		cin >> i >> len;
		mts[j].resize(len + 1);
		mts[j][0] = i;
		for (int x = 1; x <= len; ++x) {
			cin >> mts[j][x];
			
			bool first_app = 1;
			for (int y = 1; y < x; ++y) {
				if (mts[j][y] == mts[j][x]) first_app = 0;
			}
			if (first_app) apps[mts[j][x]].push_back(j);
		}
	}

	// read antibodies, build the Aho-Corasick
	AhoCora ac;
	for (int i = 0; i < m; ++i) {
		string str;
		int len;
		cin >> len;
		for (int j = 0; j < len; ++j) {
			int b;
			cin >> b;
			str.push_back('0' + b);
		}
		ac.addPattern(str);
	}
	ac.buildLinks();
	int k = ac.size();

	// How many times can a string be updated?
	// 	It has k^2 pairs -> k^2 times
	//	Each time, we process some patterns. A pattern of length LEN can be processed LEN k^2 times
	//	Processing it takes len k^3 time (which for a max-length pattern, is already almost TL!)

	// If we store the transitions in a segment tree, we don't need to redo all of the work, just APPS * log k * k^3 of it
	// Still, k seems far too large!

	// Calculate initial pattern-avoiding moves
	for (int i = 0; i < g; ++i) {
		for (int s = 0; s < k; ++s) {
			for (int t = 0; t < k; ++t) moves[i][s][t] = INF;
		}
	}

	Prique que(g);
	for (int s = 0; s < k; ++s) {
		int t = ac.addChar(s, '0');
		if (t != -1) updateVal(0, s, t, 1, que);
		// cerr << s << " + 0 = " << t << '\n';

		t = ac.addChar(s, '1');
		if (t != -1) updateVal(1, s, t, 1, que);
		// cerr << s << " + 1 = " << t << '\n';
	}

	// While new, faster ways are found, apply them
	while(! que.empty()) {
		int i = que.pop().second;

		// cerr << "pushing updates from " << i << endl;
		for (int pat_ind : apps[i]) {
			// cerr << "updating pattern " << pat_ind << "!" << endl;

			vector<int>& pat = mts[pat_ind];
			int ti = pat[0];

			clearCur(0, k);
			clearCur(1, k);
			for (int s = 0; s < k; ++s) cur[0][s][s] = 0;
			for (int j = 1; j < pat.size(); ++j) {

				int ci = pat[j];
				int d1 = (j & 1);
				int d0 = 1 - d1;
				clearCur(d1, k);

				for (int p = 0; p < k; ++p) {
					tt.clear();
					for (int t = 0; t < k; ++t) {
						if (moves[ci][p][t] < INF) tt.push_back(t);
					}
					if (tt.empty()) continue;

					ss.clear();
					for (int s = 0; s < k; ++s) {
						if (cur[d0][s][p] < INF) ss.push_back(s);
					}
					
					for (auto s : ss) {
						for (auto t : tt) {
							cur[d1][s][t] = min(cur[d1][s][t], cur[d0][s][p] + moves[ci][p][t]);
						}
					}
				}
			}

			int dl = ((int)pat.size() - 1) & 1;
			for (int s = 0; s < k; ++s) {
				for (int t = 0; t < k; ++t) {
					// if (cur[dl][s][t] < INF) cerr << s << ' ' << t << " is now possible for " << ti << endl;
					updateVal(ti, s, t, cur[dl][s][t], que);
				}
			}
		}
	}

	// Output res
	for (int i = 2; i < g; ++i) {
		ll res = INF;
		for (int t = 0; t < k; ++t) {
			res = min(res, moves[i][0][t]);
		}
		if (res >= INF) cout << "YES\n";
		else cout << "NO " << res << '\n';
	}
}