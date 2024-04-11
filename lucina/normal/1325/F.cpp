#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

vector<int> a[nax];
int n, m;

int deg[nax];
bool vis[nax];
bool del[nax];
int where[nax];

vector<int> ind_set;

int main () {

    scanf("%d %d", &n, &m);

    int sq = sqrt(n);

    if (sq * sq < n) ++ sq;

    for (int i = 1 ; i <= m ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);

        a[u].push_back(v);
        a[v].push_back(u);

        ++ deg[u] ; ++ deg[v];

    }


    priority_queue< pair <int, int>, vector< pair< int, int>> , greater< pair< int, int>> > q;

    for (int i = 1 ; i <= n ; ++ i) {
        q.emplace(deg[i], i);
    }

    while (!q.empty()) {
        pair <int, int> x = q.top();
        q.pop();

        if (del[x.second]) continue;

        if (x.first >= sq - 1) {



            vector<int> path;



            path.push_back(x.second);

            vis[x.second] = true;
            where[x.second] = 0;

            while (true) {

                int s = path.back();

                bool vis_all = true;
                for (int j : a[s]) {
                    if (del[j] || vis[j]) continue;
                    path.push_back(j);
                    where[j] = (int)path.size() - 1;
                    vis[j] = true;
                    vis_all = false;
                    break;
                }

                if (vis_all) {

                    int left_most = INT_MAX;
                    for (int j : a[s]) {
                        if (del[j]) continue;
                        left_most = min(left_most, where[j]);
                    }
                    printf("2\n");

                    printf("%d\n", (int)path.size() - left_most);

                    for (int j = left_most ; j < (int)path.size() ; ++ j)
                        printf("%d ", path[j]);
                    return 0;
                    /// assert(is_valid_cycle(path));

                    return 0;
                }
            }

        }

        for (int i : a[x.second]) {
            if (!del[i]) {
                del[i] = true;
                for (int v : a[i]) {
                    if (del[v]) continue;
                    deg[v] --;
                    q.emplace(deg[v], v);
                }
            }
        }

        del[x.second] = true;
        ind_set.push_back(x.second);
    }

    printf("1\n");

    for (int j = 0 ; j < sq ; ++ j) {
        printf("%d ", ind_set[j]);
    }
}
/*
    Good Luck
        -Lucina
*/