#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 9;

int T;
char str[Maxn];
int n;
int w, m;
int sum[Maxn];
int fir[Maxm][2];

void Update(ii &a, const ii &b)
{
    if (b.first == -1 || b.second == -1) return;
    if (a.first == -1 || a.second == -1) { a = b; return; }
    a = min(a, b);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str + 1);
        n = strlen(str + 1);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + int(str[i] - '0');
        scanf("%d %d", &w, &m);
        fill((int*)fir, (int*)fir + Maxm * 2, -1);
        for (int i = 1; i + w <= n + 1; i++) {
            int got = (sum[i + w - 1] - sum[i - 1]) % Maxm;
            if (fir[got][0] == -1) fir[got][0] = i;
            else if (fir[got][1] == -1) fir[got][1] = i;
        }
        while (m--) {
            int l, r, k; scanf("%d %d %d", &l, &r, &k);
            int x = (sum[r] - sum[l - 1]) % Maxm;
            ii res = ii(-1, -1);
            for (int i = 0; i < Maxm; i++)
                for (int j = 0; j < Maxm; j++) if ((i * x + j) % Maxm == k) {
                    ii cand = i != j? ii(fir[i][0], fir[j][0]): ii(fir[i][0], fir[i][1]);
                    Update(res, cand);
                }
            if (res.first == -1 || res.second == -1) printf("-1 -1\n");
            else printf("%d %d\n", res.first, res.second);
        }
    }
    return 0;
}