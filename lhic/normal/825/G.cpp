#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int up[1200000];
vector<int> eds[1200000];
int n;
int q;

void dfs1(int v, int d, int p) {
    d = min(d, v);
    up[v] = d;
    for (int u: eds[v]) {
        if (u == p)
            continue;
        dfs1(u, d, v);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        eds[a].push_back(b);
        eds[b].push_back(a);
    }
    int lst = 0;
    int root;
    scanf("%d%d", &lst, &root);
    lst = 0;
    --q;
    dfs1(root, n, -1);
    int cur = root;
    while (q--) {
        int t, x;
        scanf("%d%d", &t, &x);
        x = (x + lst) % n;
        if (t == 1) {
            cur = min(cur, up[x]);
        }
        else {
            lst = min(cur, up[x]) + 1;
            printf("%d\n", lst);
        }
    }
    return 0;
}