#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
vector<int> a[nax];

int deg[nax];
int pa[nax];
bool sp[nax];


void dfs_parent (int nod, int pa) {
    ::pa[nod] = pa;

    for (int i : a[nod]) {
        if (i == pa) continue;
        dfs_parent(i, nod);
    }
}

int even, odd;

void dfs (int nod, int pa, int dist) {

    if (sp[nod]) {
        if (dist % 2 == 0) {
        even ++ ;
        } else ++ odd;
    }

    for (int i : a[nod]) {
        if (i == pa) continue;
        if (deg[i] > 0) dfs(i, nod, dist + 1);
    }
}

int main () {
    scanf("%d", &n);

    for (int i = 1 ; i < n;  ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);

        ++ deg[u];
        ++ deg[v];
    }

    int ans_max = n - 1;
    int root = -1;

    for (int i = 1 ; i <= n; ++ i) {
        if (deg[i] > 1) {
            root = i;
            break;
        }
    }

    if (root == -1) throw;

    dfs_parent(root, 0);

    vector<int> lf;
    for (int i = 1 ; i <= n; ++ i) {
        if (deg[i] == 1)
            lf.push_back(i);
    }

    for (int i : lf) {
        deg[pa[i]] -- ;
        deg[i] -- ;
        sp[pa[i]] = true;
    }


    int ct = 0;
    for (int i = 1 ; i <= n;  ++ i)
        ct += sp[i];

   // fprintf(stderr, "lf = %d ct = %d\n", (int)lf.size(), ct);
    ans_max -= (int)lf.size();
    ans_max += ct;

    dfs(root, 0, 0);

    int ans_min = (even == 0 || odd == 0) ? 1 : 3;

    printf("%d %d\n", ans_min, ans_max);
}
/*
    Good Luck
        -Lucina
*/