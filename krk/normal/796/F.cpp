#include <bits/stdc++.h>
using namespace std;

typedef pair <vector <int>, bool> vib;

const int Maxn = 300005;
const int Maxm = 2097152;
const int Maxb = 30;
const int lim = 1000000000;

int mn[Maxm];
int mx[Maxm];
int n, m;
bool tk[Maxn];
map <int, vib> M;
int res[Maxn];

void createMin(int v, int l, int r)
{
    mn[v] = lim;
    if (l < r) {
        int m = l + r >> 1;
        createMin(2 * v, l, m);
        createMin(2 * v + 1, m + 1, r);
    }
}

void updateMin(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) mn[v] = min(mn[v], val);
    else {
        int m = l + r >> 1;
        if (a <= m) updateMin(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) updateMin(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
    }
}

int getMin(int v, int l, int r, int x)
{
    int res = mn[v];
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) res = min(res, getMin(2 * v, l, m, x));
        else res = min(res, getMin(2 * v + 1, m + 1, r, x));
    }
    return res;
}

void updateMax(int v, int l, int r, int x, int val)
{
    if (l == r) mx[v] = val;
    else {
        int m = l + r >> 1;
        if (x <= m) updateMax(2 * v, l, m, x, val);
        else updateMax(2 * v + 1, m + 1, r, x, val);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
}

int getMax(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return mx[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return getMax(2 * v, l, m, a, b);
        if (m + 1 <= a) return getMax(2 * v + 1, m + 1, r, a, b);
        return max(getMax(2 * v, l, m, a, m), getMax(2 * v + 1, m + 1, r, m + 1, b));
    }
}

void setInt(int x, int ind)
{
    auto it = M.find(x);
    if (it == M.end()) {
        vector <int> tmp = {ind};
        M.insert(make_pair(x, vib(tmp, false)));
    }
    else it->second.first.push_back(ind);
}

void setBool(int x)
{
    auto it = M.find(x);
    if (it == M.end()) {
        vector <int> tmp;
        M.insert(make_pair(x, vib(tmp, true)));
    }
    else it->second.second = true;
}

int main()
{
    scanf("%d %d", &n, &m);
    createMin(1, 1, n);
    for (int i = 0; i < m; i++) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            int mymx = getMax(1, 1, n, l, r);
            if (mymx > x) { printf("NO\n"); return 0; }
            if (mymx < x) setBool(x);
            updateMin(1, 1, n, l, r, x);
        } else {
            int k, d; scanf("%d %d", &k, &d);
            if (!tk[k]) setInt(getMin(1, 1, n, k), k);
            tk[k] = true;
            updateMax(1, 1, n, k, d);
        }
    }
    for (int i = 1; i <= n; i++) if (!tk[i])
        setInt(getMin(1, 1, n, i), i);
    int allres = 0;
    auto it = M.end();
    while (it != M.begin()) {
        it--;
        if (it->second.second)
            if (it->second.first.empty()) { printf("NO\n"); return 0; }
            else {
                int ind = it->second.first.back(); it->second.first.pop_back();
                res[ind] = it->first;
                allres |= res[ind];
            }
    }
    it = M.end();
    while (it != M.begin()) {
        it--;
        while (!it->second.first.empty()) {
            int ind = it->second.first.back(); it->second.first.pop_back();
            int num = it->first;
            for (int b = Maxb - 1; b >= 0; b--)
                if ((1 << b) <= num)
                    if (!(allres & 1 << b)) {
                        res[ind] |= 1 << b;
                        allres |= 1 << b;
                        num ^= (1 << b);
                    } else {
                        res[ind] |= (1 << b) - 1;
                        allres |= (1 << b) - 1;
                        break;
                    }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}