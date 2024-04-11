#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int pr[max_n];
int sz[max_n];

int n, m;
pair<pair<int, int>, pair<int, int>> f;

set<pair<pair<int, int>, pair<int, int>>> e;

int get_set(int cur) {
    return pr[cur] == cur ? cur : cur = get_set(pr[cur]);
}

void unite(int a, int b) {
    int pa = get_set(a);
    int pb = get_set(b);
    if (sz[pa] > sz[pb]) {
        pr[pb] = pa;
        sz[pa] += sz[pb];
    } else {
        pr[pa] = pb;
        sz[pb] += sz[pa];
    }
}

bool check(int val) {
    f.F.F = val;
    /////
    e.insert(f);
    /////
    for (int i = 0; i < n; ++i) {
        sz[i] = 1;
        pr[i] = i;
    }
    for (auto c : e) {
        int a = c.S.F, b = c.S.S;
        bool added;
        if (get_set(a) != get_set(b)) {
            added = true;
            unite(a, b);
        } else {
            added = false;
        }
        if (c.F.S == 0) {
            e.erase(f);
            return added;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    cin >> f.S.F >> f.S.S >> f.F.F;
    f.F.S = 0;
    --f.S.S;
    --f.S.F;
    for (int i = 1; i < m; ++i) {
        pair<pair<int, int>, pair<int, int>> c;
        scanf("%d%d%d", &c.S.F, &c.S.S, &c.F.F);
        --c.S.S;
        --c.S.F;
        c.F.S = i;
        e.insert(c);
    }
    ll l = 0, r = 1000000001;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}