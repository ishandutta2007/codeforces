#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 998244353;
const int Maxn = 300005;

int fac[Maxn];
int n;
ii a[Maxn];
int freq[Maxn];
int res;
map <ii, int> M;

int main()
{
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(fac[i - 1]) * i % mod;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
        freq[a[i].first]++;
    }
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        cur = ll(cur) * fac[freq[i]] % mod;
        freq[i] = 0;
    }
    res = cur;
    for (int i = 0; i < n; i++)
        freq[a[i].second]++;
    cur = 1;
    for (int i = 1; i <= n; i++)
        cur = ll(cur) * fac[freq[i]] % mod;
    res = (res + cur) % mod;
    sort(a, a + n);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        M[a[i]]++;
        if (i && ok) ok = a[i - 1].second <= a[i].second;
    }
    if (ok) {
        cur = 1;
        for (map <ii, int>::iterator it = M.begin(); it != M.end(); it++)
            cur = ll(cur) * fac[it->second] % mod;
        res = (res - cur + mod) % mod;
    }
    res = (fac[n] - res + mod) % mod;
    printf("%d\n", res);
    return 0;
}