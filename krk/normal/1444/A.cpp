#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;

int T;
ll p;
int q;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %d", &p, &q);
        if (p % q != 0) printf("%I64d\n", p);
        else {
            ll oldp = p;
            ll mn = Inf;
            for (int i = 2; i * i <= q; i++) if (q % i == 0) {
                int cnt1 = 0, cnt2 = 0;
                while (q % i == 0) {
                    cnt1++; q /= i;
                }
                while (p % i == 0) {
                    cnt2++; p /= i;
                }
                ll cand = 1;
                for (int z = 0; z <= cnt2 - cnt1; z++)
                    cand *= ll(i);
                mn = min(mn, cand);
            }
            if (q > 1) {
                int cnt1 = 1, cnt2 = 0;
                while (p % q == 0) { cnt2++; p /= q; }
                ll cand = 1;
                for (int i = 0; i <= cnt2 - cnt1; i++)
                    cand *= ll(q);
                mn = min(mn, cand);
            }
            printf("%I64d\n", oldp / mn);
        }
    }
    return 0;
}