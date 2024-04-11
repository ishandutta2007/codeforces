#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 60;

int T;
ll n;
int m;
ll has[Maxb];

int Solve()
{
    int res = 0;
    for (int i = 0; i < Maxb; i++) {
        if (n & 1ll << ll(i)) {
            if (has[i] == 0) {
                int j = i + 1;
                while (j < Maxb && has[j] == 0) j++;
                if (j >= Maxb) return -1;
                while (j > i) {
                    res++;
                    has[j]--; has[j - 1] += 2;
                    j--;
                }
            }
            has[i]--;
        }
        if (i + 1 < Maxb) has[i + 1] += has[i] / 2;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %d", &n, &m);
        fill(has, has + Maxb, 0ll);
        for (int i = 0; i < m; i++) {
            int a; scanf("%d", &a);
            int b = 0;
            while (a > 1) { a >>= 1; b++; }
            has[b]++;
        }
        printf("%d\n", Solve());
    }
    return 0;
}