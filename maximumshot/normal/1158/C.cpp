#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 5e5 + 5;

int n;
int nxt[N];
int perm[N];
int tree[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = nxt[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
}

int get_max(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
        return tree[v];
    } else {
        int tm = (tl + tr) >> 1;
        int res = -1;
        if (l <= tm) {
            res = max(res, get_max(v << 1, tl, tm, l, r));
        }
        if (r > tm) {
            res = max(res, get_max(v << 1 | 1, tm + 1, tr, l, r));
        }
        return res;
    }
}

mt19937 rnd(time(NULL));

void gen() {
    n = 10;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    shuffle(p.begin() + 1, p.end(), rnd);
    for (int i = n; i >= 1; i--) {
        int j = i + 1;
        while (j <= n && p[j] < p[i]) j++;
        nxt[i] = j;
        if (rnd() % 4 == 0) nxt[i] = i + 1;
    }
}

void work(int L, int R, int &cur) {
    if (L > R) return;
    vector<int> way;
    for (int x = L; ; x = nxt[x]) {
        way.push_back(x);
        if (x > R) break;
    }
    for (int i = (int)way.size() - 2; i >= 0; i--) {
        perm[way[i]] = cur--;
    }
    for (int i = 0; i + 1 < (int)way.size(); i++) {
        work(way[i] + 1, way[i + 1] - 1, cur);
    }
}

void solve() {
//    gen();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
        if (nxt[i] == -1) {
            nxt[i] = i + 1;
        }
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int j = nxt[i] - 1;
        if (i <= j) {
            if (get_max(1, 1, n, i, j) > nxt[i]) {
                cout << "-1\n";
                return;
            }
        }
    }
    int cur = n;
    work(1, n, cur);
    for (int i = 1; i <= n; i++) {
        cout << perm[i] << " ";
    }
    cout << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;

    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}