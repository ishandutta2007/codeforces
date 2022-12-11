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

const int MAXN = 200200;

struct Event {
    int x;
    int info;
    Event(int x = 0, int info = 0) : x(x), info(info) {};

    pair<int, int> get_pair() {
        return make_pair(x, info);
    }
};

bool cmp(Event a, Event b) {
    return a.get_pair() < b.get_pair();
}

struct Node {
    int value, info;
    Node() {
        value = -1;
        info = -1;
    }
};

Node fun(Node a, Node b) {
    if (a.value < b.value) {
        return b;
    } 
    return a;
}

Node tree[2][4 * MAXN];

void init(Node tree[], int v, int l, int r) {
    if (l == r) {
        tree[v] = Node();
        return;
    }
    int x = (l + r) / 2;
    init(tree, v + v, l, x);
    init(tree, v + v + 1, x + 1, r);
    tree[v] = fun(tree[v + v], tree[v + v + 1] );
}

Node get_value(Node tree[], int v, int l, int r, int ll, int rr) {
    if (l == ll && rr == r) {
        return tree[v];
    }
    Node result = Node();
    int x = (l + r) / 2;
    if (ll <= x) {
        result = fun(result, get_value(tree, v + v, l, x, ll, min(rr, x) ) );
    }
    if (x + 1 <= rr) {
        result = fun(result, get_value(tree, v + v + 1, x + 1, r, max(x + 1, ll), rr) );
    }
    return result;
}

void update(Node tree[], int v, int l, int r, int pos, int value, int info) {
    if (l == r) {
        tree[v].value = value;
        tree[v].info = info;
        return;
    }
    int x = (l + r) / 2;
    if (pos <= x) {
        update(tree, v + v, l, x, pos, value, info);
    } else {
        update(tree, v + v + 1, x + 1, r, pos, value, info);
    }
    tree[v] = fun(tree[v + v], tree[v + v + 1] );
} 

int n, m;

int l[MAXN], r[MAXN];
bool used[MAXN];
pair<int, int> buf[MAXN];
int lid[MAXN];

int a[MAXN], b[MAXN], c[MAXN];

Event e[3 * MAXN]; int h = 0;
set<pair<int, int> > s;
long long answer = 0;
int ii, jj;

void update_answer(int i, int j) {
    int ll = max(l[i], a[j] );
    int rr = min(r[i], b[j] );
    long long value = max(rr - ll, 0) * 1ll * c[j];
    if (value > answer) {
        answer = value;
        ii = i;
        jj = j;
    }
}

void solve() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l[i], &r[i] );
        e[h++] = Event(l[i], i);
        e[h++] = Event(r[i], i);
    }

    for (int i = 0; i < n; i++) {
        buf[i] = make_pair(l[i], i);
    }
    sort(buf, buf + n);
    for (int i = 0; i < n; i++) {
        lid[buf[i].second] = i;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i] );
        e[h++] = Event(b[i], n + i);
    }

    sort(e, e + h, cmp);

    init(tree[0], 1, 0, n - 1);
    init(tree[1], 1, 0, n - 1);

    for (int i = 0; i < h; i++) {
        int info = e[i].info;

        if (info < n) {
            int id = info;
            if (!used[id] ) {
                s.insert(make_pair(l[id], id) );
                used[id] = true;
            } else {
                s.erase(make_pair(l[id], id) );
                update(tree[0], 1, 0, n - 1, lid[id], r[id] - l[id], id);
                update(tree[1], 1, 0, n - 1, lid[id], r[id], id);
                used[id] = false;
            }
        } else {
            int id = info - n;
            // first case
            if (s.size() ) {
                int _i = s.begin()->second;
                update_answer(_i, id);
            }
            // second case
            int pos = lower_bound(buf, buf + n, make_pair(a[id], -1) ) - buf;
            if (pos < n) {
                Node result = get_value(tree[0], 1, 0, n - 1, pos, n - 1);
                if (result.info != -1) {
                    int _i = result.info;
                    update_answer(_i, id);
                }
            }
            // third case
            if (pos > 0) {
                Node result = get_value(tree[1], 1, 0, n - 1, 0, pos - 1);
                if (result.info != -1) {
                    int _i = result.info;
                    update_answer(_i, id);
                }
            }
        }
    }
    cout << answer << "\n";
    if (answer) {
        cout << ii + 1 << " " << jj + 1 << "\n";
    }
}

int main() {
	int cases; cases = 1;
	for (int i = 1; i <= cases; i++) {
        solve();
    }
    return 0;
}