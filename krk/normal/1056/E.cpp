#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxn = 1000005;

int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
ii H[Maxn];
char S[Maxn], T[Maxn];
int slen, tlen;
int res;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

ii Get(int l, int r)
{
    ii h = H[r];
    l--;
    if (l >= 0) {
        h.first = (ll(h.first) - ll(H[l].first) * pw1[r - l] % mod1 + mod1) % mod1;
        h.second = (ll(h.second) - ll(H[l].second) * pw2[r - l] % mod2 + mod2) % mod2;
    }
    return h;
}

int main()
{
    srand(time(0));
    arg1 = rand() % 512 + 216;
    arg2 = rand() % 1024 + 32;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%s", S); slen = strlen(S);
    scanf("%s", T); tlen = strlen(T);
    ii h = ii(0, 0);
    for (int i = 0; i < tlen; i++) {
        h.first = (ll(h.first) * arg1 + ll(T[i] - 'a' + 1)) % mod1;
        h.second = (ll(h.second) * arg2 + ll(T[i] - 'a' + 1)) % mod2;
        H[i] = h;
    }
    int zers = 0, ones = 0;
    for (int i = 0; i < slen; i++)
        if (S[i] == '0') zers++;
        else ones++;
    for (int alen = 1; zers * alen < tlen; alen++) {
        int lft = tlen - zers * alen;
        if (lft % ones == 0) {
            int blen = lft / ones;
            ii h0 = ii(-1, -1);
            ii h1 = ii(-1, -1);
            int pnt = 0;
            bool fall = false;
            for (int i = 0; i < slen && !fall; i++)
                if (S[i] == '0') {
                    ii got = Get(pnt, pnt + alen - 1);
                    pnt += alen;
                    if (h0.first != -1 && h0 != got) fall = true;
                    h0 = got;
                } else {
                    ii got = Get(pnt, pnt + blen - 1);
                    pnt += blen;
                    if (h1.first != -1 && h1 != got) fall = true;
                    h1 = got;
                }
            if (!fall && h0 != h1) res++;
        }
    }
    printf("%d\n", res);
    return 0;
}