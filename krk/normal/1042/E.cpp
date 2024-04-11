#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 1005;
const int Maxm = Maxn * Maxn;

int n, m;
int a[Maxn][Maxn];
int R, C;
vector <int> un;
int cnt[Maxm], sumx[Maxm], sumy[Maxm], sqsumx[Maxm], sqsumy[Maxm];
int res;

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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d", &R, &C); R--; C--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] < a[R][C]) un.push_back(a[i][j]);
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (a[i][j] < a[R][C]) {
            int ind = lower_bound(un.begin(), un.end(), a[i][j]) - un.begin();
            cnt[ind]++;
            sumx[ind] = (sumx[ind] + i) % mod;
            sumy[ind] = (sumy[ind] + j) % mod;
            sqsumx[ind] = (sqsumx[ind] + ll(i) * i) % mod;
            sqsumy[ind] = (sqsumy[ind] + ll(j) * j) % mod;
        }
    int c = 0, sx = 0, sy = 0, ssx = 0, ssy = 0;
    for (int i = 0; i < un.size(); i++) {
        if (c > 0) {
            int got = (ll(c) * sqsumx[i] + ll(c) * sqsumy[i]) % mod;
            got = (got - 2ll * (ll(sx) * sumx[i] + ll(sy) * sumy[i]) % mod + mod) % mod;
            got = (got + ll(cnt[i]) * ssx + ll(cnt[i]) * ssy) % mod;
            res = (res + ll(got) * Inv(cnt[i] + c) % mod * Inv(c)) % mod;
        }
        c += cnt[i];
        sx = (sx + sumx[i]) % mod;
        sy = (sy + sumy[i]) % mod;
        ssx = (ssx + sqsumx[i]) % mod;
        ssy = (ssy + sqsumy[i]) % mod;
    }
    int ind = un.size();
    cnt[ind] = 1;
    sumx[ind] = R;
    sumy[ind] = C;
    sqsumx[ind] = ll(R) * R % mod;
    sqsumy[ind] = ll(C) * C % mod;
    if (c > 0) {
        int got = (ll(c) * sqsumx[ind] + ll(c) * sqsumy[ind]) % mod;
        got = (got - 2ll * (ll(sx) * sumx[ind] + ll(sy) * sumy[ind]) % mod + mod) % mod;
        got = (got + ll(cnt[ind]) * ssx + ll(cnt[ind]) * ssy) % mod;
        res = (res + ll(got) * Inv(c)) % mod;
    }
    printf("%d\n", res);
    return 0;
}