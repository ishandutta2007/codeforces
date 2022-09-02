#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;

template<int H>
struct MergeTree {
	array<MergeTree<H-1>*, 2> ch;
	array<int, H+1> branch_cou;

	// (01 -> no change), (00 -> set 0), (11 -> set 1), (10 -> flip)
	uint s0 = 0, s1 = -1;
	uint size = 0;

	MergeTree() : branch_cou(), ch{nullptr, nullptr} {}
	MergeTree(int v) : branch_cou(), size(1) {
		int b = (bool)(v & (1 << H));
		ch[b] = new MergeTree<H-1>(v);
		ch[b ^ 1] = nullptr;
	}
	static int getSize(MergeTree<H>* t) { return (t == nullptr ? 0 : t->size); }

	void apply(uint t0, uint t1) {
		uint b0 = (bool)(t0 & (1 << H));
		uint b1 = (bool)(t1 & (1 << H));
		if (b0 && ! b1) {
			swap(ch[0], ch[1]);
		} else if (b0 == b1) {
			// We GUARANTEE that when we merge children here, one is nullptr
			if (ch[b0] == nullptr) ch[b0] = ch[b0 ^ 1];
			ch[b0 ^ 1] = nullptr;
		}
		s0 = (s0 | t0) & ((~s0) | t1);
		s1 = (s1 & t1) | ((~s1) & t0);
	}
	void push() {
		if (ch[0]) ch[0]->apply(s0, s1);
		if (ch[1]) ch[1]->apply(s0, s1);
		s0 = 0; s1 = -1;
	}
	void update() {
		size = MergeTree<H-1>::getSize(ch[0]) + MergeTree<H-1>::getSize(ch[1]);
		if (ch[0] && ch[1]) {
			branch_cou[H] = 1;
			if constexpr(H > 0) {
				for (int j = 0; j < H; ++j) {
					branch_cou[j] = ch[0]->branch_cou[j] + ch[1]->branch_cou[j];
				}
			}
		} else {
			branch_cou[H] = 0;
			if constexpr(H > 0) {
				if (ch[0]) {
					for (int j = 0; j < H; ++j) branch_cou[j] = ch[0]->branch_cou[j];
				} else if (ch[1]) {
					for (int j = 0; j < H; ++j) branch_cou[j] = ch[1]->branch_cou[j];
				} else {
					for (int j = 0; j < H; ++j) branch_cou[j] = 0;
				}
			}
		}
	}


	static MergeTree<H>* merge(MergeTree<H>* a, MergeTree<H>* b) {
		if (!a) return b;
		if (!b) return a;

		a->push(), b->push();
		a->ch[0] = MergeTree<H-1>::merge(a->ch[0], b->ch[0]);
		a->ch[1] = MergeTree<H-1>::merge(a->ch[1], b->ch[1]);
		a->update();

		delete b;
		return a;
	}

	static pair<MergeTree<H>*, MergeTree<H>*> split(MergeTree<H>* a, uint v) {
		if (! a) return {nullptr, nullptr};
		MergeTree<H>* b = nullptr;

		a->push();
		if (v & (1 << H)) {
			auto sub = MergeTree<H-1>::split(a->ch[1], v);
			a->ch[1] = sub.first;
			a->update();
			if (sub.second != nullptr) {
				b = new MergeTree<H>();
				b->ch[1] = sub.second;
				b->update();
			}
			return {a, b};
		} else {
			auto sub = MergeTree<H-1>::split(a->ch[0], v);
			a->ch[0] = sub.second;
			a->update();
			if (sub.first != nullptr) {
				b = new MergeTree<H>();
				b->ch[0] = sub.first;
				b->update();
			}
			return {b, a};
		}
	}

	static void recDelete(MergeTree<H>* t) {
		if (! t) return;
		MergeTree<H-1>::recDelete(t->ch[0]);
		MergeTree<H-1>::recDelete(t->ch[1]);
	}
};
template<>
struct MergeTree<-1> {
	// No data :)
	MergeTree() {}
	MergeTree(int v) {}
	static int getSize(MergeTree<-1>* t) { return t != nullptr; };

