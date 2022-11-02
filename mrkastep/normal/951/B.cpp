#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll mod = 1e9 + 7;
const ld PI = 3.141592653589793;

struct cube {
    int x;
    int y;
    int id;
};

int t[55][55];

pair<int, int> fin[55];

bool check(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

vector<vector<int>> actions;

pair<int, int> par[55][55];
int st[55][55];

void bfs(int i, int j, int n) {
    for (int ii = 0; ii < n; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
            st[ii][jj] = 0;
        }
    }
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (!check(p.first, p.second, n) || p.first == p.second && p.first < i)
            continue;
        if (t[p.first][p.second]) {
            while (p != make_pair(i, j)) {
                auto pp = par[p.first][p.second];
                actions.push_back({p.first, p.second, pp.first, pp.second});
                swap(t[p.first][p.second], t[pp.first][pp.second]);
                p = pp;
            }
            return;
        }
        if (p.first && !st[p.first - 1][p.second]) {
            q.push({p.first - 1, p.second});
            st[p.first - 1][p.second] = 1;
            par[p.first - 1][p.second] = p;
        }
        if (p.second && !st[p.first][p.second - 1]) {
            q.push({p.first, p.second - 1});
            st[p.first][p.second - 1] = 1;
            par[p.first][p.second - 1] = p;
        }
        if (p.first < n - 1 && !st[p.first + 1][p.second]) {
            q.push({p.first + 1, p.second});
            st[p.first + 1][p.second] = 1;
            par[p.first + 1][p.second] = p;
        }
        if (p.second < n - 1 && !st[p.first][p.second + 1]) {
            q.push({p.first, p.second + 1});
            st[p.first][p.second + 1] = 1;
            par[p.first][p.second + 1] = p;
        }
    }
}

void swp(int i, int j) {
    if (i > j) {
        swp(j, i);
        return;
    }

    for (int ii = i; ii < j; ++ii) {
        actions.push_back({i, ii, i, ii + 1});
    }
    for (int jj = j; jj > i; --jj) {
        actions.push_back({j, jj, j, jj - 1});
    }
    for (int ii = i; ii < j; ++ii) {
        actions.push_back({ii, j, ii + 1, j});
    }
    for (int jj = j; jj > i; --jj) {
        actions.push_back({jj, i, jj - 1, i});
    }

    swap(t[i][i], t[j][j]);
}

void makeRow(int row, int n) {
    int l = n, r = -1;
    for (int i = 0; i < n; ++i) {
        if (t[row][i]) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (l == n) {
        return;
    }

    while (l <= r) {
        if (fin[t[row][l] - 1].second <= l) {
            int target = fin[t[row][l] - 1].second;
            for (int j = l; j > target; --j) {
                actions.push_back({row, j, row, j - 1});
                swap(t[row][j], t[row][j - 1]);
            }
            ++l;
        } else {
            int target = fin[t[row][r] - 1].second;
            for (int j = r; j < target; ++j) {
                actions.push_back({row, j, row, j + 1});
                swap(t[row][j], t[row][j + 1]);
            }
            --r;
        }
    }

}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        t[x][y] = i + 1;
    }

    for (int i = 0; i < m; ++i) {
        cin >> fin[i].first >> fin[i].second;
        --fin[i].first;
        --fin[i].second;
    }

    for (int i = 0; i < m; ++i) {
        bfs(i, i, n);
    }

    vector<int> ind(m);
    for (int i = 0; i < m; ++i)
        ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return fin[i] < fin[j];
    });

    for (int i = 0; i < m; ++i) {
        ++ind[i];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            if (t[j][j] == ind[i]) {
                swp(i, j);
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int j = i;
        int target = fin[t[i][i] - 1].first;
        for (; j < target; ++j) {
            actions.push_back({j, i, j + 1, i});
            swap(t[j][i], t[j + 1][i]);
        }
        for (; j > target; --j) {
            actions.push_back({j, i, j - 1, i});
            swap(t[j][i], t[j - 1][i]);
        }
    }



    for (int i = 0; i < n; ++i)
        makeRow(i, n);

    cout << actions.size() << endl;
    for (auto& v : actions) {
        for (int i : v) {
            cout << i + 1 << ' ';
        }
        cout << endl;
    }
}

void gen() {
    cout << "50 50" << endl;
    for (int i = 0; i < 50; ++i) {
        cout << i / 10 + 1 << ' ' << i % 10 + 1 << endl;
    }
    for (int i = 0; i < 50; ++i) {
        cout << 50 - (i / 10) << ' ' << 50 - (i % 10) << endl;
    }
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);

    solve();
//    gen();
    return 0;
}