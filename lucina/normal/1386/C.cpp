#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, m, q;
int sz[nax];
int parent[nax];
int side[nax];

vector <pair <int *, int>> op;


pair <int, int> find (int x) {
    if (x == parent[x]) {
        return make_pair(x, side[x]);
    } else {
        auto v = find(parent[x]);
        return make_pair(v.first, v.second ^ side[x]);
    }
}

void rollback () {
    assert(!op.empty());
    *op.back().first = op.back().second;
    op.pop_back();
}

bool unite (int x, int y) {
    auto u = find(x);
    auto v = find(y);
    if (u.first == v.first) {
        return u.second != v.second;
    }
    if (sz[u.first] < sz[v.first]) {
        swap(u, v);
    }

    op.emplace_back(&parent[v.first], parent[v.first]);
    parent[v.first] = u.first;
    op.emplace_back(&sz[u.first], sz[u.first]);
    sz[u.first] += sz[v.first];

    if (u.second == v.second) {
        op.emplace_back(&side[v.first], side[v.first]);
        side[v.first] ^= 1;
    }

    return true;
}

pair <int, int> e[nax];
int first[nax];

void divide_and_conquer (int l, int r, int opt_L, int opt_R) {
    if (l > r) return ;
   // printf("dnc %d %d %d %d\n", l, r, opt_L, opt_R);
    int mid = l + r >> 1;
    int sz_start = op.size();

    /// assume that you already have information upto [1, l - 1]

    bool ok = true;

    for (int i = l ; i < mid ; ++ i) {
        ok &= unite(e[i].first, e[i].second);
    }

    int sz2 = op.size();
    if (!ok) {
        first[mid] = m + 1;
        for (int i = mid ; i <= r ; ++ i) {
            first[i] = m + 1;
        }
        /// no need to divide any further

    } else {
        int k = opt_R;

        while (k > opt_L) {
            if (k == m + 1) {
                -- k;
            } else {
                if (!unite(e[k].first, e[k].second)) break;
                -- k;
            }
        }

        first[mid] = k;
        while (int(op.size()) != sz2) rollback();
        if (!unite(e[mid].first, e[mid].second)) {
            for (int j = mid + 1 ; j <= r ; ++ j) {
                first[j] = m + 1;
            }
        } else {
            divide_and_conquer(mid + 1, r, first[mid], opt_R);
        }
    }


    while (int(op.size()) != sz_start) rollback();

    for (int i = first[mid] + 1 ; i <= opt_R ; ++ i)
        unite(e[i].first, e[i].second);

    divide_and_conquer(l, mid - 1, opt_L, first[mid]);

    while (int(op.size()) != sz_start) rollback();
}


int main () {
    //cin.tie(0)->sync_with_stdio(false);

    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1 ; i <= m ; ++ i) {
        scanf("%d %d", &e[i].first, &e[i].second);
    }

    fill(sz + 1, sz + 1 + n, 1);
    iota(parent + 1, parent + 1 + n, 1);
    divide_and_conquer(1, m, 1, m + 1);
/*
    for (int i = 1 ; i <= m ; ++ i) {
        printf("%d ", first[i]);
    }
    puts("");*/

    for (; q -- ;) {
        int l, r;
        scanf("%d %d", &l, &r);
        /// exclude [l, first[l]] mean bipartite graph
        if (r >= first[l]) {
            printf("NO\n");
        } else printf("YES\n");
    }
}

/*
1 4
2 4
3 7
4 8
5 8
6 8
7 8
8 9
*/