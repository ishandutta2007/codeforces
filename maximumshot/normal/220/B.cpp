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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

struct fen {
	int n;
	vec< int > a;

	fen() {
		n = 0;
	}

	fen(int _n) {
		n = _n;
		a.resize(n + 1);
	}

	void add(int l, int r, int k) {
		for(int cur = l;cur <= n;cur |= (cur + 1)) a[cur] += k;
		for(int cur = r + 1;cur <= n;cur |= (cur + 1)) a[cur] -= k;
	}

	int ask(int p) {
		int ans = 0;
		for(int cur = p;cur > 0;cur = (cur & (cur + 1)) - 1) ans += a[cur];
		return ans;
	}
};

const int SQRT = 330;

bool solve() {
	
	int n, m;

	scanf("%d %d", &n, &m);

	vec< int > a(n + 1);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}

	vec< pair< pii, int > > q(m);
	
	for(int l, r, i = 0;i < m;i++) {
		scanf("%d %d", &l, &r);
		q[i] = mp(mp(l, r), i);
	}

	sort(ALL(q), [](const pair< pii, int > & p1, const pair< pii, int > & p2) {
		if(p1.first.first / SQRT != p2.first.first / SQRT) return p1.first.first / SQRT < p2.first.first / SQRT;
		else return p1.first.second < p2.first.second;
	});

	int ql, qr, value = 0;
	ql = 0, qr = -1;

	vec< int > c(n + 1), ans(m);

	for(int i = 0;i < m;i++) {
		int l, r, id;
		tie(l, r) = q[i].first;
		id = q[i].second;
		while(qr < r) {
			if(a[qr + 1] <= n) {
				c[a[qr + 1]]++;
				if(c[a[qr + 1]] == a[qr + 1]) value++;
				else if(c[a[qr + 1]] == a[qr + 1] + 1) value--;
			}
			qr++;
		}
		while(ql > l) {
			if(a[ql - 1] <= n) {
				c[a[ql - 1]]++;
				if(c[a[ql - 1]] == a[ql - 1]) value++;
				else if(c[a[ql - 1]] == a[ql - 1] + 1) value--;
			}
			ql--;
		}
		while(qr > r) {
			if(a[qr] <= n) {
				c[a[qr]]--;
				if(c[a[qr]] == a[qr]) value++;
				else if(c[a[qr]] == a[qr] - 1) value--;
			}
			qr--;
		}
		while(ql < l) {
			if(a[ql] <= n) {
				c[a[ql]]--;
				if(c[a[ql]] == a[ql]) value++;
				else if(c[a[ql]] == a[ql] - 1) value--;
			}
			ql++;
		}
		ans[id] = value;
	}

	for(int i = 0;i < m;i++) printf("%d\n", ans[i]);

	return true;
}


int main() {

	//while(solve());
	solve();

	return 0;
}