#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

struct segtree {
    vector <int> sum;
    vector <ii> mn;
    int n;
    segtree() {}
    void Union(int v) {
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }
    void Create(int v, int l, int r, const vector <set <int> > &V) {
        if (l == r) {
            sum[v] = V[l].size();
            mn[v] = ii(V[l].size(), l);
        } else {
            int m = l + r >> 1;
            Create(2 * v, l, m, V);
            Create(2 * v + 1, m + 1, r, V);
            Union(v);
        }
    }
    segtree(const vector <set <int> > &V) {
        n = V.size();
        int m = 1;
        while (m <= 4 * n) m *= 2;
        sum.resize(m);
        mn.resize(m);
        Create(1, 0, n - 1, V);
    }
    ii getMin(int v, int l, int r, int a, int b) {
        if (l == a && r == b) return mn[v];
        else {
            int m = l + r >> 1;
            if (b <= m) return getMin(2 * v, l, m, a, b);
            if (m + 1 <= a) return getMin(2 * v + 1, m + 1, r, a, b);
            return min(getMin(2 * v, l, m, a, m), getMin(2 * v + 1, m + 1, r, m + 1, b));
        }
    }
    ii getMin(int a, int b) { return getMin(1, 0, n - 1, a, b); }
    int getSum(int v, int l, int r, int a, int b) {
        if (l == a && r == b) return sum[v];
        else {
            int m = l + r >> 1;
            if (b <= m) return getSum(2 * v, l, m, a, b);
            if (m + 1 <= a) return getSum(2 * v + 1, m + 1, r, a, b);
            return getSum(2 * v, l, m, a, m) + getSum(2 * v + 1, m + 1, r, m + 1, b);
        }
    }
    int getSum(int a, int b) { return getSum(1, 0, n - 1, a, b); }
    void Add(int v, int l, int r, int x, int delt) {
        if (l == r) {
            sum[v] += delt;
            mn[v].first += delt;
        } else {
            int m = l + r >> 1;
            if (x <= m) Add(2 * v, l, m, x, delt);
            else Add(2 * v + 1, m + 1, r, x, delt);
            Union(v);
        }
    }
    void Add(int x, int delt) { Add(1, 0, n - 1, x, delt); }
};

int n;
int X[Maxn], Y[Maxn];
vector <int> seq;

int Solve(const vector <int> &seq)
{
    vector <int> unX, unY;
    int all = seq.size();
    vector <set <int> > Sx, Sy;
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i];
        unX.push_back(X[ind]);
        unX.push_back(X[ind] + 1);
        unY.push_back(Y[ind]);
        unY.push_back(Y[ind] + 1);
    }
    sort(unX.begin(), unX.end()); unX.erase(unique(unX.begin(), unX.end()), unX.end());
    sort(unY.begin(), unY.end()); unY.erase(unique(unY.begin(), unY.end()), unY.end());
    Sx.resize(unX.size()); Sy.resize(unY.size());
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i];
        int nx = lower_bound(unX.begin(), unX.end(), X[ind]) - unX.begin();
        int ny = lower_bound(unY.begin(), unY.end(), Y[ind]) - unY.begin();
        Sx[nx].insert(ind);
        Sy[ny].insert(ind);
    }
    segtree stX(Sx);
    segtree stY(Sy);
    int lx = 0, rx = int(unX.size()) - 1;
    int ly = 0, ry = int(unY.size()) - 1;
    int res = 0;
    while (true) {
        while (Sx[lx].empty()) lx++;
        while (Sx[rx].empty()) rx--;
        ii got = stX.getMin(lx, rx);
        if (got.first == 0) {
            int L, R;
            int pnt = got.second;
            int lef = stX.getSum(lx, pnt);
            if (lef <= all - lef) {
                L = lx, R = pnt;
                all -= lef;
            } else {
                L = pnt, R = rx;
                all -= (all - lef);
            }
            vector <int> nxt;
            for (int i = L; i <= R; i++) {
                stX.Add(i, -int(Sx[i].size()));
                while (!Sx[i].empty()) {
                    int ind = *Sx[i].begin();
                    Sx[i].erase(Sx[i].begin());
                    int ny = lower_bound(unY.begin(), unY.end(), Y[ind]) - unY.begin();
                    Sy[ny].erase(ind);
                    stY.Add(ny, -1);
                    nxt.push_back(ind);
                }
            }
            res += Solve(nxt);
            continue;
        }
        while (Sy[ly].empty()) ly++;
        while (Sy[ry].empty()) ry--;
        got = stY.getMin(ly, ry);
        if (got.first == 0) {
            int L, R;
            int pnt = got.second;
            int lef = stY.getSum(ly, pnt);
            if (lef <= all - lef) {
                L = ly, R = pnt;
                all -= lef;
            } else {
                L = pnt, R = ry;
                all -= (all - lef);
            }
            vector <int> nxt;
            for (int i = L; i <= R; i++) {
                stY.Add(i, -int(Sy[i].size()));
                while (!Sy[i].empty()) {
                    int ind = *Sy[i].begin();
                    Sy[i].erase(Sy[i].begin());
                    int nx = lower_bound(unX.begin(), unX.end(), X[ind]) - unX.begin();
                    Sx[nx].erase(ind);
                    stX.Add(nx, -1);
                    nxt.push_back(ind);
                }
            }
            res += Solve(nxt);
            continue;
        }
        return res + 1;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        seq.push_back(i);
    }
    cout << Solve(seq) << endl;
    return 0;
}