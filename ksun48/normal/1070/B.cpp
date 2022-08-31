#include <bits/stdc++.h>
using namespace std;

struct node {
	node* ch[2];
	bool isB;
	bool isW;
	bool hasB;
	bool hasW;
};

int P;
node pool[int(1e7)];
node* root = nullptr;

void FAIL() {
	cout << -1 << endl;
	exit(0);
}

vector<pair<int, int>> res;
void solve(node* cur, int addr = 0, int msk = 0) {
	if (!cur) return;
	//cerr << int(cur - pool) << ' ' << addr << ' ' << msk << '\n';
	if (!cur->hasB) {
		return;
	}
	assert(cur->hasB);
	if (!cur->hasW) {
		assert(!cur->isW);
		// just add this node
		res.emplace_back(addr << (32-msk), msk);
		return;
	}
	assert(cur->hasW);
	if (cur->isB || cur->isW) {
		FAIL();
	}
	solve(cur->ch[0], (addr << 1), msk+1);
	solve(cur->ch[1], (addr << 1) | 1, msk+1);
}

int main() {
	root = &pool[P++];

	string line;
	int n; cin >> n;
	getline(cin, line);
	for (int z = 0; z < n; z++) {
		getline(cin, line);
		bool hasMsk = false;
		for (char c : line) {
			if (c == '/') hasMsk = true;
		}
		if (!hasMsk) {
			line += "/32";
		}
		char type;
		int a, b, c, d, msk;
		sscanf(line.c_str(), "%c%d.%d.%d.%d/%d", &type, &a, &b, &c, &d, &msk);
		//fprintf(stderr, "%c %d.%d.%d.%d/%d\n", type, a,b,c,d,msk);

		int addr = (((((a << 8) | b) << 8) | c) << 8) | d;
		assert((addr >> (32-msk)) << (32-msk) == addr);

		node* cur = root;
		for (int i = 0; i < msk; i++) {
			assert(cur);
			if (type == '-') {
				cur->hasB = true;
			} else if (type == '+') {
				cur->hasW = true;
			} else assert(false);
			int dir = (addr >> (31-i)) & 1;

			if (!cur->ch[dir]) {
				cur->ch[dir] = &pool[P++];
			}
			cur = cur->ch[dir];
		}
		assert(cur);
		if (type == '-') {
			cur->hasB = true;
			cur->isB = true;
		} else if (type == '+') {
			cur->hasW = true;
			cur->isW = true;
		} else assert(false);
	}
	solve(root);
	printf("%d\n", int(res.size()));
	for (auto it : res) {
		int addr = it.first;
		int msk = it.second;
		printf("%d.%d.%d.%d/%d\n", (addr >> 24) & 255, (addr >> 16) & 255, (addr >> 8) & 255, (addr >> 0) & 255, msk);
	}
	return 0;
}