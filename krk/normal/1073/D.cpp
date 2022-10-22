#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;
const int Maxm = 1048576;

int n;
ll T;
int a[Maxn];
lli sum[Maxm];
ll res;

lli Add(const lli &a, const lli &b)
{
    return lli(a.first + b.first, a.second + b.second);
}

void Union(int v)
{
    sum[v] = Add(sum[2 * v], sum[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    if (l == r) sum[v] = lli(a[l], 1);
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Clear(int v, int l, int r, int x)
{
    if (l == r) sum[v] = lli(0, 0);
    else {
        int m = l + r >> 1;
        if (x <= m) Clear(2 * v, l, m, x);
        else Clear(2 * v + 1, m + 1, r, x);
        Union(v);
    }
}

lli Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return sum[v];
    else {
        int m = l + r >> 1;
        lli res = lli(0, 0);
        if (a <= m) res = Add(res, Get(2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = Add(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

lli Get(int a, int hm)
{
    if (hm == 0) return lli(0, 0);
    if (a + hm - 1 < n) return Get(1, 0, n - 1, a, a + hm - 1);
    return Add(Get(1, 0, n - 1, a, n - 1), Get(1, 0, n - 1, 0, a + hm - 1 - n));
}

int getNext(int ind)
{
    if (sum[1].first == 0) return -1;
    if (sum[1].first <= T) {
        ll tims = T / sum[1].first;
        res += tims * sum[1].second;
        T -= tims * sum[1].first;
    }
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        auto got = Get(ind, mid);
        if (got.first > T) r = mid - 1;
        else l = mid + 1;
    }
    auto got = Get(ind, r);
    res += got.second;
    T -= got.first;
    ind = (ind + r) % n;
    Clear(1, 0, n - 1, ind);
    return ind;
}

int main()
{
    scanf("%d %I64d", &n, &T);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Create(1, 0, n - 1);
    int cur = 0;
    while ((cur = getNext(cur)) != -1) ;
    cout << res << endl;
    return 0;
}