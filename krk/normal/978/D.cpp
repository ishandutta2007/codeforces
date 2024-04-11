#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int b[Maxn];
int res = Maxn;

int main()
{
    scanf("%d", &n);
    if (n <= 2) { printf("0\n"); return 0; }
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = b[0] - 1; i <= b[0] + 1; i++)
        for (int j = b[1] - 1; j <= b[1] + 1; j++) {
            ll fir = i, d = j - i;
            int cand = 0;
            for (int z = 0; z < n; z++) {
                ll nd = fir + ll(z) * d;
                if (nd != b[z])
                    if (abs(nd - b[z]) == 1) cand++;
                    else cand = Maxn;
            }
            res = min(res, cand);
        }
    if (res >= Maxn) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}