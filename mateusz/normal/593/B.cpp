#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const long long INF = 1e18;

int n;
int x1, x2;
int k[N], b[N], tab[N];

bool cmp(int a, int c) {
    return (long long)k[a] * x1 + b[a] < (long long)k[c] * x1 + b[c];
}

int main() {

    scanf("%d", &n);
    scanf("%d %d", &x1, &x2);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &k[i], &b[i]);
        tab[i] = i;
    }

    sort(tab + 1, tab + 1 + n, cmp);

    long long mx = -INF;
    for (int i = 1; i <= n; i++) {
        long long y2 = (long long)k[tab[i]] * x2 + b[tab[i]];
        if (mx > y2) {
            printf("YES\n");
            return 0;
        }

        if (i == n || (long long)k[tab[i]] * x1 + b[tab[i]] != (long long)k[tab[i + 1]] * x1 + b[tab[i + 1]]) {
            int w = i;
            while (w >= 1 && (long long)k[tab[i]] * x1 + b[tab[i]] == (long long)k[tab[w]] * x1 + b[tab[w]]) {
                mx = max(mx, (long long)k[tab[w]] * x2 + b[tab[w]]);
                w--;
            }
        }
    }

    printf("NO\n");
    return 0;
}