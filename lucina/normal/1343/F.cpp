#include<bits/stdc++.h>
using namespace std;
int const nax = 205;
int n, k[nax];
bool take[nax];
int p[nax];

vector<int> where[nax];

bool try_solve(int f) ;
int c[nax];
int a[nax][nax];

void solve () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i)
        where[i].clear();

    for (int i = 1 ; i < n ; ++ i) {
        scanf("%d", k + i);

        for (int j = 1 ; j <= k[i] ; ++ j) {
            int x;
            scanf("%d", &x);
            a[i][j] = x;
            where[x].push_back(i);
        }
    }

    bool ok = false;

    for (int first_num = 1 ; first_num <= n ; ++ first_num) {
        if (try_solve(first_num)) {
            ok = true;
            break;
        }
    }

    assert(ok);

   // printf("ANS:\n");

    for (int i = 1 ; i <= n ; ++ i) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

bool try_solve (int f) {

    static bool used[nax];
    static int ed[nax];
    p[1] = f;

    for (int i = 1 ; i < n ; ++ i)
        take[i] = false;

    for (int i = 1 ; i <= n ; ++ i) {
        c[i] = k[i];
        used[i] = false;
    }


    used[f] = true;

    for (int j : where[f])
        -- c[j];

    static int seen[nax];
    int top_seen = 0;


    for (int i = 2 ; i <= n ; ++ i) {

        top_seen = 0;
        for (int j = 1 ; j < n ; ++ j) {
            if (take[j]) continue;
            if (c[j] == 1)
                seen[++ top_seen] = j;
        }

        if (top_seen != 1) return false;
        int x = seen[1];

        top_seen = 0;


        for (int j = 1 ; j <= k[x] ; ++ j) {
            if (!used[a[x][j]]) {
                seen[++ top_seen] = a[x][j];
            }
        }

        take[x] = true;
        ed[i] = x;
        if (top_seen != 1) return false;

        used[seen[1]] = true;

        for (int j  : where[seen[1]]) -- c[j];
        p[i] = seen[1];
    }

    for (int i = 2 ; i <= n ; ++ i) {
        int x = ed[i];

        if (i - k[x] + 1 <= 0) return false;

        fill(used + 1, used + 1 + n, false);

        for (int v = i - k[x] + 1 ; v <= i ; ++ v) {
            used[p[v]] = true;
        }

        for (int j = 1 ; j <= k[x] ; ++ j)
            if (!used[a[x][j]]) return false;
    }

    return true;



    return true;

}



int main () {

    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        solve();
    }
}
/**
5
6
3 2 5 6
2 4 6
3 1 3 4
2 1 3
4 1 2 4 6

*/