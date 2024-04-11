#include <iostream>
#include <string>
#include <stack>

const int N = 2 * 1e5;
int point[N];
int syno[N];

int ind(char c) {
	return (int)(c) - (int)('a');
}

struct Trie {
	Trie* next[26];
	int wi;

	Trie() {
		for (int i = 0; i < 26; ++i) {
			next[i] = 0;
		}
		wi = -1;
	}

	void add(std::string& str, int i, int word_index) {
		if (i == str.size()) {
			wi = word_index;
		} else {
			int char_index = ind(str[i]);
			if (next[char_index] == 0) {
				next[char_index] = new Trie();
			}
			(*next[char_index]).add(str, i+1, word_index);
		}
	}

	int index(std::string& str, int i) {
		if (i == str.size()) {
			return wi;
		} else {
			return (*next[ind(str[i])]).index(str, i+1);
		}
	}
};

int collapse(int i) {
	std::stack<int> coll;
	while(point[i] != i) {
		coll.push(i);
		i = point[i];
	}
	int eq = 1;
	while(! (coll.empty())) {
		int top = coll.top();
		coll.pop();
		eq *= syno[top];
		syno[top] = eq;
		point[top] = i;
	}
	return i;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, q;
	std::cin >> n >> m >> q;
	
	Trie root;
	for (int i = 0; i < n; ++i) {
		point[i] = i;
		syno[i] = 1;

		std::string str;
		std::cin >> str;
		root.add(str, 0, i);
	}
	for (int i = 0; i < m; ++i) {
		int op;
		std::string a, b;
		std::cin >> op >> a >> b;
		op = op * (-2) + 3;
		int a_ind, b_ind;
		a_ind = root.index(a, 0);
		b_ind = root.index(b, 0);
		int a_root = collapse(a_ind);
		int b_root = collapse(b_ind);
		if (a_root == b_root) {
			if (syno[a_ind] == syno[b_ind]) {
				if (op == 1) {
					std::cout << "YES\n";
				} else {
					std::cout << "NO\n";
				}
			} else {
				if (op == 1) {
					std::cout << "NO\n";
				} else {
					std::cout << "YES\n";
				}
			}
		} else {
			point[a_root] = b_root;
			if (syno[a_ind] == syno[b_ind]) {
				syno[a_root] = op;
			} else {
				syno[a_root] = -op;
			}
			std::cout << "YES\n";
		}
	}
	for (int i = 0; i < q; ++i) {
		std::string a, b;
		std::cin >> a >> b;
		int a_ind, b_ind;
		a_ind = root.index(a, 0);
		b_ind = root.index(b, 0);
		int a_root = collapse(a_ind);
		int b_root = collapse(b_ind);
		if (a_root == b_root) {
			if (syno[a_ind] == syno[b_ind]) {
				std::cout << "1\n";
			} else {
				std::cout << "2\n";
			}
		} else {
			std::cout << "3\n";
		}
	}
	
}