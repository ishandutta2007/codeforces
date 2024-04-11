#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100100;
const int MAXK = 200200;
 
struct Query {
	int x1, y1;
	int x2, y2;
	int id;
};

struct Event {
	int t;
	int info;
	Event(int t = 0, int info = 0) : t(t), info(info) {};
};

int n, m, k, q;
int x[MAXK], y[MAXK];
Query queries[MAXK];
bool answer[MAXK];
vector<Event> events;
int tree[4 * MAXN];

void init_tree(int v, int l, int r) {
	tree[v] = 0;
	if (l == r) {
		return;
	}
	int x = (l + r) / 2;
	init_tree(v + v, l, x);
	init_tree(v + v + 1, x + 1, r);
}

void upd(int v, int l, int r, int pos, int value) {
	if (l == r) {
		tree[v] = value;
		return;
	}
	int x = (l + r) / 2;
	if (pos <= x) {
		upd(v + v, l, x, pos, value);
	} else {
		upd(v + v + 1, x + 1, r, pos, value);
	}
	tree[v] = min(tree[v + v], tree[v + v + 1]);
}

int find_min(int v, int l, int r, int ll, int rr) {
	if (l == ll && rr == r) {
		return tree[v];
	}
	int x = (l + r) / 2;
	int result = MAXN;
	if (ll <= x) {
		result = min(result, find_min(v + v, l, x, ll, min(x, rr) ) );
	}
	if (x + 1 <= rr) {
		result = min(result, find_min(v + v + 1, x + 1, r, max(x + 1, ll), rr) );
	}
	return result;
}

void process() {
	events.clear();
	init_tree(1, 1, m);
	for (int i = 0; i < k; i++) {
		events.push_back(Event(x[i], i));
	}
	for (int i = 0; i < q; i++) {
		int t = queries[i].x2;
		events.push_back(Event(t, k + i));
	}
	sort(events.begin(), events.end(), 
		[](Event a, Event b) {
			return make_pair(a.t, a.info) < make_pair(b.t, b.info);
		});
	for (Event &e : events) {
		if (e.info < k) {
			int id = e.info;
			upd(1, 1, m, y[id], x[id]);
			// cerr << "Point " << id + 1 << " " << y[id] << " " << x[id] << " added\n";
		} else {
			int id = e.info - k;
			int x1 = queries[id].x1;
			int y1 = queries[id].y1;
			int y2 = queries[id].y2;
			// cerr << "Rect " << id + 1 << " " << find_min(1, 1, m, y1, y2) << "\n";
			if (find_min(1, 1, m, y1, y2) >= x1) {
				answer[id] = true;
			}
		}
	}
}

void solve() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		queries[i].x1 = x1;
		queries[i].y1 = y1;
		queries[i].x2 = x2;
		queries[i].y2 = y2;
		queries[i].id = i;
		answer[i] = false;
	}
	process();
	swap(n, m);
	for (int i = 0; i < k; i++) {
		swap(x[i], y[i]);
	}
	for (int i = 0; i < q; i++) {
		swap(queries[i].x1, queries[i].y1);
		swap(queries[i].x2, queries[i].y2);
	}
	process();
	for (int i = 0; i < q; i++) {
		if (answer[i]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}