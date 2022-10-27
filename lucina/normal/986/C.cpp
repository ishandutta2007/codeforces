#include<bits/stdc++.h>
using namespace std;
const int nax = (1 << 22) + 10;
int n, m;
bool vis[nax << 1];
int q[nax << 1];
bool has[nax];

void bfs (int start) {
    int topQ = 0;
    q[topQ ++] = start;

    vis[start] = true;

    //puts("BFS");
    for (int _i = 0 ; _i < topQ ; ++ _i) {
        int x = q[_i];
        if (x < (1 << n)) {
            if (!vis[x + (1 << n)]) {
                q[topQ ++] = x + (1 << n);
                vis[x + (1 << n)] = true;
            }
        } else {
            int a = x - (1 << n);
            int complement = (1 << n) - 1 - a;
            if (!vis[complement] && has[complement]) {
                q[topQ ++] = complement;
                vis[complement] = true;
            }
            for (int i = 0 ; i < n ; ++ i) {
                if (!(a >> i & 1)) {
                    int g = (a | (1 << i)) + (1 << n);
                    if (!vis[g]) {
                        q[topQ ++] = g;
                        vis[g] = true;
                    }
                }
            }
        }
    }
}

int main () {
    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= m ; ++ i) {
        int x;
        scanf("%d", &x);
        has[x] = true;
    }

    int ans = 0;

    for (int i = 0 ; i < (1 << n) ; ++ i) {
        if (!vis[i] && has[i]) bfs(i), ++ ans;
    }

    printf("%d\n", ans);
}