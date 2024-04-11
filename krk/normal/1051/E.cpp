#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const int mod = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
char tmp[Maxn];
int mod1, mod2;
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
string A, L, R;
ii HA[Maxn], HL[Maxn], HR[Maxn];
int dp[Maxn];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Compute(const string &X, ii H[])
{
    ii h = ii(0, 0);
    for (int i = 0; i < X.size(); i++) {
        h.first = (ll(h.first) * arg1 + ll(X[i] - '0' + 1)) % mod1;
        h.second = (ll(h.second) * arg2 + ll(X[i] - '0' + 1)) % mod2;
        H[i] = h;
    }
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

bool LessEq(const string &A, ii HA[], int fromA, const string &B, ii HB[], int fromB, int len)
{
    int l = 0, r = len - 1;
    while (l <= r) {
        int m = l + r >> 1;
        int ind1 = fromA + m;
        int ind2 = fromB + m;
        if (A[ind1] != B[ind2]) r = m - 1;
        else if (getHash(HA, fromA, ind1) != getHash(HB, fromB, ind2)) r = m - 1;
        else l = m + 1;
    }
    if (l >= len) return true;
    return A[fromA + l] < B[fromB + l];
}

int main()
{
    mod1 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    arg1 = uniform_int_distribution<int>(1000000, 10000000)(rng);
    arg2 = uniform_int_distribution<int>(1000000, 10000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    Read(A);
    Read(L);
    Read(R);
    Compute(A, HA);
    Compute(L, HL);
    Compute(R, HR);
    dp[0] = 1;
    dp[1] = mod - 1;
    int cur = 0;
    for (int i = 0; i < A.length(); i++) {
        cur = (cur + dp[i]) % mod;
        if (cur == 0) continue;
        if (A[i] == '0') {
            if (L.length() == 1 && L[0] == '0') {
                dp[i + 1] = (dp[i + 1] + cur) % mod;
                dp[i + 2] = (dp[i + 2] - cur + mod) % mod;
            }
            continue;
        }
        int lef = L.length();
        int rig = min(int(R.length()), int(A.length()) - i);
        if (lef > rig) continue;
        if (!LessEq(L, HL, 0, A, HA, i, lef)) lef++;
        if (lef > rig) continue;
        if (rig == R.length() && !LessEq(A, HA, i, R, HR, 0, rig)) rig--;
        if (lef > rig) continue;
        lef += i; rig += i;
        dp[lef] = (dp[lef] + cur) % mod;
        dp[rig + 1] = (dp[rig + 1] - cur + mod) % mod;
    }
    cur = (cur + dp[A.length()]) % mod;
    printf("%d\n", cur);
    return 0;
}