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
#include <complex>

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

const int LOG = 21;

struct RMQ {

	int n;
	vec< int > mn[LOG], mx[LOG], lg;

	RMQ(const vec< int > & a) {
		int n = (int)a.size() - 1;

		for(int i = 0;i < LOG;i++) {
			mx[i].resize(n + 1, -inf - 1);
			mn[i].resize(n + 1, +inf + 1);
		}

		mn[0] = mx[0] = a;

		for(int i = 1;i < LOG;i++) {
			for(int j = 1;j + (1 << (i - 1)) <= n;j++) {
				mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
				mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
			}
		}

		lg.resize(n + 1);

		int cur = 0;

		while((1 << cur) <= n) cur++;

		for(int i = n;i > 0;i--) {
			if((1 << cur) > i) cur--;
			lg[i] = cur;
		}
	}

	int get_max(int l, int r) {
		int _log = lg[r - l + 1];
		return max(mx[_log][l], mx[_log][r - (1 << _log) + 1]);
	}

	int get_min(int l, int r) {
		int _log = lg[r - l + 1];
		return min(mn[_log][l], mn[_log][r - (1 << _log) + 1]);	
	}

};

bool solve() {

	int n;

	scanf("%d", &n);

	vec< int > a(n + 1), b(n + 1);

	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);

	RMQ rmq_a(a), rmq_b(b);

	ll res = 0;

	for(int i = 1;i <= n;i++) {
		int bl, br, bm, L, R;

		bl = i;
		br = n;

		while(br - bl > 1) {
			bm = (bl + br) / 2;
			if(rmq_a.get_max(i, bm) < rmq_b.get_min(i, bm)) bl = bm + 1;
			else br = bm;
		}

		if(rmq_a.get_max(i, bl) == rmq_b.get_min(i, bl)) L = bl;
		else if(rmq_a.get_max(i, br) == rmq_b.get_min(i, br)) L = br;
		else continue;

		bl = i;
		br = n;

		while(br - bl > 1) {
			bm = (bl + br) / 2;
			if(rmq_a.get_max(i, bm) > rmq_b.get_min(i, bm)) br = bm - 1;
			else bl = bm;
		}

		if(rmq_a.get_max(i, br) == rmq_b.get_min(i, br)) R = br;
		else if(rmq_a.get_max(i, bl) == rmq_b.get_min(i, bl)) R = bl;
		else continue;

		res += R - L + 1;
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}