#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
int n;
vector <int> a[nax];
vector <int> dep[nax];

pair <int, int> ask (const vector <int> &to_ask) {
    printf("? %d", int(to_ask.size()));
    for (int i : to_ask)
        printf(" %d", i);
    puts("");
    fflush(stdout);
    int x, y;
    scanf("%d %d", &x, &y);
    return make_pair(x, y);
}


void answer (int a, int b) {
    printf("! %d %d\n", a, b);
    fflush(stdout);
    static char buf[64];
    scanf("%s", buf);
    assert(buf[0] == 'C');
}

void dfs (int nod, int parent, int depth) {
    dep[depth].push_back(nod);
    for (int i : a[nod]) {
        if (i != parent) dfs(i, nod, depth + 1);
    }
}

void solve () {
    scanf("%d", &n);
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector <int> all(n);
    iota(all.begin(), all.end(), 1);
    auto [root, d] = ask(all);
    dfs(root, 0, 0);

    int l = d / 2, r = d, ans = -1, hidden = -1;

    while (l <= r) {
        int mid = l + r >> 1;
        if (dep[mid].empty()) {
            r = mid - 1;
            continue;
        }

        auto [x, dist] = ask(dep[mid]);
        if (dist == d) {
            ans = mid;
            hidden = x;
            l = mid + 1;
        } else r = mid - 1;
    }

    for (int i = 0 ; i <= n ; ++ i)
        dep[i].clear();

    dfs(hidden, 0, 0);
    int other = ask(dep[d]).first;

    answer(hidden, other);
}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ;) {
        solve();
        for (int i = 0 ; i <= n ; ++ i)
            a[i].clear(), dep[i].clear();
    }
}
/**
1
10
6 7
2 8
8 9
4 3
1 3
6 10
5 9
10 2
5 4

9 6
*/