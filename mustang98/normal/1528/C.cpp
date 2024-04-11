#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;
/*
struct segment_tree {
    int val[max_n * 4];
    void clr(int n) {
        for (int i = 0; i < n * 4; ++i) {
            val[i] = -1;
        }
    }

    void set(int cur, int l, int r, int ql, int qr, int x) {
        if (l == ql && r == qr) {
            val[cur] = x;
            return;
        }
        if (ql > r || qr < l) {
            return;
        }
        int mid = (l  + r) / 2;
        set(cur * 2, l, mid, ql, min(mid, qr));
        set(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr);
    }

    int get(int cur, int l, int r, int pos) {
        if (val[cur] != -1) {
            return val[cur];
        }
        if (l == r) {
            return -1;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            return get(cur * 2, l, mid, pos);
        } else {
            return get(cur * 2 + 1, mid + 1, r, pos);
        }
    }
} st;*/

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T sum[4 * max_n];

    void clr(int n) {
        for (int i = 0; i < n * 4; ++i) {
            f[i] = 0;
            sum[i] = 0;
        }
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            sum[2 * v] += f[v] * (mid - l + 1);
            sum[2 * v + 1] += f[v] * (r - mid);
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            sum[v] += value * (r - l + 1);
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

segment_tree<ll> st;

vector<int> va[max_n];
vector<int> vb[max_n];
int n;
int start[max_n];
int sz[max_n];
int curt = 0;
int ans = 0;
int max_ans = 0;

void clr() {
    curt = 0;
    ans = 0;
    max_ans = 0;
    for (int i =0 ; i < n; ++i) {
        va[i].clear();
        vb[i].clear();
    }
    st.clr(n);
}

void dfs(int cur) {
    sz[cur] = 1;
    start[cur] = curt++;
    for (int to : vb[cur]) {
        dfs(to);
        sz[cur] += sz[to];
    }
}

int rem = -1, sett = -1;

void revert(int rem, int sett) {
    if (sett != -1) {
        st.update(1, 0, n - 1, start[sett], start[sett] + sz[sett] - 1, -(sett + 1));
    }
    if (rem != -1) {
        st.update(1, 0, n - 1, start[rem], start[rem] + sz[rem] - 1, rem + 1);
    }
}

void add(int cur) {
    rem = -1, sett = -1;
    int l = start[cur], r = start[cur] + sz[cur] - 1;
    int val = st.get_sum(1, 0, n - 1, l, l);
    --val;
    if (val != -1) {
        //st.update(1, 0, n - 1, start[val], start[val] + sz[val] - 1, -(val + 1));
        //st.update(1, 0, n - 1, start[cur], start[cur] + sz[cur] - 1, cur + 1);
        revert(cur, val);
        rem = val;
        sett = cur;
        return;
    }
    if (st.get_sum(1, 0, n - 1, l, r) != 0) {
        return;
    }
    st.update(1, 0, n - 1, start[cur], start[cur] + sz[cur] - 1, cur + 1);
    sett = cur;
}



void dfs_solve(int cur) {
    add(cur);
    int cur_rem = rem;
    int cur_set = sett;
    if (cur_rem != -1) --ans;
    if (cur_set != -1) ++ans;
    if (ans > max_ans) {
        max_ans = ans;
    }
    for (int to : va[cur]) {
        dfs_solve(to);
    }
    if (cur_rem != -1) ++ans;
    if (cur_set != -1) --ans;
    revert(cur_rem, cur_set);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        scanf("%d", &n);
        clr();
        for (int i = 1; i < n; ++i) {
            int a;
            scanf("%d", &a);
            --a;
            va[a].PB(i);
        }
        for (int i = 1; i < n; ++i) {
            int a;
            scanf("%d", &a);
            --a;
            vb[a].PB(i);
        }
        dfs(0);
        dfs_solve(0);
        printf("%d\n", max_ans);
    }

    return 0;
}