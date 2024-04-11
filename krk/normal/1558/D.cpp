#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
 
const int Maxn = 400005;
const int Maxm = 1048576;
const int mod = 998244353;
 
int fac[Maxn], ifac[Maxn];
int T;
int n, m;
int X[Maxn], Y[Maxn];
int st[Maxm];
vector <ii> seq;
 
int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}
 
int Inv(int x) { return toPower(x, mod - 2); }
 
int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}
 
void Clear(int v, int l, int r)
{
    if (st[v] == 0) return;
    st[v] = 0;
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}
 
int getInd(int v, int l, int r, int x)
{
    st[v]++;
    if (l == r) return l;
    else {
        int m = l + r >> 1;
        int has = (m - l + 1) - st[2 * v];
        if (x <= has) return getInd(2 * v, l, m, x);
        else return getInd(2 * v + 1, m + 1, r, x - has);
    }
}
 
int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d %d", &X[i], &Y[i]);
        seq.clear();
        for (int i = m - 1; i >= 0; i--)
            seq.push_back(ii(getInd(1, 1, n, Y[i]), X[i]));
        sort(seq.begin(), seq.end());
        int got = m;
        for (int i = 0; i + 1 < seq.size(); i++)
            if (seq[i].first + 1 == seq[i + 1].first && seq[i].second < seq[i + 1].second)
                got--;
        printf("%d\n", C(n + n - 1 - got, n - 1 - got));
        Clear(1, 1, n);
    }
    return 0;
}