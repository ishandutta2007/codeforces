#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int const C = 300000;
using ll = long long ;

ll glob_ans;

int n;
ll ans[nax];
int * where[nax * 64];
int val[nax * 64];
int top;
int par[nax << 1];
int sz_x[nax << 1], sz_y[nax << 1];

int find_par (int x) {
    return par[x] == x? x : find_par(par[x]);
}

void rollback () {
    *where[top] = val[top];
    -- top;
}

inline void change (int &from, int to) {
    ++ top;

    where[top] = &from;
    val[top] = from;
    from = to;
}

void unite (int a, int b) {
    a = find_par(a);
    b = find_par(b);

    if (a == b) return ;

    glob_ans -= 1LL * sz_x[a] * sz_y[a];
    glob_ans -= 1LL * sz_x[b] * sz_y[b];

    if (sz_x[a] + sz_y[a] < sz_x[b] + sz_y[b]) swap(a, b);
    change(par[b], a);
    change(sz_x[a], sz_x[a] + sz_x[b]);
    change(sz_y[a], sz_y[a] + sz_y[b]);

    glob_ans += 1LL * sz_x[a] * sz_y[a];
}

void init_dsu () {

    for (int i = 1 ; i <= C ; ++ i) {
        sz_x[i] = 1;
        par[i] = i;
    }

    for (int i = C + 1 ; i <= C + C ; ++ i) {
        sz_y[i] = 1;
        par[i] = i;
    }
}

vector < pair <int, int>> sg[nax << 2];

void add (int v, int x, int y, int l, int r, pair < int, int> to_add) {

    if (l > r) return ;

    if (l == x && r == y) {
        sg[v].push_back(to_add);
        return ;
    }

    int mid = x + y >> 1;
  //

    add (v << 1 , x , mid, l, min(r, mid), to_add);
    add (v << 1 ^ 1, mid + 1, y, max(l, mid + 1), r, to_add);
}

void dfs (int v, int l, int r) {

    int prev_top = top;
    ll prev_ans = glob_ans;

    for (pair <int, int> p : sg[v]) {
        unite(p.first, p.second);
    }

    if (l == r) {
        ans[l] = glob_ans;
    } else {
        int mid = l + r >> 1;
        dfs(v << 1, l, mid);
        dfs(v << 1 ^ 1, mid + 1, r);
    }

    while (top != prev_top) rollback();
    glob_ans = prev_ans;

} ///  dfs on segment tree O_O

int main () {

    int q;
    scanf("%d", &q);

    map < pair <int, int>, int > last;
    map < pair <int, int>, int >::iterator it;



    for (int i = 1 ; i <= q ; ++ i) {
        int x, y;
        scanf("%d %d", &x, &y);

        y += C;

        pair <int, int> t = make_pair(x, y);
        it = last.find(t);

        if (it != last.end()) {
            add(1, 1, q, it->second, i - 1, t);
            last.erase(it);
        } else {
            last[t] = i;
        }
    }

    for (auto &i : last) {
        add(1, 1, q, i.second, q, i.first);
    }

    init_dsu();

    dfs(1, 1, q);

    for (int i = 1 ; i <= q ; ++ i) {
        printf("%lld ", ans[i]);
    }
}