#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxb = 9;
const int Inf = 1000000007;

int n, m;
int peop[1 << Maxb];
ii best[1 << Maxb][2];
int res = -1, cost = Inf, bi, bj;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int cnt; scanf("%d", &cnt);
        int mask = 0;
        while (cnt--) {
            int j; scanf("%d", &j);
            mask |= 1 << j - 1;
        }
        peop[mask]++;
    }
    for (int i = 0; i < Maxb; i++)
        for (int j = 0; j < 1 << Maxb; j++)
            if (!(j & 1 << i)) peop[j | 1 << i] += peop[j];
    fill((ii*)best, (ii*)best + (1 << Maxb) * 2, ii(Inf, -1));
    for (int i = 0; i < m; i++) {
        int c, cnt; scanf("%d %d", &c, &cnt);
        int mask = 0;
        while (cnt--) {
            int j; scanf("%d", &j);
            mask |= 1 << j - 1;
        }
        if (c < best[mask][0].first) best[mask][1] = best[mask][0], best[mask][0] = ii(c, i + 1);
        else if (c < best[mask][1].first) best[mask][1] = ii(c, i + 1);
    }
    for (int i = 0; i < 1 << Maxb; i++) if (best[i][0].first < Inf) {
        if (best[i][1].first < Inf) {
            int cand1 = peop[i], cand2 = best[i][0].first + best[i][1].first;
            if (cand1 > res || cand1 == res && cand2 < cost) {
                res = cand1;
                cost = cand2;
                bi = best[i][0].second;
                bj = best[i][1].second;
            }
        }
        for (int j = i + 1; j < 1 << Maxb; j++) if (best[j][0].first < Inf) {
            int cand1 = peop[i | j], cand2 = best[i][0].first + best[j][0].first;
            if (cand1 > res || cand1 == res && cand2 < cost) {
                res = cand1;
                cost = cand2;
                bi = best[i][0].second;
                bj = best[j][0].second;
            }
        }
    }
    printf("%d %d\n", bi, bj);
    return 0;
}