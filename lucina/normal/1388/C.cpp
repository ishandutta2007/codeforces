#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = int64_t;
int n, m;
vector <int> a[nax];
ll h[nax];
ll p[nax];
ll happy[nax];
bool ok = true;

void dfs (int nod, int parent) {

    for (int i : a[nod]) {
        if (i != parent) {
            dfs(i, nod);
            happy[nod] += happy[i];
            p[nod] += p[i];
        }
    }

    ll dif = h[nod] - happy[nod];
    /// want ok to be something
    /// p[nod] - 2 * x == dif
    ll x = (p[nod] - dif) / 2;
    if (abs(p[nod] - dif) % 2) ok = false;
    if (x < 0 || x > p[nod]) ok = false;
    happy[nod] += (p[nod] - x);
    p[nod] = x;
    if (p[nod] < 0) ok = false;
}

bool solve () {
    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i)
        scanf("%lld", p + i);
   // assert(accumulate(p + 1, p + 1 + n, 0) == m);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%lld", h + i);

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    fill(happy + 1, happy + 1 + n, 0);
    ok = true;
    dfs(1, 0);
   // if (p[1] != 0) ok = false;
    return ok;
}


int main () {
    int T;

    for (scanf("%d", &T) ; T -- ;) {
        puts(solve() ? "YES" : "NO");

        for (int i = 1 ; i <= n ; ++ i)
            a[i].clear();
    }
}
/*
    Very hard game. :(
*/