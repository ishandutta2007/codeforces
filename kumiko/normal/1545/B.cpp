#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 998244353;

const int maxn = 100007;
int n;
char s[maxn];
ll fac[maxn], inv[maxn], sinv[maxn];

int C(int n, int m) {
    // printf("C(%d, %d)\n", n, m);
    return fac[n] * sinv[m] % M * sinv[n - m] % M;
}

int main() {
    int T;
    fac[0] = fac[1] = inv[0] = inv[1] = sinv[0] = sinv[1] = 1;
    for (int i = 2; i <= 100000; ++i) {
        fac[i] = fac[i - 1] * i % M;
        inv[i] = (M - M / i) * inv[M % i] % M;
        sinv[i] = sinv[i - 1] * inv[i] % M;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s);
        int res = 1;
        int cnt11 = 0, cnt0 = 0, con_cur = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i + 1 < n && s[i + 1] == '1') {
                    cnt11 += 1;
                    ++i;
                }
            } else {
                ++cnt0;
            }
        }
        printf("%d\n", C(cnt0 + cnt11, cnt0));
    }
    return 0;
}