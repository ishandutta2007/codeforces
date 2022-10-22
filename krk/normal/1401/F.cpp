#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300000;
const int Maxm = 2097152;

int n, q;
int a[Maxn];
int lst[Maxm];
ll sum[Maxm];
int L[Maxm], R[Maxm];
vector <int> s[20];

void Union(int v)
{
    sum[v] = sum[L[v]] + sum[R[v]];
}

void Down(int v, int lvl)
{
    if (s[lvl].empty()) return;
    int hm = s[lvl].end() - upper_bound(s[lvl].begin(), s[lvl].end(), lst[v]);
    lst[v] = s[lvl].back();
    if (hm % 2) swap(L[v], R[v]);
}

void Create(int v, int l, int r)
{
    L[v] = 2 * v;
    R[v] = 2 * v + 1;
    if (l == r) sum[v] = a[l];
    else {
        int m = l + r >> 1;
        Create(L[v], l, m);
        Create(R[v], m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int lvl, int x, int val)
{
    if (l == r) sum[v] = val;
    else {
        Down(v, lvl);
        int m = l + r >> 1;
        if (x <= m) Update(L[v], l, m, lvl - 1, x, val);
        else Update(R[v], m + 1, r, lvl - 1, x, val);
        Union(v);
    }
}

ll getSum(int v, int l, int r, int lvl, int a, int b)
{
    if (l == a && r == b) return sum[v];
    else {
        Down(v, lvl);
        ll res = 0;
        int m = l + r >> 1;
        if (a <= m) res += getSum(L[v], l, m, lvl - 1, a, min(m, b));
        if (m + 1 <= b) res += getSum(R[v], m + 1, r, lvl - 1, max(m + 1, a), b);
        return res;
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= 1 << n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, 1 << n);
    for (int i = 1; i <= q; i++) {
        int typ, p1, p2; scanf("%d %d", &typ, &p1);
        if (typ == 1) {
            scanf("%d", &p2);
            Update(1, 1, 1 << n, n - 1, p1, p2);
        } else if (typ == 2) {
            for (int j = 0; j < p1; j++)
                s[j].push_back(i);
        } else if (typ == 3)
            s[p1].push_back(i);
        else {
            scanf("%d", &p2);
            printf("%I64d\n", getSum(1, 1, 1 << n, n - 1, p1, p2));
        }
    }
    return 0;
}