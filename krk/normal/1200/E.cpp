#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxn = 1000005;
int arg1, arg2;

int pw1[Maxn], pw2[Maxn];
int n;
char str[Maxn];
int slen;
ii SH[Maxn];
char res[Maxn];
int rlen;
ii RH[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

ii addLet(ii h, char let)
{
    return ii((ll(h.first) * arg1 + ll(let) + 500ll) % mod1,
              (ll(h.second) * arg2 + ll(let) + 600ll) % mod2);
}

ii Get(ii H[], int l, int r)
{
    ii res = H[r];
    if (l > 0) {
        l--;
        res.first = (ll(res.first) - ll(H[l].first) * pw1[r - l] % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(H[l].second) * pw2[r - l] % mod2 + mod2) % mod2;
    }
    return res;
}

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    arg1 = uniform_int_distribution<int>(10000, 100000000)(rng);
    arg2 = uniform_int_distribution<int>(10000, 100000000)(rng);
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(arg1) * pw1[i - 1] % mod1;
        pw2[i] = ll(arg2) * pw2[i - 1] % mod2;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str); slen = strlen(str);
        ii cur = ii(0, 0);
        for (int j = 0; j < slen; j++) {
            cur = addLet(cur, str[j]);
            SH[j] = cur;
        }
        int sam;
        for (sam = min(slen, rlen); sam > 0; sam--)
            if (Get(SH, 0, sam - 1) == Get(RH, rlen - sam, rlen - 1)) break;
        for (int j = sam; j < slen; j++) {
            RH[rlen] = addLet((rlen? RH[rlen - 1]: ii(0, 0)), str[j]);
            res[rlen++] = str[j];
        }
    }
    res[rlen] = '\0';
    printf("%s\n", res);
    return 0;
}