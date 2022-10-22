#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const string lets = "NESW";
const int mod1 = 1000000007;
const int mod2 = 1000000009;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int n;
char A[Maxn];
char B[Maxn];
ii hA[Maxn], hB[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

ii getHash(ii H[], int l, int r)
{
    ii res = H[r];
    if (--l >= 0) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * H[l].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * H[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

ii getHashR(ii H[], int l, int r)
{
    ii res = H[l];
    if (++r < n) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * H[r].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * H[r].second % mod2 + mod2) % mod2;
    }
    return res;
}

ii Add(ii h, char let, bool md)
{
    int add = lets.find(let);
    if (md) add = (add + 2) % 4;
    add++;
    h.first = (ll(h.first) * arg1 + ll(add)) % mod1;
    h.second = (ll(h.second) * arg2 + ll(add)) % mod2;
    return h;
}

int main()
{
    arg1 = uniform_int_distribution<int>(10000000, 20000000)(rng);
    arg2 = uniform_int_distribution<int>(10000000, 20000000)(rng);
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(arg1) * pw1[i - 1] % mod1;
        pw2[i] = ll(arg2) * pw2[i - 1] % mod2;
    }
    scanf("%d", &n); n--;
    scanf("%s", A);
    scanf("%s", B);
    ii h = ii(0, 0);
    for (int i = 0; i < n; i++) {
        h = Add(h, A[i], true);
        hA[i] = h;
    }
    h = ii(0, 0);
    for (int i = n - 1; i >= 0; i--) {
        h = Add(h, B[i], false);
        hB[i] = h;
    }
    for (int i = 0; i < n; i++)
        if (getHash(hA, i, n - 1) == getHashR(hB, i, n - 1)) {
            printf("NO\n"); return 0;
        }
    printf("YES\n");
    return 0;
}