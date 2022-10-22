#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;
const int Maxm = 2097152;
const int Maxk = 22;

int n;
int a[Maxn];
ii seq[Maxn];
int rmq[Maxn][Maxk];
int st[Maxm];
int flag[Maxm];
int best = Maxn, bi;

void downOn(int v, int f)
{
    st[v] += f; flag[v] += f;
}

void Down(int v)
{
    if (flag[v]) {
        downOn(2 * v, flag[v]);
        downOn(2 * v + 1, flag[v]);
        flag[v] = 0;
    }
}

void Union(int v)
{
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

int getMax(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        Down(v);
        int m = l + r >> 1;
        if (b <= m) return getMax(2 * v, l, m, a, b);
        if (m + 1 <= a) return getMax(2 * v + 1, m + 1, r, a, b);
        return max(getMax(2 * v, l, m, a, m), getMax(2 * v + 1, m + 1, r, m + 1, b));
    }
}

void Update(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

int getLeft(int ind, int val)
{
    int res = ind + n;
    for (int i = Maxk - 1; i >= 0; i--) if (ind + (1 << i) <= 2 * n && rmq[ind][i] >= val)
        ind += 1 << i;
    return min(res, ind);
}

int getRight(int ind, int val)
{
    int res = ind - n;
    for (int i = Maxk - 1; i >= 0; i--) if (ind - (1 << i) >= -1 && rmq[ind - (1 << i) + 1][i] >= val)
        ind -= 1 << i;
    return max(ind, res);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
        seq[i] = ii(a[i], i);
    }
    sort(seq, seq + n);
    for (int i = 0; i < 2 * n; i++)
        rmq[i][0] = a[i];
    for (int j = 1; j < Maxk; j++)
        for (int i = 0; i + (1 << j) <= 2 * n; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << j - 1)][j - 1]);
    set <int> S;
    for (int i = 0; i < n; i++) {
        int ind = seq[i].second;
        set <int>::iterator it1 = S.upper_bound(ind);
        set <int>::iterator it2 = it1;
        int g = 1;
        if (it1 != S.begin()) {
            it1--;
            if (it2 != S.end())
                if (a[*it1] > a[*it2]) g = getMax(1, 0, 2 * n - 1, *it1, *it1) + 1;
                else g = getMax(1, 0, 2 * n - 1, *it2, *it2) + 1;
            else g = getMax(1, 0, 2 * n - 1, *it1, *it1) + 1;
        } else if (it2 != S.end())
                g = getMax(1, 0, 2 * n - 1, *it2, *it2) + 1;
        Update(1, 0, 2 * n - 1, ind, ind, g);
        S.insert(ind);
    }
    for (int i = 0; i < n; i++) {
        int cand = getMax(1, 0, 2 * n - 1, i, i + n - 1);
        if (cand < best) { best = cand; bi = i; }
        int lef = getLeft(i, a[i]);
        Update(1, 0, 2 * n - 1, i, lef - 1, -1);
        int rig = getRight(i + n, a[i]);
        if (rig > i) {
            int g = getMax(1, 0, 2 * n - 1, rig, rig);
            Update(1, 0, 2 * n - 1, n + i, n + i, g);
        }
        Update(1, 0, 2 * n - 1, rig + 1, n + i, 1);
    }
    printf("%d %d\n", best, bi);
    return 0;
}