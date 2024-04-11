#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

struct SegmnetTree {
	
	vec< vec< int > > t;
	int n, m;

	SegmnetTree() {
		n = m = 0;
	}

	SegmnetTree(int nn, int mm) {
		n = nn;
		m = mm;
		t.resize(4 * nn, vec< int >(4 * mm, inf));
	}

	void put_j(int vi, int li, int ri, int vj, int lj, int rj, int i, int j, int x) {
		if(lj == rj) {
			if(li == ri) {
				t[vi][vj] = x;
			}else {
				t[vi][vj] = min(t[vi * 2 + 1][vj], t[vi * 2 + 2][vj]);
			}
		}else {
			int mj = (lj + rj) / 2;
			if(j <= mj) put_j(vi, li, ri, vj * 2 + 1, lj, mj, i, j, x);
			else put_j(vi, li, ri, vj * 2 + 2, mj + 1, rj, i, j, x);
			t[vi][vj] = min(t[vi][vj * 2 + 1], t[vi][vj * 2 + 2]);
		}
	}

	void put_i(int v, int li, int ri, int i, int j, int x) {
		if(li != ri) {
			int mi = (li + ri) / 2;
			if(i <= mi) put_i(v * 2 + 1, li, mi, i, j, x);
			else put_i(v * 2 + 2, mi + 1, ri, i, j, x);
		}
		put_j(v, li, ri, 0, 0, m - 1, i, j, x);
	}

	void put(int i, int j, int x) {
		put_i(0, 0, n - 1, i, j, x);
	}

	int get_j(int vi, int vj, int tlj, int trj, int lj, int rj) {
		if(lj <= tlj && trj <= rj) return t[vi][vj];
		else {
			int mj = (tlj + trj) / 2, res = inf;
			if(lj <= mj) res = min(res, get_j(vi, vj * 2 + 1, tlj, mj, lj, rj));
			if(rj > mj) res = min(res, get_j(vi, vj * 2 + 2, mj + 1, trj, lj, rj));
			return res;
		}
	}

	int get_i(int v, int tli, int tri, int li, int ri, int lj, int rj) {
		if(li <= tli && tri <= ri) return get_j(v, 0, 0, m - 1, lj, rj);
		else {
			int mi = (tli + tri) / 2, res = inf;
			if(li <= mi) res = min(res, get_i(v * 2 + 1, tli, mi, li, ri, lj, rj));
			if(ri > mi) res = min(res, get_i(v * 2 + 2, mi + 1, tri, li, ri, lj, rj));
			return res;
		}
	}

	int get(int li, int lj, int ri, int rj) {
		if(li >= n || lj >= m) return inf;
		else return get_i(0, 0, n - 1, li, ri, lj, rj);
	}
};

bool solve() {

	int n, m, p;

	scanf("%d %d %d", &n, &m, &p);

	if(p == 1) {
		printf("0\n");
		return true;
	}

	/*SegmnetTree st(n, m);
	
	for(;;) {
		char ty;
		cin >> ty;
		int i, j, x, li, ri, lj, rj;
		if(ty == '=') {
			cin >> i >> j >> x;
			st.put(i, j, x);
		}else {
			cin >> li >> lj >> ri >> rj;
			cout << st.get(li, lj, ri, rj) << '\n';
		}
	}*/

	vec< vec< pii > > pos(p + 1);

	pos[0].push_back(mp(0, 0));

	for(int x, i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			scanf("%d", &x);
			pos[x].push_back(mp(i, j));
		}
	}

	SegmnetTree st1(n, m), st2(n, m), st3(n, m), st4(n, m);

	vec< vec< int > > ans(n, vec< int >(m));

	for(auto cur : pos[1]) {
		int I, J, dp;
		tie(I, J) = cur;
		dp = I + J;
		st1.put(I, J, dp - I - J);
		st2.put(I, J, dp - I + J);
		st3.put(I, J, dp + I - J);
		st4.put(I, J, dp + I + J);
		ans[I][J] = dp;
	}

	for(int it, dp, I, J, x = 2; x <= p;x++) {
		vec< int > mas;
		for(auto cur : pos[x]) {
			tie(I, J) = cur;
			dp = inf;

			/*int v1, v2, v3, v4;

			v1 = I + J + st1.get(0, 0, I, J);
			v2 = I - J + st2.get(0, J + 1, I, m - 1);
			v3 = J - I + st3.get(I + 1, 0, n - 1, J);
			v4 = -I- J + st4.get(I + 1, J + 1, n - 1, m - 1);*/

			dp = min(dp, I + J + st1.get(0, 0, I, J));
			dp = min(dp, I - J + st2.get(0, J + 1, I, m - 1));
			dp = min(dp, J - I + st3.get(I + 1, 0, n - 1, J));
			dp = min(dp, -I- J + st4.get(I + 1, J + 1, n - 1, m - 1));
			ans[I][J] = dp;
			mas.push_back(dp);

			//cout << I << ", " << J << " : {" << v1 << ", " << v2 << ", " << v3 << ", " << v4 << "}\n";

			if(x == p) {
				printf("%d\n", dp);
				return true;
			}
		}
		for(auto cur : pos[x - 1]) {
			tie(I, J) = cur;
			st1.put(I, J, inf);
			st2.put(I, J, inf);
			st3.put(I, J, inf);
			st4.put(I, J, inf);
		}
		it = 0;
		for(auto cur : pos[x]) {
			dp = mas[it++];
			tie(I, J) = cur;
			st1.put(I, J, dp - I - J);
			st2.put(I, J, dp - I + J);
			st3.put(I, J, dp + I - J);
			st4.put(I, J, dp + I + J);
		}
	}

	/*for(auto i : ans) {
		for(auto j : i) cout << j << ' ';
		cout << '\n';
	}*/

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}