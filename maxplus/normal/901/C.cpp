#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

using minimax = pair<int, int>;

constexpr int N = 300001;
constexpr minimax def = {N + 1, -1};

minimax t[4 * N];

minimax recalc(minimax a, minimax b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}

void tset(int x, int key, int ind = 0, int l = 0, int r = N) {
    if (r <= x || l > x) {
        return;
    }
    if (r == l + 1) {
        t[ind] = {key, key};
        return;
    }
    tset(x, key, 2 * ind + 1, l, (l + r) / 2);
    tset(x, key, 2 * ind + 2, (l + r) / 2, r);
    t[ind] = recalc(t[2 * ind + 1], t[2 * ind + 2]);
}

minimax ask(int L, int R, int ind = 0, int l = 0, int r = N) {
    if (r <= L || l >= R) {
        return def;
    }
    if (l >= L && R >= r) {
        return t[ind];
    }
    return recalc(ask(L, R, 2 * ind + 1, l, (l + r) / 2),
                  ask(L, R, 2 * ind + 2, (l + r) / 2, r));
}

int d[N];
vector<int> nei[N];
vector<minimax> pits;

void dfs(int v) {
    tset(d[v], v);
    for (auto u: nei[v]) {
        if (d[u] == -1) {
            d[u] = d[v] + 1;
            dfs(u);
        } else if (d[u] < d[v] - 1) {
            pits.push_back(ask(d[u], d[v] + 1));
        }
    }
}

int rlim[N];
int64_t ssum[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, q;
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < 4 * N; ++i) {
        t[i] = def;
    }
    for (int i = 0; i < m; ++i) {
//        nei[i].push_back(i + 1), nei[i + 1].push_back(i);
        cin >> a >> b;
        nei[--a].push_back(--b), nei[b].push_back(a);
    }
    memset(d, -1, sizeof d);
    for (int i = 0; i < n; ++i) {
        if (d[i] == -1) {
            d[i] = 0;
            dfs(i);
        }
    }
    sort(pits.begin(), pits.end(), [](const minimax &a, const minimax &b) { return a.first < b.first; });
    for (int i = n - 1, j = pits.size() - 1, cr = n; i > -1; --i) {
        while (j >= 0 && pits[j].first == i) {
            cr = min(cr, pits[j--].second);
        }
        rlim[i] = cr;
        ssum[i] = ssum[i + 1] + rlim[i] - i;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l;
        cin >> r;
        --l;
        int L = l - 1, R = r, M;
        while (R > L + 1) {
            M = (L + R) / 2;
            if (rlim[M] >= r) {
                R = M;
            } else {
                L = M;
            }
        }
        cout << ssum[l] - ssum[R] + (r - R) * (r - R + 1ll) / 2 << '\n';
    }
    return 0;
}