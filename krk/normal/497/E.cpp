#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 62;
const int Maxb = 30;
const int mod = 1000000007;

ll n;
int b;

struct node {
    int m[Maxb][Maxb];
    int has[Maxb];
    int lst[Maxb];
    node() {
        for (int i = 0; i < b; i++) {
            has[i] = 0;
            for (int j = 0; j < b; j++)
                m[i][j] = 0;
        }
    }
};

node M[Maxl][Maxb];
bool comp[Maxl][Maxb];

node Join(const node &A, const node &B, int dif)
{
    node C;
    for (int i = 0; i < b; i++) {
        C.lst[i] = (B.lst[i] + dif) % b;
        C.has[i] = A.has[i];
    }
    bool was[Maxb] = {};
    for (int i = b - 1; i >= 0; i--) {
        int u = A.lst[i];
        for (int j = 0; j < b; j++) if (!was[j]) {
            int v2 = (j - dif + b) % b;
            for (int v = 0; v < b; v++) {
                C.has[v] = (C.has[v] + ll(A.m[v][u]) * B.has[v2]) % mod;
                for (int u2 = 0; u2 < b; u2++)
                    C.m[v][u2] = (C.m[v][u2] + ll(A.m[v][u]) * B.m[v2][(u2 - dif + b) % b]) % mod;
            }
        }
        was[u] = true;
    }
    return C;
}

node Get(int len, int val)
{
    if (!comp[len][val]) {
        comp[len][val] = true;
        if (val == 0) M[len][val] = Get(len - 1, b - 1);
        else M[len][val] = Join(Get(len, (val - 1) / 2), Get(len, val / 2), (val + 1) / 2);
    }
    return M[len][val];
}

node Solve(ll n, int len, int &cur)
{
    if (n < b) {
        cur = (cur + n) % b;
        return Get(len, n - 1);
    }
    if (n % b == 0) return Solve(n / b, len + 1, cur);
    auto tmp = Solve(n / b, len + 1, cur);
    auto res = Join(tmp, Get(len, n % b - 1), cur);
    cur = (cur + n % b) % b;
    return res;
}

int main()
{
    scanf("%I64d %d", &n, &b);
    int L = 0;
    ll num = n;
    while (num) {
        L++;
        num /= b;
    }
    for (int j = 0; j < b; j++) {
        comp[0][j] = true;
        for (int z = 0; z <= j; z++) {
            M[0][j].lst[z] = z;
            M[0][j].has[z] = 1 << (j - z);
            M[0][j].m[z][z] = 1;
            for (int c = z + 1; c <= j; c++)
                M[0][j].m[z][c] = 1 << (c - z - 1);
        }
    }
    int cur = 0;
    node res = Solve(n, 0, cur);
    int ans = 1;
    for (int i = 0; i < b; i++)
        ans = (ans + res.has[i]) % mod;
    printf("%d\n", ans);
    return 0;
}