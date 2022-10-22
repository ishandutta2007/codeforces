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

vector<vector<int>> fast(int n, vector<int> p) {
    vector<vector<int>> res(n + 1, vector<int>(n + 1)), used(n + 1, vector<int>(n + 1));
    int timer = 1;
    function<void(int, int)> rec = [&](int l, int r) {
        if (l > r)
            return;
        int m = l;
        for (int i = l; i <= r; i++) {
            if (p[i] > p[m])
                m = i;
        }
        timer++;
        for (int i = l; i < m; i++) {
            used[i][i] = timer;
            for (int I = i, J = i, x = p[i] - 1; x > 0; x--) {
                if (J > 1 && !res[I][J - 1] && used[I][J - 1] != timer)
                    J--;
                else
                    I++;
                used[I][J] = timer;
            }
        }
        res[m][m] = p[m];
        for (int I = m, J = m, x = p[m] - 1; x > 0; x--) {
            if (J > 1 && !res[I][J - 1] && used[I][J - 1] != timer)
                J--;
            else
                I++;
            res[I][J] = p[m];
        }
        rec(l, m - 1);
        rec(m + 1, r);
    };
    rec(1, n);
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    auto fs = fast(n, p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << fs[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}