	void apply(uint t0, uint t1) {}
	void push() {}
	void update() {}

	static MergeTree<-1>* merge(MergeTree<-1>* a, MergeTree<-1>* b) {
		if (! a) return b;
		else if (b) delete b;
		return a;
	}
	static pair<MergeTree<-1>*, MergeTree<-1>*> split(MergeTree<-1>* a, uint v) {
		return {nullptr, a};
	}
	static void recDelete(MergeTree<-1>* t) {
		if (t) delete t;
	}
};


template<int H>
void andTree(MergeTree<H>* t, uint x) {
	if (t == nullptr) return;

	bool cont = 0;
	for (int j = 0; j <= H; ++j) cont |= ((! (x & (1 << j))) && (t->branch_cou[j] > 0));
	if (! cont) t->apply(0, x);
	else {
		t->push();
		if (! (x & (1 << H))) {
			t->ch[0] = MergeTree<H-1>::merge(t->ch[0], t->ch[1]);
			t->ch[1] = nullptr;
		}
		andTree<H-1>(t->ch[0], x);
		andTree<H-1>(t->ch[1], x);
		t->update();
	}
}
template<>
void andTree<-1>(MergeTree<-1>* t, uint x) { return; }


template<int H>
void orTree(MergeTree<H>* t, uint x) {
	if (t == nullptr) return;

	bool cont = 0;
	for (int j = 0; j <= H; ++j) cont |= ((x & (1 << j)) && (t->branch_cou[j] > 0));
	if (! cont) {
		t->apply(x, -1);
	} else {
		t->push();
		if (x & (1 << H)) {
			t->ch[1] = MergeTree<H-1>::merge(t->ch[0], t->ch[1]);
			t->ch[0] = nullptr;
		}
		orTree<H-1>(t->ch[0], x);
		orTree<H-1>(t->ch[1], x);
		t->update();
	}
}
template<>
void orTree<-1>(MergeTree<-1>* t, uint x) { return; }


template<int H>
void printTree(MergeTree<H>* a, uint ind = 0) {
	if (a == nullptr) return;
	a->push();
	printTree<H-1>(a->ch[0], ind);
	printTree<H-1>(a->ch[1], ind | (1 << H));
}
template<>
void printTree(MergeTree<-1>* a, uint ind) {
	if (a != nullptr) cerr << ind << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	

	// Numbers up to 2^20
	// 1. AND all a_i with L <= a_i <= R with x
	// 2. OR all a_i with L <= a_i <= R with x
	// 3. XOR all a_i with L <= a_i <= R with x
	// 4. Count DISTINCT a_i with L <= a_i <= R
	
	const int H = 21;
	MergeTree<H>* root = nullptr;
	for (int i = 0; i < n; ++i) {
		uint v;
		cin >> v;
		root = MergeTree<H>::merge(root, new MergeTree<H>(v));
	}

	/*
	printTree<H>(root);
	cerr << '\n';
	*/

	for (int qi = 0; qi < q; ++qi) {
		uint t, a, b;
		cin >> t >> a >> b;
		++b;

		MergeTree<H> *le = nullptr, *ri = nullptr;
		tie(le, root) = MergeTree<H>::split(root, a);
		if (b < (1 << H)) tie(root, ri) = MergeTree<H>::split(root, b);

		if (t <= 3) {
			uint x;
			cin >> x;
			if (root != nullptr) {
				if (t == 1) andTree<H>(root, x);
				if (t == 2) orTree<H>(root, x);
				if (t == 3) root->apply(x, ~x);
			}
		} else {
			cout << MergeTree<H>::getSize(root) << '\n';
		}

		root = MergeTree<H>::merge(le, root);
		root = MergeTree<H>::merge(root, ri);
		
		/*
		printTree<H>(root);
		cerr << '\n';
		*/
	}
	MergeTree<H>::recDelete(root);
}