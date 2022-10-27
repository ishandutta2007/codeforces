#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n, p[nax], c[nax];
bool vis[nax];

int cyc[nax];
int topCycle;




int solve () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n;  ++ i) {
        scanf("%d", p + i);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", c + i);
    }

    fill(vis + 1, vis + 1 + n, false);

    int ans = n + 1;

    for (int i = 1 ; i <= n; ++ i) {
        if (vis[i]) continue;
        int cur = i;
        topCycle = 0;

        do {
            vis[cur] = true;
            cyc[topCycle ++ ] = cur;
            cur = p[cur];
        } while (cur != i);

        ans = min(ans, topCycle);
        int s = topCycle;

        for (int d = 1 ; d <= ans ; ++d) if (s % d == 0) {
            for (int j = d - 1 ; j >= 0 ; -- j) {
                int base_color = c[cyc[j]];
                bool same = true;

                for (int v = j + d ; v < s ; v += d) {
                        same &= base_color == c[cyc[v]];
                        if (!same) break;
                }

                if (same) ans = min(ans, d);
            }
        }
    }


    return ans;


}

int main () {
    int T;
    for (scanf("%d", &T) ; T -- ;) {
        printf("%d\n", solve());
    }
}