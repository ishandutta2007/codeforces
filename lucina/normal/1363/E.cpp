#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

vector <int> a[nax];
int n;
int cost[nax], b[nax], c[nax];

bool is_min[nax];
int ct[2];
long long ans;



int dfs_ans (int nod, int par, int cur_cost) {

    int cb = 0, cc = 0;

    cur_cost = min(cur_cost, cost[nod]);

    if (b[nod] != c[nod]) {
        if (b[nod]) ++ cb;
        else ++ cc;
    }

    for (int i : a[nod]) {
        if (i != par) {
            int res = dfs_ans(i, nod, cur_cost);

            if (res < 0) {
                cc -= res;
            } else cb += res;
        }
    }

    int can = min(cc, cb);

    ans += 2LL * can * cur_cost;

    return cb - cc;

    /**
    sigh
    don't use global count during dfs
    This is one of the most stupid mistake.
    Seems like you can go even more stupid.
    */


}

int main () {

    scanf("%d", &n);

    int x = 0, y = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d %d %d", cost + i, b + i, c + i);

        if (b[i]) ++ x;
        if (c[i]) ++ y;
    }

    for (int i = 1, u, v ; i < n ; ++ i) {
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }


    dfs_ans(1, 0, INT_MAX);

    if (x != y) return !printf("-1");



    printf("%lld\n", ans);
}
/*
    Good Luck
        -Lucina
*/