#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 10;
const int BUBEN = 25;
int n, m;
ll t;
int s;
int f[maxN];
int par[maxN];
pair < int, int > now[maxN];
int val_sq[maxN];
int get_par(int i) {
    if (i == par[i]) return i;
    par[i] = get_par(par[i]);
    return par[i];
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += n;
    return s;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= n) s -= n;
    return s;
}
void build_stupid() {
    vector  < int > all;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        f[i] = i;
        now[i] = make_pair(-1, -1);
        all.push_back(i);
    }
    for (int i = 1; i < n; i++) {
        vector < int > nall;
        for (int v : all) {
            if (f[v] < m) {
                f[v] = sub(f[v], i);
            }
            else {
                f[v] = sum(f[v], i);
            }
            if (now[f[v]].first != i) {
                now[f[v]] = make_pair(i, v);
                nall.push_back(v);
            }
            else {
                int cur = now[f[v]].second;
                par[v] = cur;
            }
        }
        swap(all, nall);
    }
    for (int i = 0; i < n; i++) {
        get_par(i);
        f[i] = f[par[i]];
    }
}
vector < int > sq[maxN];
int calc_f(int v, int step) {
    if (step == n) return v;
    if (v < m) {
        v = sub(v, step);
        return calc_f(v, step + 1);
    }
    else {
        int new_v = sub(v, val_sq[step - 1]);
        int mn_step = n + 100;
        int opt_pos = -1;
        for (int pos = 0; pos < m; pos++) {
            int need = sub(pos, new_v);
            if (sq[need].empty() || sq[need].back() < step) continue;
            int x = lower_bound(sq[need].begin(), sq[need].end(), step) - sq[need].begin();
            mn_step = min(mn_step, sq[need][x]);
            if (mn_step == sq[need][x]) {
                opt_pos = pos;
            }
        }
        if (opt_pos == -1) {
            return sum(new_v, val_sq[n - 1]);
        }
        else {
            return calc_f(opt_pos, mn_step + 1);
        }
    }
}
int stupid(int i) {
    for (int j = 1; j < n; j++) {
        if (i < m) i = sub(i, j);
        else i = sum(i, j);
    }
    return i;
}
void build_other() {
    for (int i = 0; i < n; i++) {
        int x = ((1LL * i * (i + 1)) / 2) % n;
        val_sq[i] = x;
        sq[x].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        f[i] = calc_f(i, 1);
    }
}
int up[maxN][65];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s >> t;
    s--;
    bool rev = false;
    if (m > n - 1 - m) {
        m = n - m;
        s = n - 1 - s;
        rev = true;
    }
    while (t % n > 0) {
        if (s < m) {
            s = (int)((s + (t % n)) % n);
        }
        else {
            s = (int)((s - (t % n) + n) % n);
        }
        t--;
    }
    if (m > BUBEN) {
        build_stupid();
    }
    else {
        build_other();
    }
    ll steps = t / n;
    for (int i = 0; i < n; i++) {
        up[i][0] = f[i];

    }
    for (int j = 1; j < 63; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for (int i = 62; i >= 0; i--) {
        if ((1LL << i) <= steps) {
            s = up[s][i];
            steps -= (1LL << i);
        }
    }
    if (rev) {
        cout << n - s;
    }
    else {
        cout << s + 1;
    }
    return 0;
}