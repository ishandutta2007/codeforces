#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;

int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
char str[Maxn];
int slen;
ii H[Maxn], R[Maxn];
char T[Maxn];
int tlen;
int Z[Maxn];
ii best[Maxn];
int res;
vector <ii> b;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

ii getHash(int l, int r)
{
    ii h = H[r];
    if (--l >= 0) {
        h.first = (ll(h.first) - ll(pw1[r - l]) * H[l].first % mod1 + mod1) % mod1;
        h.second = (ll(h.second) - ll(pw2[r - l]) * H[l].second % mod2 + mod2) % mod2;
    }
    return h;
}

ii getReverse(int l, int r)
{
    ii h = R[l];
    if (++r < slen) {
        h.first = (ll(h.first) - ll(pw1[r - l]) * R[r].first % mod1 + mod1) % mod1;
        h.second = (ll(h.second) - ll(pw2[r - l]) * R[r].second % mod2 + mod2) % mod2;
    }
    return h;
}

int main()
{
    arg1 = uniform_int_distribution<int>(100000000, 500000000)(rng);
    arg2 = uniform_int_distribution<int>(100000000, 500000000)(rng);
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%s", str);
    slen = strlen(str);
    ii h = ii(0, 0);
    for (int i = 0; i < slen; i++) {
        h.first = (ll(h.first) * arg1 + ll(str[i] - '0' + 1)) % mod1;
        h.second = (ll(h.second) * arg2 + ll(str[i] - '0' + 2)) % mod2;
        H[i] = h;
    }
    h = ii(0, 0);
    for (int i = slen - 1; i >= 0; i--) {
        h.first = (ll(h.first) * arg1 + ll(str[i] - '0' + 1)) % mod1;
        h.second = (ll(h.second) * arg2 + ll(str[i] - '0' + 2)) % mod2;
        R[i] = h;
    }
    for (int i = slen - 1; i >= 0; i--)
        T[tlen++] = str[i];
    T[tlen++] = '#';
    for (int i = 0; i < slen; i++)
        T[tlen++] = str[i];
    int l = -1, r = -1;
    for (int i = 1; i < tlen; i++) {
        if (i <= r) Z[i] = min(Z[i - l], r - i);
        while (i + Z[i] < tlen && T[Z[i]] == T[i + Z[i]]) Z[i]++;
        int nl = i, nr = i + Z[i] - 1;
        if (nr > r) {
            if (nr > slen)
                for (int j = r + 1; j <= nr; j++)
                    best[j - slen] = max(best[j - slen - 1], ii(j - nl + 1, nl - slen - 1));
            l = nl; r = nr;
        }
    }
    for (int i = 0; i < slen; i++) {
        int l = 1, r = min(i, slen - 1 - i);
        while (l <= r) {
            int m = l + r >> 1;
            if (getHash(i - m, i + m) == getReverse(i - m, i + m))
                l = m + 1;
            else r = m - 1;
        }
        int got = l - 1;
        int mx = min(slen - 1 - (i + got), best[i - got].first);
        if (2 * got + 1 + 2 * mx > res) {
            res = 2 * got + 1 + 2 * mx;
            b.clear();
            if (mx) b.push_back(ii(best[i - got].second, mx));
            b.push_back(ii(i - got, 2 * got + 1));
            if (mx) b.push_back(ii(slen - mx, mx));
        }
    }
    printf("%d\n", int(b.size()));
    for (int i = 0; i < b.size(); i++)
        printf("%d %d\n", b[i].first + 1, b[i].second);
    return 0;
}