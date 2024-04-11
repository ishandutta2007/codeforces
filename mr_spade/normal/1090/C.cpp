#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 5e5 + 10;
int n, m, sm, goal[N];
set<int> st[N];
queue<int> S, B;
int tot, px[M], py[M], pz[M];
inline void Ck(int x) {
    if ((int)st[x].size() < goal[x]) S.push(x);
    if ((int)st[x].size() > goal[x]) B.push(x);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, k, x; i <= n; ++i) {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            scanf("%d", &x);
            st[i].insert(x);
        }
        sm += k;
    }
    int small = sm / n, big = small + 1, big_num = sm % n, small_num = n - big_num;
    for (int i = 1; i <= n; ++i) {
        if (!big_num || (small_num && (int)st[i].size() <= small)) {
            --small_num;
            goal[i] = small;
        } else {
            --big_num;
            goal[i] = big;
        }
    }
    for (int i = 1; i <= n; ++i) Ck(i);
    while (!S.empty()) {
        int u = S.front(), v = B.front(); S.pop(); B.pop();
        vector<int> del;
        for (set<int>::iterator it = st[u].begin(); it != st[u].end(); ++it) {
            set<int>::iterator nit = st[v].find(*it);
            if (nit != st[v].end()) {
                del.push_back(*nit);
                st[v].erase(nit);
            }
        }
        while ((int)st[u].size() < goal[u] && (int)st[v].size() + (int)del.size() > goal[v]) {
            ++tot; px[tot] = v; py[tot] = u; pz[tot] = *st[v].begin();
            st[u].insert(pz[tot]);
            st[v].erase(st[v].begin());
        }
        for (vector<int>::iterator it = del.begin(); it != del.end(); ++it)
            st[v].insert(*it);
        Ck(u); Ck(v);
    }
    assert(B.empty());
    printf("%d\n", tot);
    for (int i = 1; i <= tot; ++i) 
        printf("%d %d %d\n", px[i], py[i], pz[i]);
    return 0;
}