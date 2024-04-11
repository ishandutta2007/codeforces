#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxn = 1000005;
int arg1, arg2;

int pw1[Maxn], pw2[Maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int T;
char str[Maxn];
int slen;
ii L[Maxn], R[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

ii getLeft(int l, int r)
{
    ii res = L[r];
    if (--l >= 0) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * L[l].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * L[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

ii getRight(int l, int r)
{
    ii res = R[l];
    if (++r < slen) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * R[r].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * R[r].second % mod2 + mod2) % mod2;
    }
    return res;
}

void Write(int l, int r)
{
    for (int i = l; i <= r; i++)
        printf("%c", str[i]);
}

int main()
{
    arg1 = uniform_int_distribution<int>(10000000, 100000000)(rng);
    arg2 = uniform_int_distribution<int>(10000000, 100000000)(rng);
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        ii h = ii(0, 0);
        for (int i = 0; i < slen; i++) {
            h.first = (ll(h.first) * arg1 + ll(str[i] - 'a' + 1)) % mod1;
            h.second = (ll(h.second) * arg2 + ll(str[i] - 'a' + 1)) % mod2;
            L[i] = h;
        }
        h = ii(0, 0);
        for (int i = slen - 1; i >= 0; i--) {
            h.first = (ll(h.first) * arg1 + ll(str[i] - 'a' + 1)) % mod1;
            h.second = (ll(h.second) * arg2 + ll(str[i] - 'a' + 1)) % mod2;
            R[i] = h;
        }
        int l = 0, r = slen - 1;
        while (l <= r && str[l] == str[r]) l++, r--;
        if (l > r) printf("%s\n", str);
        else {
            bool found = false;
            for (int i = r - l + 1; i > 0 && !found; i--)
                if (getLeft(l, l + i - 1) == getRight(l, l + i - 1)) {
                    Write(0, l + i - 1);
                    Write(r + 1, slen - 1);
                    found = true;
                } else if (getLeft(r - i + 1, r) == getRight(r - i + 1, r)) {
                    Write(0, l - 1);
                    Write(r - i + 1, slen - 1);
                    found = true;
                }
            if (!found) {
                Write(0, l - 1);
                Write(r + 1, slen - 1);
            }
            printf("\n");
        }
    }
    return 0;
}