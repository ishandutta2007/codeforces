#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m;
int tab[N][N];
int cnt[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int best = 0;
        tab[i][0] = -1;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &tab[i][j]);
            if (tab[i][j] > tab[i][best]) {
                best = j;
            }
        }
        cnt[best]++;
    }

    int best = 0;
    cnt[0] = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > cnt[best]) {
            best = i;
        }
    }

    printf("%d\n", best);

    return 0;
}