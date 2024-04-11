#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 30;

vector<int> _mul(const vector<int> &a, const vector<int> &b) {
    int n = (int) a.size();
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = b[a[i]];
    }
    return c;
}

bool check(const vector<int> &p, const vector<int> &c) {
    int n = (int) p.size();
    vector<int> used(n);
    for (int s = 0; s < n; s++) {
        if (used[s])
            continue;
        int color = -1, ok = 1;
        for (int x = s; !used[x]; used[x] = 1, x = p[x]) {
            if (color == -1)
                color = c[x];
            else if (color != c[x])
                ok = 0;
        }
        if (ok)
            return true;
    }
    return false;
}

const int MAXN = 2e5 + 5;

vector<int> dv[MAXN];

void precalc() {
    for (int x = 2; x < MAXN; x++) {
        for (int y = x; y < MAXN; y += x) {
            dv[y].push_back(x);
        }
    }
}

int find_min(const vector<int> &cycle) {
    int res = inf;
    int n = (int) cycle.size();
    for (int p : dv[n]) {
        for (int i = 0; i < p; i++) {
            int ok = 1;
            for (int j = i; j < n; j += p)
                ok &= (cycle[j] == cycle[i]);
            if (ok) {
                res = min(res, p);
                break;
            }
        }
    }
    return res;
}

int find_ans(const vector<int> &p, const vector<int> &c) {
    int n = (int) p.size();
    vector<int> used(n);
    int res = inf;
    for (int s = 0; s < n; s++) {
        if (used[s])
            continue;
        vector<int> cycle;
        for (int x = s; !used[x]; used[x] = 1, cycle.push_back(c[x]), x = p[x]);
        res = min(res, find_min(cycle));
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    if (check(p, c)) {
        cout << "1\n";
        return;
    }
    cout << find_ans(p, c) << "\n";
}

int main() {

    precalc();

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    for (int ti = 0; ti < tt; ti++) {
        solve();
    }

    return 0;
}