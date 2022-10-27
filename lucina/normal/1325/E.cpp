#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10, lim = 1e6;
int n, a[nax];
int found[lim + 5];
int id[lim + 5];
bool vis[lim + 5];
int ans = numeric_limits<int>::max();

vector<int> b[nax];
vector<int> t;

void add_edge (int u, int v) {
    u = id[u];
    v = id[v];

    b[u].push_back(v);
    b[v].push_back(u);
}


int q[nax], topQ;
int dist[nax][2];

vector<int> prime;

void bfs (int start) {
    topQ = 0;

    for (int i = 0 ; i <= (int)prime.size() + 1 ; ++ i)
        dist[i][0] = dist[i][1] = -1;

    for (int i : b[start]) {
        dist[i][0] = 1;
        dist[i][1] = i;
        q[topQ ++] = i;
    }

    for (int i = 0 ; i < topQ ; ++ i) {
        int u = q[i];

        for (int to : b[u]) {
            if (to == start) continue;
            if (dist[to][0] == -1) {
                dist[to][0] = dist[u][0] + 1;
                dist[to][1] = dist[u][1];
                q[topQ ++ ] = to;
            } else if (dist[to][1] != dist[u][1] ) {
                ans = min(ans, dist[to][0] + dist[u][0] + 1);
            }
        }
    }
}

int d[lim + 1];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", a + i);
    }


    for (int j = 2 ; j <= lim ; ++ j) {
        if (!vis[j]) {
            prime.push_back(j);
            for (int v = j ; v <= lim ; v += j) {
                if (!vis[v]) d[v] = j;
                vis[v] = true;
            }
        }
    }

    int now = 0;
    id[1] = ++ now;
    for (int i : prime) {
        id[i] = ++ now;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        int cur = a[i];
        int t = 0;
        if (cur == 1) return !printf("1");

        vector<int> has;

        while (cur > 1) {
            int x = d[cur];
            int ret = 0;
            do {
                cur /= x;
                ret ^= 1;
            } while(cur % x == 0);

            if (ret) has.push_back(x);
            }
        if ((int) has.size() == 2) {
            add_edge(has[0], has[1]), found[ has[0] * has[1]] ++;
        } else if ((int)has.size() == 1) {
            add_edge(has[0], 1), found[has[0]] ++;
        } else if ((int)has.size() == 0) {
            return !printf("1");
        } else throw;
    }

    for (int j = 1 ; j <= lim ; ++ j) {
        if (found[j] >= 2) return !printf("2");
    }

    for (int i = 1 ; i <= 1000 ; ++ i) {
        int u = id[i];
        if (b[u].empty()) continue;
        bfs(u);
    }

    if (ans > lim) puts("-1");
    else printf("%d\n", ans);
}
/*
    Good Luck
        -Lucina
*/