#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10;

struct query {
    int l, r, id;

    query () {}
    query (int l, int r, int id) : l(l), r(r), id(id) {}
};

int find_point (int x, int y, int l, int r) {
    int mid = x + y >> 1;
    if (l >= x && l <= mid && r <= y && r >= mid + 1) {
        return mid;
    } else {
        if (r <= mid) return find_point(x, mid, l, r);
        else if (l > mid) return find_point(mid + 1, y, l ,r);
        else assert(false);
    }
    throw;
}

int ans[nax];
int c[nax];
int n, nq;

vector <query> q[nax];

bool ins (int * basis, int x) {

    for (int j = 20 ; j >= 0 ; -- j) {
        if (!(x >> j & 1)) continue;
        if (basis[j] == -1) {
            basis[j] = x;
            return true;
        } else {
            x ^= basis[j];
        }
    }

    return x > 0;
}

int get_max (int * basis) {
    int res = 0;

    for (int j = 20 ; j >= 0 ; -- j) {
        if (basis[j] == -1) continue;
        if (!(res >> j & 1)) res ^= basis[j];
    }

    return res;
}

int l_basis[22];
int r_basis[22];
int l_important[25];
int r_important[25];
int all_basis[22];

void divide_and_conquer (int l, int r) {
    if (l == r) return ;

    int mid = l + r >> 1;
    divide_and_conquer(l, mid);
    divide_and_conquer(mid + 1, r);

    memset(l_basis, -1, sizeof(l_basis));
    memset(r_basis, -1, sizeof(r_basis));

    int top_l = 0, top_r = 0;

    for (int i = mid ; i >= l ; -- i) {
        if (ins(l_basis, c[i])) {
            l_important[++ top_l] = i;
        }
    }

    for (int i = mid + 1 ; i <= r ; ++ i) {
        if (ins(r_basis, c[i])) {
            r_important[++ top_r] = i;
        }
    }

    for (auto [l, r, id] : q[mid]) {
        memset(all_basis, -1, sizeof(all_basis));

        for (int k = 1 ; k <= top_l ; ++ k) {
            if (l_important[k] < l) break;
            else ins(all_basis, c[l_important[k]]);
        }

        for (int k = 1 ; k <= top_r ; ++ k) {
            if (r_important[k] > r) break;
            else ins(all_basis, c[r_important[k]]);
        }

        ans[id] = get_max(all_basis);
    }

}

int main () {

    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", c + i);
    }

    scanf("%d", &nq);

    for (int i = 1 ; i <= nq ; ++ i) {
        query q;
        scanf("%d %d", &q.l, &q.r);
        q.id = i;

        if (q.l == q.r) {
            ans[i] = c[q.l];
        } else {
            int mid_point = find_point(1, n, q.l, q.r);
            ::q[mid_point].push_back(q);
        }
    }

    divide_and_conquer(1, n);

    for (int i = 1 ; i <= nq ; ++ i) {
        printf("%d\n", ans[i]);
    }
}