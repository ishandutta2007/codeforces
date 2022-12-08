#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
using namespace std;

// code credit : https://github.com/niklasb/contest-algos/
// blob/master/convex_hull/dynamic.cpp
using line_t = long double;
const line_t is_query = -1e100;

struct Line {
	line_t m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
		if (rhs.b != is_query) return m < rhs.m;
		const Line* s = succ();
		if (!s) return 0;
		line_t x = rhs.m;
		return b - s->b < (s->m - m) * x;
	}
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
	bool bad(iterator y) {
		auto z = next(y);
		if (y == begin()) {
			if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b;
		}
		auto x = prev(y);
		if (z == end()) return y->m == x->m && y->b <= x->b;
		return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
	}
	void insert_line(line_t m, line_t b) {
		auto y = insert({ m, b });
		y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		if (bad(y)) { erase(y); return; }
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	line_t query(line_t x) {
		Line u = { x, is_query };
		auto l = *lower_bound(u);
		return l.m * x + l.b;
	}
}* hi[100100];

long long A[100100],B[100100],W[100100];
vector<int> G[100100];

void go(int x, int l)
{
	hi[x] = new HullDynamic();

	for (auto &y : G[x]) if (y != l){
		go(y,x);
		if (hi[x]->size() < hi[y]->size()){
			swap(hi[x],hi[y]);
		}
		for (auto I = hi[y]->begin(); I != hi[y]->end(); I++){
			hi[x]->insert_line(I->m,I->b);
		}
		delete hi[y];
	}

	if (l && G[x].size() == 1) W[x] = 0;
	else W[x] = floor(-hi[x]->query(A[x])+0.3);
	hi[x]->insert_line(-B[x],-W[x]);
}

int main()
{
	int N;
	scanf ("%d",&N);
	for (int i=1;i<=N;i++) scanf ("%lld",&A[i]);
	for (int i=1;i<=N;i++) scanf ("%lld",&B[i]);
	for (int i=1;i<N;i++){
		int x,y; scanf ("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	go(1,0);

	for (int i=1;i<=N;i++) printf ("%lld ",W[i]);

	return 0;
}