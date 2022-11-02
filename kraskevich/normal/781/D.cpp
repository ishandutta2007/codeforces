#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const ll INF = ll(1e18);
const int N = 512;
const int MAX_POW = 62;

bitset<N> dir[MAX_POW][N];
bitset<N> dirT[MAX_POW][N];
bitset<N> inv[MAX_POW][N];
bitset<N> invT[MAX_POW][N];
int n, m;

void make_step(int p) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            dir[p][i][j] = dir[p][i][j] || (dir[p - 1][i] & invT[p - 1][j]).any(); 
            inv[p][i][j] = inv[p][i][j] || (inv[p - 1][i] & dirT[p - 1][j]).any();
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            dirT[p][j][i] = dir[p][i][j];
            invT[p][j][i] = inv[p][i][j];
        }
}

int get_max_dir(int v, int up) {
    while (up >= 0 && !dir[up][v].any())
        up--;
    return up;
}

int get_max_inv(int v, int up) {
    while (up >= 0 && !inv[up][v].any())
        up--;
    return up;
}

bool was[N];
int max_dir[N];
int max_inv[N];

vector<int> keepMax(const vector<int>& cur, bool flip, int oldPow, int& newPow) {
    fill(was, was + N, false);
    newPow = -1;
    for (int x : cur)
        newPow = max(newPow, flip ? max_inv[x] : max_dir[x]);
    assert (newPow < oldPow);
    if (newPow == -1)
        return {};
    for (int x : cur) {
        int c = flip ? max_inv[x] : max_dir[x];
        if (c == newPow)
            for (int j = 0; j < n; j++)
                if (!flip && dir[c][x][j] || flip && inv[c][x][j])
                    was[j] = true;
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
        if (was[i])
            res.push_back(i);
    return res;
}

ll rec() {
    ll res = 0;
    int curPow = MAX_POW - 1;
    bool flip = false;
    vector<int> cur;
    for (int i = 0; i < n; i++)
        cur.push_back(i);
    while (curPow >= 0) {
        cur = keepMax(cur, flip, curPow, curPow);
        if (curPow < 0)
            break;
        res += 1ll << curPow;
        flip = !flip;
    }
    return res;
}

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        if (t == 0) { 
            dir[0][a].set(b);
            dirT[0][b].set(a);
        } else {
            inv[0][a].set(b);
            invT[0][b].set(a);
        }
    }
    for (int p = 1; p < MAX_POW; p++)
        make_step(p);
    ll res;
    for (int i = 0; i < n; i++) {
        max_dir[i] = get_max_dir(i, MAX_POW - 1);
        max_inv[i] = get_max_inv(i, MAX_POW - 1);
        //cerr << max_dir[i] << " " << max_inv[i] << endl;
    }
    for (int i = 0; i < n; i++)
        if (dir[MAX_POW - 1][i].any()) {
            cout << -1 << endl;
            return 0;
        }
    res = rec();
    if (res > INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
}