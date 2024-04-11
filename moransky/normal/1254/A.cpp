#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 105;

int n, m, k, cnt, t;

PII e[N * N];

char g[N][N], s[N][N];

char get(int x) {
    if (x < 26) return x + 'A';
    else if (x < 52) return x - 26 + 'a';
    else return x - 52 + '0';
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)  {
            scanf("%s", g[i] + 1);
            for (int j = 1; j <= m; j++)
                if (g[i][j] == 'R') cnt++;
        }
        int a = cnt / k, o = cnt % k;
        t = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                for (int j = 1; j <= m; j++) {
                    e[++t] = mp(i, j);
                }
            } else {
                for (int j = m; j; j--) {
                    e[++t] = mp(i, j);
                }
            }
        }
        int p = 1;
        for (int i = 0; i < k; i++) {
            int j = a;
            if (i < o) j++;
            while (j || (i == k - 1 && p <= n * m)) {
                s[e[p].fi][e[p].se] = get(i);
                if (g[e[p].fi][e[p].se] == 'R') j--;
                p++;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                putchar(s[i][j]);
            }
            puts("");
        }
        cnt = 0;
    }
    return 0;
}