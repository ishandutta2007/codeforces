#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 1000001;
const int Inf = 1000000000;

int mx[Maxm];
vector <int> pr;
int n;
int best[Maxm];
int mycnt[Maxm];
int res = Inf;

int main()
{
    for (int i = 1; i < Maxm; i++) if (mx[i] == 0 || mx[i] == 1) {
        pr.push_back(i);
        for (int j = i; j < Maxm; j += i)
            mx[j] = i;
    }
    fill(best, best + Maxm, Inf);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        int cur = 1;
        while (a > 1) {
            int cnt = 0;
            int my = mx[a];
            while (mx[a] == my) { cnt++; a /= my; }
            if (cnt % 2) cur *= my;
        }
        if (cur == 1) { printf("1\n"); return 0; }
        mycnt[cur]++;
    }
    for (int i = 0; i < Maxm; i++)
        if (mycnt[i] > 1) { printf("2\n"); return 0; }
    for (int i1 = int(pr.size()) - 1; i1 >= 0; i1--) {
        for (int i2 = 0; i2 < i1 && pr[i2] <= (Maxm - 1) / pr[i1]; i2++) if (mycnt[pr[i1] * pr[i2]]) {
            res = min(res, 1 + best[pr[i1] * pr[i2]]);
            for (int b = 0; b < pr.size() && pr[b] <= (Maxm - 1) / pr[i1]; b++) if (b != i1)
                best[pr[b] * pr[i1]] = min(best[pr[b] * pr[i1]], best[pr[b] * pr[i2]] * (b != i2) + 1);
        }
        for (int a = 0; a < pr.size() && pr[a] <= (Maxm - 1) / pr[i1]; a++) if (a != i1)
            for (int b = 0; b < pr.size() && pr[b] <= (Maxm - 1) / pr[i1] &&
                                             pr[b] <= (Maxm - 1) / pr[a]; b++) if (b != a && b != i1)
                best[pr[a] * pr[b]] = min(best[pr[a] * pr[b]],
                                          best[pr[a] * pr[i1]] + best[pr[b] * pr[i1]]);
    }
    printf("%d\n", res > n? -1: res);
    return 0;
}