#pragma comment (linker, "/STACK:128000000") 
//#include "testlib.h" 
#include <cstdio> 
#include <cassert> 
#include <algorithm> 
#include <iostream> 
#include <memory.h> 
#include <string> 
#include <vector> 
#include <set> 
#include <map> 
#include <cmath> 
#include <bitset> 
//#include <unordered_map> 
//#include <unordered_set> 
#include <ctime> 
#include <stack> 
#include <queue> 
using namespace std;
//#define FILENAME "" 
#define mp make_pair 
#define all(a) a.begin(), a.end() 
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1; 

bool doing = true;

int main() {
#ifdef room81
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else 
	//freopen("input.txt", "r", stdin); 
	//freopen("output.txt", "w", stdout); 
	//freopen(FILENAME".in", "r", stdin); 
	//freopen(FILENAME ".out", "w", stdout); 
#endif 
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": "; 
		solve();
		//++timer; 
	}

#ifdef room81
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif 

	return 0;
}

//BE CAREFUL: IS INT REALLY INT? 

//#define int li 

void precalc() {


}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li

struct _node;

typedef _node *node;

struct _node {
	int cnt, prior;
	_node* l;
	_node* r;
	_node* p;
	li val;
	li add;
	int lastNull;
	int lastNullToPush;
	_node() :val(0), add(0), lastNull(0), lastNullToPush(0) {
		prior = (rand() << 16) | rand();
		cnt = 1;
		l = nullptr;
		r = nullptr;
		p = nullptr;
	}
	inline void push() {
		if (l) {
			l->add += add;
			l->lastNullToPush = max(l->lastNullToPush, lastNullToPush);
		}
		if (r) {
			r->add += add;
			r->lastNullToPush = max(r->lastNullToPush, lastNullToPush);
		}
		lastNull = max(lastNull, lastNullToPush);
		val += add;
		add = 0;
		lastNullToPush = 0;
	}
	inline void recalc() {
		p = nullptr;
		cnt = 1 + Cnt(l) + Cnt(r);
		if (l) {
			l->p = this;
		}
		if (r) {
			r->p = this;
		}
	}

	static int Cnt(_node* v) {
		if (!v)
			return 0;
		return v->cnt;
	}

	node merge(node l, node r) {
		if (!l)
			return r;
		if (!r)
			return l;
		if (l->prior < r->prior) {
			l->push();
			l->r = merge(l->r, r);
			l->recalc();
			return l;
		}
		else {
			r->push();
			r->l = merge(l, r->l);
			r->recalc();
			return r;
		}
	}

	inline void split(node v, int key, node& l, node& r) {
		l = r = nullptr;
		if (!v)
			return;
		v->push();
		int cur = Cnt(v->l);
		if (cur < key) {
			l = v;
			split(l->r, key - cur - 1, l->r, r);
			l->recalc();
		}
		else {
			r = v;
			split(r->l, key, l, r->l);
			r->recalc();
		}
	}

	node push_back(node other) {
		return merge(this, other);
	}

	int getLastZero(node v) {
		int res = v->lastNull;
		while (v) {
			res = max(res, v->lastNullToPush);
			v = v->p;
		}
		return res;
	}

	li getActualVal(_node* v) {
		li res = v->val;
		while (v) {
			res += v->add;
			v = v->p;
		}
		return res;
	}

};

enum {
	UNI_MERGE = 0,
	WAR_MERGE = 1,
	UNI_ADD = 2,
	WAR_ZERO = 3,
	QUERY = 4
};

struct Query {
	int type;
	int q, w;
	int num;
	void scan() {
		char c;
		cin >> c;
		switch (c) {
		case 'U':
			type = UNI_MERGE;
			cin >> q >> w;
			--q; --w;
			break;
		case 'M':
			type = WAR_MERGE;
			cin >> q >> w;
			--q; --w;
			break;
		case 'A':
			type = UNI_ADD;
			cin >> q;
			--q;
			break;
		case 'Z':
			type = WAR_ZERO;
			cin >> q;
			--q;
			break;
		case 'Q':
			type = QUERY;
			cin >> q;
			--q;
			break;
		default:
			assert(false);
		}
	}
};

vector<int> dsu[2];

int findSet(int id, int v) {
	if (dsu[id][v] == v) {
		return v;
	}
	return dsu[id][v] = findSet(id, dsu[id][v]);
}

void merge(int id, int q, int w) {
	dsu[id][w] = q;
}

void solve() {
	int n, Q;
	cin >> n >> Q;

	vector<Query> ask;
	vector<vector<pair<int, int>>> askNum(Q);

	for (int i = 0; i < Q; ++i) {
		Query cur;
		cur.scan();
		cur.num = i;
		if (cur.type == QUERY) {
			askNum[i].push_back(mp(cur.q, i));
		}
		ask.push_back(cur);
	}

	vector<li> res(Q, 0);

	for (int dom = 1; dom >= -1; dom -= 2) {
		vector<int> sizes(n, 1);
		vector<node> uni(n), war(n);
		vector<node> uniRoots(n), warRoots(n);
		for (int i = 0; i < n; ++i) {
			uni[i] = new _node();
			war[i] = new _node();
			uniRoots[i] = uni[i];
			warRoots[i] = war[i];
		}
		
		for (int w = 0; w < 2; ++w) {
			dsu[w].resize(n);
			for (int i = 0; i < n; ++i) {
				dsu[w][i] = i;
			}
		}

		for (int i = 0; i < Q; ++i) {
			for (auto item : askNum[i]) {
				int id = item.first;
				li curRes = uni[id]->getActualVal(uni[id]);
				res[item.second] += dom * curRes;
			}
			askNum[i].clear();

			auto& curAsk = ask[i];

			if (curAsk.type == QUERY) {
				int id = curAsk.q;
				int lastZero = war[id]->getLastZero(war[id]);
				askNum[lastZero].push_back(mp(id, i));
			}

			if (curAsk.type == UNI_MERGE) {
				uniRoots[curAsk.q] = uniRoots[curAsk.q]->push_back(uniRoots[curAsk.w]);
				sizes[curAsk.q] += sizes[curAsk.w];
				merge(0, curAsk.q, curAsk.w);
			}

			if (curAsk.type == WAR_MERGE) {
				warRoots[curAsk.q] = warRoots[curAsk.q]->push_back(warRoots[curAsk.w]);
				merge(1, curAsk.q, curAsk.w);
			}

			if (curAsk.type == UNI_ADD) {
				uniRoots[curAsk.q]->add += sizes[curAsk.q];
			}

			if (curAsk.type == WAR_ZERO) {
				warRoots[curAsk.q]->lastNullToPush = i;
			}
		}
	}

	for (int i = 0; i < Q; ++i) {
		if (ask[i].type == QUERY) {
			cout << res[i] << "\n";
		}
	}
}