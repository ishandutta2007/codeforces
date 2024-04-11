#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 998244353;
const int Maxn = 200005;

int n, m;
int d[Maxn];
int sumbad, sumgood, k;
int a[Maxn], b[Maxn];
ii quer[Maxn];
int res[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        sumbad = (sumbad + d[i]) % mod;
        k++;
    }
    sort(d, d + n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        quer[i] = ii(b[i], i);
    }
    sort(quer, quer + m);
    int pnt = 0;
    for (int i = 0; i < m; i++) {
        int ind = quer[i].second;
        while (pnt < n && d[pnt] < b[ind]) {
            k--;
            sumbad = (sumbad - d[pnt] + mod) % mod;
            sumgood = (sumgood + d[pnt]) % mod;
            pnt++;
        }
        if (a[ind] > k) res[ind] = 0;
        else {
            res[ind] = ll(k - a[ind]) * Inv(k) % mod * sumbad % mod;
            res[ind] = (res[ind] + ll(k - a[ind] + 1) * Inv(k + 1) % mod * sumgood) % mod;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", res[i]);
    return 0;
}