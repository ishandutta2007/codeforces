#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

struct segment_tree {
    ll add[max_n * 4];

    void add_val(int cur, int l, int r, int ql, int qr, ll val) {
        if (l == ql && r == qr) {
            add[cur] += val;
            return;
        }
        if (l > qr || r < ql) {
            return;
        }
        int mid = (l + r) / 2;
        add_val(cur * 2, l, mid, ql, min(mid, qr), val);
        add_val(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr, val);
    }

    void print(int cur, int l, int r, ll s) {
        s += add[cur];
        if (l == r) {
            printf("%I64d ", s);
            return;
        }

        int mid = (l + r)/ 2;
        print(cur * 2, l, mid, s);
        print(cur * 2 + 1, mid + 1, r, s);
    }

} st;

vector<int> v;
set<pair<int, int>> s;
int w;
int p[max_n];

bool cmp(int a, int b) {
    return v[a] < v[b];
}

pair<int, int> get_range(int ind, int len) {
    return MP(ind, w - (len - ind));
}

void add_range(const pair<int, int>& rn, int val) {
    int l = rn.F, r = rn.S;
    //cout << l << ' ' << r << ' ' << val << endl;
    auto it = s.upper_bound(MP(l, inf));
    int from, to;
    if (it == s.begin()) {
        from = l;
    } else {
        --it;
        from = max(l, it->S + 1);
    }
    if (from > r) {
        return;
    }
    it = s.lower_bound(MP(from, -inf));
    if (it == s.end()) {
        to = r;
    } else {
        to = min(r, it->F - 1);
    }
    if (to < from) {
        return;
    }
    //s.insert(MP(from, to));
    pair<int, int> a(from, to);
    it = s.lower_bound(a);
    if (it != s.begin()) {
        --it;
        if (it->S == from - 1) {
            a.F = it->F;
            s.erase(it);
        }
    }
    it = s.upper_bound(a);
    if (it != s.end()) {
        if (it->F == to + 1) {
            a.S = it->S;
            s.erase(it);
        }
    }
    s.insert(a);
    st.add_val(1, 0, w - 1, from, to, val);
}

void proc() {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    sort(p, p + n, cmp);
    reverse(p, p + n);
    bool was0 = false;
    for (int I = 0; I < n; ++I) {
        int i = p[I];
        if (v[i] < 0 && !was0 && n < w) {
            add_range(get_range(0, n + 1), 0);
            add_range(get_range(n, n + 1), 0);
            was0 = 1;
        }
        add_range(get_range(i, n), v[i]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n >> w;
    for (int i = 0; i < n ;++i) {
        int l;
        scanf("%d", &l);
        for (int j =0 ;j < l; ++j) {
            int a;
            scanf("%d", &a);
            v.PB(a);
        }
        proc();
        v.clear();
        s.clear();
    }
    st.print(1, 0, w - 1, 0);
    return 0;
}