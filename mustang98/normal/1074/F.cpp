#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 400111, inf = 1000111222, max_log = 22;

int tin[max_n];
int tout[max_n];
int sz[max_n];
int curt1 = 0;
int curt2 = 0;
vector<int> v[max_n];
int n;
int p[max_n][max_log];

void dfs(int cur, int pr) {
    p[cur][0] = pr;
    for (int l = 0; l < max_log; ++l) {
        if (p[cur][l] != -1 && p[p[cur][l]][l] != -1) {
            p[cur][l + 1] = p[p[cur][l]][l];
        }
    }
    sz[cur] = 1;
    tin[cur] = curt1++;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pr) continue;
        dfs(to, cur);
        sz[cur] += sz[to];
    }
    tout[cur] = curt2++;
}

bool is_pr(int a, int b) {
    if (a == -1) return true;
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

struct segment_tree{
    int mx[max_n * 4];
    int cnt[max_n * 4];
    int ost[max_n * 4];

    void build(int cur, int l, int r) {
        if (l == r) {
            cnt[cur] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
        cnt[cur] = cnt[cur * 2] + cnt[cur * 2 + 1];
    }

    void push(int cur, int l, int r) {
        if (l == r) {
            mx[cur] += ost[cur];
            cnt[cur] = 1;
            ost[cur] = 0;
            return;
        }
        mx[cur] += ost[cur];
        ost[cur * 2] += ost[cur];
        ost[cur * 2 + 1] += ost[cur];
        ost[cur] = 0;
    }

    void add(int cur, int l, int r, int ql, int qr, int val) {
        push(cur, l, r);
        if (l == ql && r == qr) {
            ost[cur] += val;
            push(cur, l, r);
            return;
        }
        if (qr < l || ql > r) {
            return;
        }
        int mid = (l + r) / 2;
        add(cur * 2, l, mid, ql, min(mid, qr), val);
        add(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr, val);
        if (mx[cur * 2] == mx[cur * 2 + 1]) {
            mx[cur] = mx[cur * 2];
            cnt[cur] = cnt[cur * 2] + cnt[cur * 2 + 1];
        } else if (mx[cur * 2] > mx[cur * 2 + 1]) {
            mx[cur] = mx[cur * 2];
            cnt[cur] = cnt[cur * 2];
        } else {
            mx[cur] = mx[cur * 2 + 1];
            cnt[cur] = cnt[cur * 2 + 1];
        }
    }

    pair<int, int> get(int cur, int l, int r, int ql, int qr) {
        push(cur, l, r);
        if (l == ql && r == qr) {
            return MP(mx[cur], cnt[cur]);
        }
        if (qr < l || ql > r) {
            return MP(-inf, 1);
        }
        int mid = (l + r) / 2;
        pair<int, int> al = get(cur * 2, l, mid, ql, min(mid, qr));
        pair<int, int> ar = get(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr);
        if (al.F == ar.F) {
            return MP(al.F, al.S + ar.S);
        } else if (al.F > ar.F) {
            return al;
        } else {
            return ar;
        }
    }
} st;
set<pair<int, int> > s;

int get_ch(int a, int b) {
    for (int l = max_log - 1; l > 0; --l) {
        if (!is_pr(p[b][l - 1], a)) {
            b = p[b][l - 1];
        }
    }
    return b;
}

void add(int a, int b) {
    //cout << "AA" << endl;
    if (is_pr(a, b)) {
        int ch = get_ch(a, b);
        st.add(1, 0, n - 1, 0, n - 1, 1);
        st.add(1, 0, n - 1, tin[ch], tin[ch] + sz[ch] - 1, -1);
        st.add(1, 0, n - 1, tin[b], tin[b] + sz[b] - 1, 1);
    } else if (is_pr(b, a)) {
        int ch = get_ch(b, a);
        st.add(1, 0, n - 1, 0, n - 1, 1);
        st.add(1, 0, n - 1, tin[ch], tin[ch] + sz[ch] - 1, -1);
        st.add(1, 0, n - 1, tin[a], tin[a] + sz[a] - 1, 1);
    } else {
        st.add(1, 0, n - 1, tin[a], tin[a] + sz[a] - 1, 1);
        st.add(1, 0, n - 1, tin[b], tin[b] + sz[b] - 1, 1);
    }
}

void rem(int a, int b) {
   // cout << "RR" << endl;
    if (is_pr(a, b)) {
        int ch = get_ch(a, b);
        st.add(1, 0, n - 1, 0, n - 1, -1);
        st.add(1, 0, n - 1, tin[ch], tin[ch] + sz[ch] - 1, 1);
        st.add(1, 0, n - 1, tin[b], tin[b] + sz[b] - 1, -1);
    } else if (is_pr(b, a)) {
        int ch = get_ch(b, a);
        st.add(1, 0, n - 1, 0, n - 1, -1);
        st.add(1, 0, n - 1, tin[ch], tin[ch] + sz[ch] - 1, 1);
        st.add(1, 0, n - 1, tin[a], tin[a] + sz[a] - 1, -1);
    } else {
        st.add(1, 0, n - 1, tin[a], tin[a] + sz[a] - 1, -1);
        st.add(1, 0, n - 1, tin[b], tin[b] + sz[b] - 1, -1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i){
        for (int j = 0; j < max_log; ++j) {
            p[i][j] = -1;
        }
    }
    int q;
    cin >> n >> q;
    st.build(1, 0, n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(0, -1);
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        if (a > b) {
            swap(a, b);
        }
        if (s.find({a, b}) == s.end()) {
            s.insert({a, b});
            add(a, b);
        } else {
            s.erase(s.find({a, b}));
            rem(a, b);
        }
        pair<int, int> ans = st.get(1, 0, n - 1, 0, n - 1);
        if (ans.first == s.size()) {
            printf("%d\n", ans.S);
        } else {
            printf("0\n");
        }
    }
    return 0;
}