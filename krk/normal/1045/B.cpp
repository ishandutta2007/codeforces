#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 37;
const int arg2 = 1000007;

int pw1[Maxn], pw2[Maxn];
int n, m;
int a[Maxn];
int difs[Maxn];
ii L[Maxn], R[Maxn];
vector <int> res;

ii Join(const ii &a, const ii &b, int len)
{
    ii c;
    c.first = (ll(a.first) * pw1[len] + ll(b.first)) % mod1;
    c.second = (ll(a.second) * pw2[len] + ll(b.second)) % mod2;
    return c;
}

ii Add(const ii &h, int val)
{
    return Join(h, ii(val + 1, val + 2), 1);
}

ii getLeft(int l, int r)
{
    ii res = L[r];
    l--;
    if (l >= 0) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * L[l].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * L[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

ii getRight(int l, int r)
{
    ii res = R[l];
    r++;
    if (r < n) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * R[r].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * R[r].second % mod2 + mod2) % mod2;
    }
    return res;
}

int main()
{
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(arg1) * pw1[i - 1] % mod1;
        pw2[i] = ll(arg2) * pw2[i - 1] % mod2;
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        difs[i] = (a[ni] - a[i] + m) % m;
    }
    ii cur = ii(0, 0);
    for (int i = 0; i < n; i++) {
        cur = Add(cur, difs[i]);
        L[i] = cur;
    }
    cur = ii(0, 0);
    for (int i = n - 1; i >= 0; i--) {
        cur = Add(cur, difs[i]);
        R[i] = cur;
    }
    for (int i = 0; i < n; i++) {
        ii h1 = getLeft(i, n - 1);
        if (i > 0) {
            ii add = getLeft(0, i - 1);
            h1 = Join(h1, add, i);
        }
        ii h2 = i > 0? getRight(0, i - 1): ii(0, 0);
        ii add = getRight(i, n - 1);
        h2 = Join(h2, add, n - i);
        if (h1 == h2) res.push_back(2 * a[i] % m);
        h1 = i < n - 1? getLeft(i + 1, n - 1): ii(0, 0);
        if (i > 0) {
            add = getLeft(0, i - 1);
            h1 = Join(h1, add, i);
        }
        h2 = i > 0? getRight(0, i - 1): ii(0, 0);
        add = i < n - 1? getRight(i + 1, n - 1): ii(0, 0);
        h2 = Join(h2, add, n - i - 1);
        if (h1 == h2) res.push_back((a[i] + a[(i + 1) % n]) % m);
    }
    sort(res.begin(), res.end()); res.erase(unique(res.begin(), res.end()), res.end());
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}