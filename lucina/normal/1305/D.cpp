#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
int n, deg[nax];

int ask (int u, int v) {
    printf("? %d %d\n", u, v);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == -1) throw;
    return x;
}

void ans (int x) {
    printf("! %d\n", x);
    fflush(stdout);
    exit(0);
}

int pa[nax];
vector<int> a[nax];

bool rm[nax];

int main () {
    scanf("%d", &n);

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        ++ deg[u];
        ++ deg[v];

        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<int> lf;

    for (int i = 1 ; i <= n ; ++ i) {
        if (deg[i] == 1) {
            lf.push_back(i);
        }
    }

    while (true) {

        if ((int)lf.size() == 1) ans(lf.back());
        int u = lf.back(); lf.pop_back();
        int v = lf.back(); lf.pop_back();

        rm[u] = true;
        rm[v] = true;

        for (int i : a[u]) {
            if (!rm[i]) {
                deg[i] --;
                if (deg[i] == 1) lf.push_back(i);
            }
        }

        for (int i : a[v]) {
            if (!rm[i]) {
                deg[i] -- ;
                if (deg[i] == 1) lf.push_back(i);
            }
        }

        int res = ask(u, v);

        if (res == u || res == v) {
            ans(res);
        }
    }
}