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

map<pair<pii, pii>, int> mem;

int ask(int x1, int y1, int x2, int y2) {
    x1++, y1++, x2++, y2++;
    if (x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2);
    if (mem.count({{x1, y1}, {x2, y2}})) {
        return mem[{{x1, y1}, {x2, y2}}];
    }
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int res;
    cin >> res;
    return mem[{{x1, y1}, {x2, y2}}] = res;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, -1));
    queue<pii> q;

    a[0][0] = 1;
    a[n - 1][n - 1] = 0;

    auto push = [&]() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == -1) continue;
                q.push({i, j});
            }
        }

        while (!q.empty()) {
            int vi, vj;
            tie(vi, vj) = q.front();
            q.pop();
            for (int di = -2; di <= 2; di++) {
                for (int dj = -2; dj <= 2; dj++) {
                    if (abs(di) + abs(dj) != 2) continue;
                    int ti = vi + di;
                    int tj = vj + dj;
                    if (ti < 0 || ti >= n || tj < 0 || tj >= n) continue;
                    if (a[ti][tj] != -1) continue;
                    if ((ti > vi && tj < vj) || (vi > ti && vj < tj)) continue;
                    a[ti][tj] = ask(ti, tj, vi, vj) ^ 1 ^ a[vi][vj];
                    q.push({ti, tj});
                }
            }
        }
    };

    auto show = [&]() {
        cout << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    };

    push();

//    show();

    int li = -1, lj = -1;
    int ok = 0;
    for (int i = 0; i < n && !ok; i++) {
        for (int j = 0; j < n && !ok; j++) {
            if ((i + j) % 2) continue;
            li = i;
            lj = j;
//            if (i - 1 >= 0 && j + 2 < n && a[i - 1][j + 1] != a[i][j + 2]) {
//                a[i - 1][j + 2] = a[i][j] ^ 1 ^ ask(i - 1, j, i, j + 2);
//                ok = 1;
//            }
//            if (i + 2 < n && j - 1 >= 0 && a[i + 1][j - 1] != a[i + 2][j]) {
//                a[i + 2][j - 1] = a[i][j] ^ 1 ^ ask(i, j - 1, i + 2, j);
//                ok = 1;
//            }
//            if (i + 1 < n && j - 2 >= 0 && a[i][j - 2] != a[i + 1][j - 1]) {
//                a[i + 1][j - 2] = a[i][j] ^ 1 ^ ask(i, j - 2, i + 1, j);
//                ok = 1;
//            }
//            if (i - 2 >= 0 && j + 1 < n) {
//                a[i - 2][j + 1] = a[i][j] ^ 1 ^ ask(i - 2, j, i, j + 1);
//                ok = 1;
//            }
            if (i - 1 >= 0 && j - 2 >= 0 && a[i][j - 2] != a[i - 1][j - 1]) {
                a[i - 1][j - 2] = a[i][j] ^ 1 ^ ask(i - 1, j - 2, i, j);
                ok = 1;
                break;
            }
            if (i - 2 >= 0 && j - 1 >= 0 && a[i - 2][j] != a[i - 1][j - 1]) {
                a[i - 2][j - 1] = a[i][j] ^ 1 ^ ask(i - 2, j - 1, i, j);
                ok = 1;
                break;
            }
            if (i + 1 < n && j + 2 < n && a[i][j + 2] != a[i + 1][j + 1]) {
                a[i + 1][j + 2] = a[i][j] ^ 1 ^ ask(i, j, i + 1, j + 2);
                ok = 1;
                break;
            }
            if (i + 2 < n && j + 1 < n && a[i + 1][j + 1] != a[i + 2][j]) {
                a[i + 2][j + 1] = a[i][j] ^ 1 ^ ask(i, j, i + 2, j + 1);
                ok = 1;
                break;
            }
        }
    }

    for (int i = 0; i + 2 < n && !ok; i++) {
        if (a[i][i] && a[i + 1][i + 1] && !a[i + 2][i + 2]) {
            if (ask(i + 1, i, i + 2, i + 1)) {
                a[i + 1][i] = ask(i, i, i + 2, i + 1);
            } else {
                a[i + 1][i] = !ask(i + 1, i, i + 2, i + 2);
            }
            ok = 1;
            break;
        }
        if (a[i][i] && !a[i + 1][i + 1] && !a[i + 2][i + 2]) {
            if (!ask(i + 1, i, i + 2, i + 1)) {
                a[i + 2][i + 1] = ask(i, i, i + 2, i + 1);
            } else {
                a[i + 1][i] = !ask(i + 1, i, i + 2, i + 2);
            }
            ok = 1;
            break;
        }
    }

//    cout << "(" << li << ", " << lj << ")\n";

//    show();

    push();

//    show();

    push();

    cout << "!" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}