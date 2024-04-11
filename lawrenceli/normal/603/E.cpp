#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>
#include <cassert>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 100100;
const int maxm = 300100;
const int inf = 1e9 + 5;

int n, q;
piii ar[maxm];
int par[maxn], sze[maxn], tot;
int ans[maxm];

int getpar(int a) {
    while (par[a] != a) a = par[a];
    return a;
}

struct op {
    int a, b, pa, sb, d;
} ops[maxm];
int osze;

void merge(int a, int b) {
    a = getpar(a), b = getpar(b);
    if (sze[a] > sze[b]) swap(a, b);
    ops[osze++] = (op){a, b, par[a], sze[b], 0};
    if (a == b) return;
    par[a] = b;
    sze[b] += sze[a];
    if ((sze[a] & 1) && !(sze[b] & 1)) tot -= 2, ops[osze - 1].d = 2;
}

void undo() {
    assert(osze);
    op o = ops[osze - 1];
    par[o.a] = o.pa;
    sze[o.b] = o.sb;
    tot += o.d;
    osze--;
}

bool cmp(int a, int b) {
    return ar[a].B < ar[b].B;
}

void go(int l, int r, int lo, int hi, vector<int> w = vector<int>()) {
    if (l >= r) return;
    int m = (l + r) / 2;

    vector<int> v = w;
    for (int i = l; i <= m; i++)
        if (ar[i].B <= hi)
            v.push_back(i);
    sort(v.begin(), v.end(), cmp);

    int mid = lo;
    int mcnt = 0;
    if (tot) {
        for (int i : v) {
            merge(ar[i].A.A, ar[i].A.B);
            mid = max(mid, ar[i].B);
            mcnt++;
            if (!tot) break;
        }
    }

    if (tot) mid = hi;
    ans[m] = mid;

    for (int i = 0; i < mcnt; i++) undo();

    mcnt = 0;
    v = vector<int>();
    for (int i = l; i <= m; i++)
        if (ar[i].B <= lo)
            merge(ar[i].A.A, ar[i].A.B), mcnt++;
        else if (ar[i].B <= hi)
            v.push_back(i);

    for (int i : w)
        if (ar[i].B <= mid)
            v.push_back(i);
    
    go(m + 1, r, lo, mid, v);

    for (int i = 0; i < mcnt; i++) undo();
    mcnt = 0;

    v = vector<int>();
    for (int i : w)
        if (ar[i].B <= mid)
            merge(ar[i].A.A, ar[i].A.B), mcnt++;
        else v.push_back(i);

    go(l, m, mid, hi, v);

    for (int i = 0; i < mcnt; i++) undo();
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> ar[i].A.A >> ar[i].A.B >> ar[i].B;
        ar[i].A.A --, ar[i].A.B --;
    }

    for (int i = 0; i < n; i++) par[i] = i, sze[i] = 1;
    tot = n;
    go(0, q, 0, inf);

    for (int i = 0; i < q; i++)
        if (ans[i] == inf) cout << "-1\n";
        else cout << ans[i] << '\n';
}