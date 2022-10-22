#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Node {

    int h_pref = 0;
    int min_h_pref = 0;

    int h_suff = 0;
    int min_h_suff = 0;

    int res = 0;

    int pref_sum = 0;

    int h_max;
    int h_min;
};

Node merge(Node l, Node r) {
    Node res;

    res.pref_sum = l.pref_sum + r.pref_sum;
    res.h_max = max(l.h_max, r.h_max + l.pref_sum);
    res.h_min = min(l.h_min, r.h_min + l.pref_sum);

    res.h_pref = l.h_pref;
    res.min_h_pref = l.min_h_pref;

    if (res.h_pref - 2 * res.min_h_pref < r.h_pref - 2 * r.min_h_pref - l.pref_sum) {
        res.h_pref = r.h_pref + l.pref_sum;
        res.min_h_pref = r.min_h_pref + l.pref_sum;
    }

    if (res.h_pref - 2 * res.min_h_pref < (r.h_max + l.pref_sum) - 2 * l.h_min) {
        res.h_pref = (r.h_max + l.pref_sum);
        res.min_h_pref = l.h_min;
    }

    res.h_suff = l.h_suff;
    res.min_h_suff = l.min_h_suff;

    if (res.h_suff - 2 * res.min_h_suff < r.h_suff - 2 * r.min_h_suff - l.pref_sum) {
        res.h_suff = r.h_suff + l.pref_sum;
        res.min_h_suff = r.min_h_suff + l.pref_sum;
    }

    if (res.h_suff - 2 * res.min_h_suff < l.h_max - 2 * (r.h_min + l.pref_sum)) {
        res.h_suff = l.h_max;
        res.min_h_suff = r.h_min + l.pref_sum;
    }

    res.res = max(l.res, r.res);

    res.res = max(res.res, l.h_suff + r.h_max + l.pref_sum - 2 * l.min_h_suff);
    res.res = max(res.res, l.h_max - l.pref_sum + r.h_pref - 2 * r.min_h_pref);

    return res;
}

const int N = 2e5 + 5;

Node t[4 * N];

void build(int v, int tl, int tr, const string &s) {
    if (tl == tr) {
        t[v].res = 0;
        t[v].min_h_pref = s[tl] == '(' ? 1 : -1;
        t[v].min_h_suff = s[tl] == '(' ? 1 : -1;
        t[v].h_max = s[tl] == '(' ? 1 : -1;
        t[v].h_min = s[tl] == '(' ? 1 : -1;
        t[v].h_pref = s[tl] == '(' ? 1 : -1;
        t[v].h_suff = s[tl] == '(' ? 1 : -1;
        t[v].pref_sum = s[tl] == '(' ? 1 : -1;
    } else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, s);
        build(v << 1 | 1, tm + 1, tr, s);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int tl, int tr, int pos, char c) {
    if (tl == tr) {
        t[v].res = 0;
        t[v].min_h_pref = c == '(' ? 1 : -1;
        t[v].min_h_suff = c == '(' ? 1 : -1;
        t[v].h_max = c == '(' ? 1 : -1;
        t[v].h_min = c == '(' ? 1 : -1;
        t[v].h_pref = c == '(' ? 1 : -1;
        t[v].h_suff = c == '(' ? 1 : -1;
        t[v].pref_sum = c == '(' ? 1 : -1;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            update(v << 1, tl, tm, pos, c);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, c);
        }
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n >> q;

    string s;

    cin >> s;

    build(1, 0, (int)s.size() - 1, s);

    cout << t[1].res << "\n";

    for (int iter = 0; iter < q; iter++) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        if (i != j) {
            swap(s[i], s[j]);
            update(1, 0, (int)s.size() - 1, i, s[i]);
            update(1, 0, (int)s.size() - 1, j, s[j]);
        }
        cout << t[1].res << "\n";
    }

    return 0;
}