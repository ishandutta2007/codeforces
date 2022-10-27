#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5+  10;

int n;
bool vis[nax];

void solve () {
    scanf("%d", &n);

    int cradle_daughter = -1;
    fill(vis + 1 , vis + 1 + n , false);


    for (int i = 1 ; i <= n; ++ i) {
        int k;
        scanf("%d", &k);
        bool done = false;

        for (int v = 0 ; v < k ; ++ v) {
            int x;
            scanf("%d", &x);
            if (done) continue;
            else if (!vis[x]) {
                done = true;
                vis[x] = true;
            }
        }

        if (!done && cradle_daughter == -1) cradle_daughter = i;
    }

    if (cradle_daughter == -1) {
        puts("OPTIMAL");
        return ;
    }

    puts("IMPROVE");

    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) {
            printf("%d %d\n", cradle_daughter, i);
            return ;
        }
    }

    throw;

}


int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        solve();
    }
}