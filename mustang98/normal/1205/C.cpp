#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 50, inf = 1000111222;

int f[max_n][max_n];


bool qr(pair<int, int> from, pair<int, int> to) {
    if (from > to) {
        swap(from, to);
    }
    if (to.S < from.S) {
        exit(228);
    }
    cout << "? " << from.F + 1 << ' ' << from.S + 1 << ' ' << to.F + 1 << ' ' << to.S + 1 << endl;
    //cout << from.F << ' ' << from.S  << ' ' << to.F << ' ' << to.S << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}
bool qr(int i1, int j1, int i2, int j2) {
    return qr(MP(i1, j1), MP(i2, j2));
}

pair<int, int> have = MP(-1, -1);
int n;

int di[] = {0, 0, -2, 2, -1, 1};
int dj[] = {-2, 2, 0, 0, -1, 1};

bool onf(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(have);
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int k = 0; k < 6; ++k) {
            pair<int, int> to = MP(cur.F + di[k], cur.S + dj[k]);
            if (onf(to.F, to.S) && f[to.F][to.S] == -1) {
                if (qr(cur, to)) {
                    f[to.F][to.S] = f[cur.F][cur.S];
                } else {
                    f[to.F][to.S] = !f[cur.F][cur.S];
                }
                q.push(to);
            }
        }
    }
}

void solve0(pair<int, int> s) {
    for (int i = n - 1; i >= 0; --i) {
        if (f[i][i] == 0 && f[i - 1][i - 1] == 0 && f[i - 2][i - 2] == 1) {
            s.F = s.S = i;
            break;
        }
    }
    bool vz = f[s.F - 2][s.F];
    int si = s.F, sj = s.S;
    pair<int, int> x(si - 2, sj - 1);
    pair<int, int> y(si - 1, sj);
    pair<int, int> l(si - 2, sj - 2);

    if (vz == 1) {
        if (qr(x, s)) {
            have = x;
            f[x.F][x.S] = 0;
            return;
        } else {
            have = x;
            f[x.F][x.S] = 1;
            return;
        }
    } else {
        if (qr(l, y)) {
            have = y;
            f[y.F][y.S] = 1;
            return;
        }
        if (qr(x, s)) {
            have = x;
            f[x.F][x.S] = 0;
            return;
        }
        have = x;
        f[x.F][x.S] = 1;
    }
}

void solve1(pair<int, int> s) {
    bool vz = f[s.F][s.F + 2];
    int si = s.F, sj = s.S;
    pair<int, int> x(si, sj + 1);
    pair<int, int> y(si + 1 , sj + 2);
    pair<int, int> r(si + 2, sj + 2);

    if (vz == 0) {
        if (qr(s, y)) {
            have = y;
            f[y.F][y.S] = 1;
            return;
        } else {
            have = y;
            f[y.F][y.S] = 0;
            return;
        }
    } else {
        if (qr(x, r)) {
            have = x;
            f[x.F][x.S] = 0;
            return;
        }
        if (qr(s, y)) {
            have = y;
            f[y.F][y.S] = 1;
            return;
        }
        have = y;
        f[y.F][y.S] = 0;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i][j] = -1;
        }
    }
    f[0][0] = 1;
    f[n - 1][n - 1] = 0;
    have = MP(0, 0);
    bfs();
    have = MP(-1, -1);
    for (int i = n - 1; i - 2 >= 0; --i) {
        if (f[i][i] == 0 && f[i - 1][i - 1] == 0 && f[i - 2][i - 2] == 1) {
            solve0(MP(i, i));
            break;
        }
        if (f[i][i] == 0 && f[i - 1][i - 1] == 1 && f[i - 2][i - 2] == 1) {
            solve1(MP(i - 2, i - 2));
            break;
        }
    }
    if (have == MP(-1, -1)) {
        exit(228);
    }
    bfs();
    cout << "!" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << f[i][j];
        }
        cout << endl;
    }

    return 0;
}