#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 120000;
vector<pair<int, int> > go[MAXN * 4];
int p[MAXN * 4];
int sz[MAXN * 4];
int n, q;
vector<int> st;
vector<int> st2;

void add(int v, int tl, int tr, int l, int r, pair<int, int> x) {
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        go[v].push_back(x);
        return;
    }
    int m = (tl + tr) >> 1;
    add(v * 2 + 1, tl, m, l, r, x);
    add(v * 2 + 2, m, tr, l, r, x);
}

void undo() {
    int x = st.back();
    st.pop_back();
    for (int i = 0; i < x; ++i) {
        int y = st2.back();
        st2.pop_back();
        sz[p[y]] -= sz[y];
        p[y] = y;
    }
}

int get(int a) {
    if (a == p[a])
        return a;
    return get(p[a]);
}

int oth(int a) {
    if (a < 2 * n)
        return a + n;
    else
        return a - n;
}

int add(int a, int b) {
    a = get(a);
    b = get(b);
    if (abs(a - b) == n) {
        st.push_back(0);
        return 1;
    }
    if (a == b) {
        return 0;
    }
    int a2 = oth(a);
    int b2 = oth(b);
    if (sz[a] + sz[a2] < sz[b] + sz[b2])
        swap(a, b), swap(a2, b2);
    swap(b, b2);
    sz[a] += sz[b];
    sz[a2] += sz[b2];
    st2.push_back(b);
    st2.push_back(b2);
    st.push_back(2);
    p[b] = a;
    p[b2] = a2;
    return 1;
}

void run(int v, int l, int r) {
    for (int i = 0; i < go[v].size(); ++i) {
        if (!add(go[v][i].first, go[v][i].second)) {
            for (int j = 0; j < i; ++j)
                undo();
            for (int j = l; j < r; ++j)
                printf("NO\n");
            return;
        }
    }
    if (l + 1 != r) {
        int m = (l + r) >> 1;
        run(v * 2 + 1, l, m);
        run(v * 2 + 2, m, r);
    }
    else {
        printf("YES\n");
    }
    for (int i = 0; i < go[v].size(); ++i)
        undo();
}


map<pair<int, int>, int> mm;
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        if (mm.count(make_pair(a, b))) {
            add(0, 0, q, mm[make_pair(a, b)], i, make_pair(a, b));
            mm.erase(make_pair(a, b));
        }
        else {
            mm[make_pair(a, b)] = i;
        }
    }
    for (auto x: mm)
        add(0, 0, q, x.second, q, x.first);
    for (int i = 0; i < n; ++i)
        p[i] = i + n, sz[i + n] = 1;
    for (int i = n; i < 3 * n; ++i)
        p[i] = i;
    run(0, 0, q);
    return 0;
}