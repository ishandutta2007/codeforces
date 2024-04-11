#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


int h, q;

struct node {
	node *l, *r;
	ll sum;
	ll x;
	node() {
		l = r = 0;
		sum = x = 0;
	}
};

void upd(node *g, int v, int h, int d) {
	g->sum += d;
	if (h == 0) {
		g->x += d;
		return;
	}
	if (v & 1) {
		if (!g->r)
			g->r = new node();
		upd(g->r, v >> 1, h - 1, d);
	}
	else {
		if (!g->l)
			g->l = new node();
		upd(g->l, v >> 1, h - 1, d);
	}
}

double run(node *g, ll mx) {
	if (g->l) {
		if (g->r) {
			if (g->l->sum >= g->r->sum) {
				double ans = max(mx, g->l->sum + g->x) / 2.0;
				ans += run(g->l, max(mx, g->x + g->r->sum)) / 2.0;
				return ans;
			}
			else {
				double ans = max(mx, g->r->sum + g->x) / 2.0;
				ans += run(g->r, max(mx, g->x + g->l->sum)) / 2.0;
				return ans;
			}
		}
		else {
			double ans = max(mx, g->l->sum + g->x) / 2.0;
			ans += run(g->l, max(mx, g->x)) / 2.0;
			return ans;
		}
	}
	else {
		if (g->r) {
			double ans = max(mx, g->r->sum + g->x) / 2.0;
			ans += run(g->r, max(mx, g->x)) / 2.0;
			return ans;
		}
		else {
			return max(mx, g->sum);
		}
	}
}


node *root;

char buf[1000];

int main() {
	scanf("%d%d", &h, &q);
	root = new node();
	for (int i = 0; i < q; ++i) {
		scanf(" %s", buf);
		if (buf[0] == 'a') {
			int v, a;
			scanf("%d%d", &v, &a);
			int ans = 0;
			int len = 0;
			while (v)
				ans = ans * 2 + (v & 1), ++len, v >>= 1;
			upd(root, ans >> 1, len - 1, a);
		}
		else {
			printf("%f\n", run(root, 0));
		}
	}
	return 0;
}