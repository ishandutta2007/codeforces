#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int a[Maxn];
bool tk[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            tk[i] = false;
        }
        int g = 0;
        for (int i = 0; i < n; i++) {
            int best = 0, wth = -1;
            for (int j = 0; j < n; j++) if (!tk[j]) {
                int cand = gcd(g, a[j]);
                if (cand > best) {
                    best = cand;
                    wth = j;
                }
            }
            printf("%d%c", a[wth], i + 1 < n? ' ': '\n');
            tk[wth] = true;
            g = best;
        }
    }
    return 0;
}