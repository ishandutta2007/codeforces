#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

bool check(vector<string> a) {
    int n = (int) a.size();
    int m = (int) a[0].size();
    for (int si = 0; si < n; si++) {
        for (int sj = 0; sj < m; sj++) {
            if (a[si][sj] != 'X')
                continue;
            vector<vector<int>> used(n, vector<int>(m));
            used[si][sj] = 1;
            queue<pii> q;
            q.push({si, sj});
            while (!q.empty()) {
                auto [vi, vj] = q.front();
                q.pop();
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di && dj || !di && !dj)
                            continue;
                        int ti = vi + di;
                        int tj = vj + dj;
                        if (ti < 0 || ti >= n || tj < 0 || tj >= m)
                            continue;
                        if (a[ti][tj] != 'X' || used[ti][tj])
                            continue;
                        used[ti][tj] = 1;
                        q.push({ti, tj});
                    }
                }
            }
            int V = 0, E = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 'X' && !used[i][j])
                        return false;
                    if (a[i][j] != 'X')
                        continue;
                    V++;
                    if (i + 1 < n && a[i + 1][j] == 'X')
                        E++;
                    if (j + 1 < m && a[i][j + 1] == 'X')
                        E++;
                }
            }
            if (V != E + 1)
                return false;
            return true;
        }
    }
    return true;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

//#define TEST

#ifdef TEST
    mt19937 rnd(42);
    const int N = 50;
#endif

    while (t--) {
#ifndef TEST
        int n, m;
        cin >> n >> m;
#else
        int n = rnd() % N + 1;
        int m = rnd() % N + 1;
#endif
        vector<string> a(n), b;
#ifndef TEST
        for (int i = 0; i < n; i++)
            cin >> a[i];
#else
        a.assign(n, string(m, '?'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = '.';
                if (i > 0 && a[i - 1][j] == 'X')
                    continue;
                if (j > 0 && a[i][j - 1] == 'X')
                    continue;
                if (i > 0 && j > 0 && a[i - 1][j - 1] == 'X')
                    continue;
                if (i > 0 && j + 1 < m && a[i - 1][j + 1] == 'X')
                    continue;
                a[i][j] = rnd() % 2 ? 'X' : '.';
            }
        }
        b = a;
        cout << n << " " << m << "\n";
        for (auto x : b)
            cout << x << "\n";
        cout.flush();
#endif
        for (int i = 0; i < n; i += 3)
            for (int j = 0; j < m; j++)
                a[i][j] = 'X';
        for (int i = 0; i + 1 < n; i += 3) {
            if (i + 3 < n) {
                int ok = 0;
                for (int j = 0; j < m; j++) {
                    if (a[i + 1][j] == 'X') {
                        a[i + 2][j] = 'X';
                        ok = 1;
                        break;
                    }
                }
                if (ok)
                    continue;
                for (int j = 0; j < m; j++) {
                    if (a[i + 2][j] == 'X') {
                        a[i + 1][j] = 'X';
                        ok = 1;
                        break;
                    }
                }
                if (ok)
                    continue;
                a[i + 1][0] = a[i + 2][0] = 'X';
            } else if (i + 3 == n) {
                for (int j = 0; j < m; j++) {
                    if (a[i + 2][j] == 'X')
                        a[i + 1][j] = 'X';
                }
            }
        }
        for (auto x : a)
            cout << x << "\n";

#ifdef TEST
        if (!check(a)) {
            cout << "WA\n";
            break;
        } else {
            cout << "OK" << endl;
        }
#endif
    }

    return 0;
}