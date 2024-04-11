#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 2097152;

int n;
vector <int> seq[Maxn];
int good[Maxm];
int onme[Maxm];
ll res;

int getNode(int v) { return onme[v] > 0? 0: good[v]; }

void downOn(int v, int delt)
{
    onme[v] += delt;
}

void Union(int v)
{
    good[v] = getNode(2 * v) + getNode(2 * v + 1);
}

void Create(int v, int l, int r)
{
    good[v] = r - l + 1;
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) downOn(v, delt);
    else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        Union(v);
    }
}

int Get(int v, int l, int r, int a, int b)
{
    if (onme[v] > 0) return 0;
    if (l == a && r == b) return getNode(v);
    else {
        int res = 0;
        int m = l + r >> 1;
        if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return res;
    }
}

void markLast(const vector <int> &V, int delt)
{
    if (V.empty()) return;
    if (V.size() >= 4) Update(1, 0, n, 0, V[int(V.size()) - 4] - 1, delt);
    int cur = V.size() >= 3? V[int(V.size()) - 3]: 0;
    Update(1, 0, n, cur, V.back() - 1, delt);
}

int main()
{
    scanf("%d", &n);
    Create(1, 0, n);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        markLast(seq[a], -1);
        seq[a].push_back(i);
        markLast(seq[a], 1);
        res += Get(1, 0, n, 0, i - 1);
    }
    cout << res << endl;
    return 0;
}