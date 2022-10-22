#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 150005;
const int Maxt = 524280;

struct node {
    double st, en, best;
    node(double st = 0.0, double en = 0.0, double best = 0.0): st(st), en(en), best(best) {}
};

int n, m, c;
int x[Maxn];
double S[Maxn];
node stree[Maxt];
double res;

void Create(int v, int l, int r)
{
    if (l == r) {
        double smal = max(0.0, S[r + 1] - S[l]);
        stree[v] = node(smal, smal, smal);
    } else {
        int mid = l + r >> 1, lc = 2 * v, rc = 2 * v + 1;
        Create(lc, l, mid); Create(rc, mid + 1, r);
        double st = max(stree[lc].st, S[mid + 1] - S[l] + stree[rc].st),
               en = max(stree[rc].en, stree[lc].en + S[r + 1] - S[mid + 1]),
               best = max(max(stree[lc].best, stree[rc].best), stree[lc].en + stree[rc].st);
        stree[v] = node(st, en, best);
    }
}

node getNode(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return stree[v];
    else {
        int mid = l + r >> 1, lc = 2 * v, rc = 2 * v + 1;
        if (a <= mid && mid < b) {
            node n = getNode(lc, l, mid, a, mid), m = getNode(rc, mid + 1, r, mid + 1, b);
            double st = max(n.st, S[mid + 1] - S[l] + m.st),
                   en = max(m.en, n.en + S[r + 1] - S[mid + 1]),
                   best = max(max(n.best, m.best), n.en + m.st);
            return node(st, en, best);
        }
        if (a <= mid) return getNode(lc, l, mid, a, b);
        return getNode(rc, mid + 1, r, a, b);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    S[0] = 0.0;
    for (int i = 1; i < n; i++) {
        int p; scanf("%d", &p);
        S[i] = S[i - 1] + double(x[i] - x[i - 1]) / 2.0 - double(p) / 100.0 * double(c);
    }
    Create(1, 0, n - 2);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        res += getNode(1, 0, n - 2, a - 1, b - 2).best;
    }
    printf("%.9lf\n", res);
    return 0;
}