#include <bits/stdc++.h>

using namespace std;

int n, k, q;

const int MAXN = 200100;

int lev[MAXN];
bool onl[MAXN];
int main() {
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &lev[i]);
    }
    set<int> now;
    for (int it = 1; it <= q; it++) {
        int tp, id;
        scanf("%d%d", &tp, &id);
        if (tp == 1) {
            now.insert( lev[id] );
            onl[id] = true;

            if (now.size() > k) {
                now.erase(now.begin() );
            }
        }
        else {
            if ( onl[id] == true ) {
                if ( (*now.begin() ) <= lev[id] ) {
                    printf("YES\n");
                    continue;
                }
            }
            printf("NO\n");
        }

    }
    return 0;
}