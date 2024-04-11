#include<bits/stdc++.h>
using namespace std;
int const nax = 5010;
int n, d, p[nax];

int lv[nax], dep[nax];
pair<int, int> q[nax];
int topQ ;

void solve () {
    scanf("%d %d", &n, &d);
    if ( 2 * d > (n * (n - 1))) {
        puts("NO");
        return ;
    }
    int res = n - 1;
    int m = 0;
    int mdep = 0;
    fill(lv , lv + 1 + n , 0);

    for (int i = 2 ; i <= n ; ++ i) {
        p[i] = i / 2;
        dep[i] = dep[i / 2] + 1;
        mdep = max(mdep, dep[i]);
        m += dep[i];
        if (lv[dep[i]] == 0) lv[dep[i]] = i;
    }
    if (d < m) {
        puts("NO");
        return ;
    }

    puts("YES");
    d -= m;

    if (d > 0 && (n != (1 << (__lg(n))))) {
        -- d;
        lv[++ mdep] = n;
        p[n] = lv[mdep - 1];
    }
    topQ = 0;
    for (int i = n - 1 ; i > 1 ; i --) {
        if (i != (1 << (__lg(i)) ))
            q[topQ ++] = make_pair(i, dep[i]);
    }
    int cur = 0;
    while (d > 0 ) {
        auto now = q[cur ++];
        int v = now.first;
        int lev = now.second;
        int canput = mdep - lev + 1;
        if (d > canput) {
            lv[++ mdep] = v;
            p[v] = lv[mdep - 1];
            d -= canput;
            continue;
        }
        int tar = lev + d - 1;
        p[v] = lv[tar];
        break;
    }
    for (int i = 2 ; i <= n ; ++ i)
        printf("%d ", p[i]);
    printf("\n");
}



int main  () {
    int T ;
    cin >>  T;
    for (int i = 1 ; i <= T  ;  ++ i) {
        solve ();
    }
}