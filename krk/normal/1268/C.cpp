#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int p[Maxn];
int ind[Maxn];
ll sum[Maxm], cnt[Maxm];

void Add(int v, int l, int r, ll x)
{
    sum[v] += x; cnt[v]++;
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) Add(2 * v, l, m, x);
        else Add(2 * v + 1, m + 1, r, x);
    }
}

int getInd(int v, int l, int r, ll x)
{
    if (l == r) return l;
    else {
        int m = l + r >> 1;
        if (x < cnt[2 * v]) return getInd(2 * v, l, m, x);
        else return getInd(2 * v + 1, m + 1, r, x - cnt[2 * v]);
    }
}

ll getSum(int v, int l, int r, int a, int b)
{
    if (a > b) return 0;
    if (l == a && r == b) return sum[v];
    else {
        int m = l + r >> 1;
        ll res = 0;
        if (a <= m) res += getSum(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) res += getSum(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return res;
    }
}

ll getCnt(int v, int l, int r, int a, int b)
{
    if (a > b) return 0;
    if (l == a && r == b) return cnt[v];
    else {
        int m = l + r >> 1;
        ll res = 0;
        if (a <= m) res += getCnt(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) res += getCnt(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return res;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        ind[p[i]] = i;
    }
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += getCnt(1, 0, n - 1, ind[i] + 1, n - 1);
        Add(1, 0, n - 1, ind[i]);
        int ind = getInd(1, 0, n - 1, (i - 1) / 2);
        int a = (i - 1) / 2, b = i / 2;
        ll cand = cur;
        cand += ll(a) * ind - getSum(1, 0, n - 1, 0, ind - 1) - ll(a) * (a + 1) / 2ll;
        cand += getSum(1, 0, n - 1, ind + 1, n - 1) - ll(b) * ind - ll(b) * (b + 1) / 2ll;
        printf("%I64d%c", cand, i + 1 <= n? ' ': '\n');
    }
    return 0;
}