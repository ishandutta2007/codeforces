#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n;
int p[nax];
int f[nax];
int a[nax];
int indeg[nax];
vector <int> g[nax];
int ans[nax];
bool vis[nax];
int at_least[nax];

void go2(int *f) {
    static int buffer[nax];
    for (int i = 1 ; i <= n ; ++ i) {
        buffer[i] = f[f[i]];
    }
    copy(buffer + 1, buffer + 1 + n, f + 1);
}

void go1(int *f) {
    static int buffer[nax];
    for (int i = 1 ; i <= n ; ++ i) {
        buffer[i] = p[f[i]];
    }
    copy(buffer + 1, buffer + 1 + n, f + 1);
}

void go(int *f, int y) {
    if (y == 0) return;
    go(f, y / 2);
    go2(f);
    if (y & 1) go1(f);
}

int main() {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", p + i);
        indeg[p[i]] += 1;
        f[i] = i;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }
    int cnt = count(indeg + 1, indeg + 1 + n, 0);
    int mx = *max_element(a + 1, a + 1 + n);

    int turn = (mx - n) / cnt;
    go(f, turn);

    for (int i = 1 ; i <= n ; ++ i) {
        g[f[i]].push_back(i);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] <= n) {
            ans[g[i][0]] = a[i];
            vis[a[i]] = true;
            for (int t = 1 ; t < g[i].size() ; ++ t) {
                at_least[g[i][t]] = a[i] + 1;
            }
        }
    }


    set <int> setik;
    for (int i = 1 ; i <= n ; ++ i)
        if (!vis[i]) setik.insert(i);
    for (int i = 1 ; i <= n ; ++ i) {
        if (!ans[i]) {
            auto it = setik.lower_bound(at_least[i]);
            ans[i] = *it;
            setik.erase(it);
        }
        printf("%d ", ans[i]);
    }
    printf("\n");

    /**
        after doing boring stuffs above,
        the problem ask about
        assign permutation
        a1, a2, ...., an lexicographically smallest,
        such that a_i >= f(i)
        necessary and sufficient condition
        freq(i) is the number of x f(x) >= i
        Let's say there are g(i) numbers left >= i
        g(i) >= freq(i) for all i,
        you can binary search and check in O(1) whether you can place or not.
    */
}