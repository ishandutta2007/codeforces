#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10;

int n, m;
vector <int> a[nax];
vector <int> to[nax];
int tar[nax];
int ans[nax];
int top ;
int num[nax];
bool vis[nax];

int main () {

    scanf("%d %d", &n, &m);

    while (m --) {
        int u, v;

        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n ; ++ i) {
        scanf("%d", tar + i);
        to[tar[i]].push_back(i);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (to[i].empty()) continue;

        for (int v : to[i]) {

             if ((int)a[v].size() < i - 1) return !printf("-1");
             fill(vis + 1, vis + i, false);

             int ct = 0;
             for (int u : a[v]) {
                if (num[u] == i) return !printf("-1");
                if (num[u] > 0 && num[u] < i && !vis[num[u]]) {
                    vis[num[u]] = true;
                    ++ ct;
                }
             }

             if (ct != i - 1) return !printf("-1");
             ans[++ top] = v;
           //  printf("%d ", v);
             num[v] = i;
        }
    }

    for (int i = 1 ; i <= top ; ++ i)
        printf("%d ", ans[i]);

}
/*
    Good Luck
        -Lucina
*/