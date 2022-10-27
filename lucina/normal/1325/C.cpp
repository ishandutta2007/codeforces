#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
pair<int, int> e[nax];
int n, ans[nax];
vector<int> a[nax];
vector<int> lf;
map <pair <int, int>, int> id;

int main () {
    scanf("%d", &n);
    for (int i = 1 ; i < n;  ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[i] = make_pair(u, v);
        a[u].push_back(v);
        a[v].push_back(u);
        id[minmax(u, v)] = i;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if ((int) a[i].size() == 1) {
            lf.push_back(i);
        }
    }
    if ((int)lf.size() == 2) {
        for (int i = 0 ; i <= n - 2 ; ++ i) {
            printf("%d\n", i);
        }
        return 0;
    }
    fill(ans, ans + n + 1, -1);

    for (int i = 0 ; i < 3 ; ++ i) {
        int u = lf[i], v = a[lf[i]][0];
        int cur = id[minmax(u, v)];
        ans[cur] = i;
    }
    int pt = 3;
    for (int i = 1 ; i < n  ; ++ i) {
        printf("%d\n", ans[i] == -1 ? pt ++ : ans[i]);
    }

}
/*
    Good Luck
        -Lucina
*/