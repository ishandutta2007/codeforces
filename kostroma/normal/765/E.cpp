#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

void precalc() {

}

//#define int li

//const int mod = 1000000007;

vector<char> used;
vector<int> par;
vector<vector<int>> g;
vector<pair<int, int>> way;

void dfs(int v, int p, int dep) {
    par[v] = p;
    if (g[v].size() == 1) {
        way[v] = {dep, v};
        return;
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v, dep + 1);
    }
    vector<pair<int, int>> children;
    bool have_bad = false;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (way[to].first != -1) {
            children.push_back(way[to]);
        } else {
            have_bad = true;
        }
    }
    if (children.empty()) {
        way[v] = {-1, v};
        return;
    }
    sort(all(children));
    vector<pair<int, int>> res;
    res.push_back(children[0]);
    for (int i = 1; i < children.size(); ++i) {
        if (children[i].first == children[i - 1].first) {
            int cur = children[i].second;
            while (cur != v) {
                used[cur] = true;
                cur = par[cur];
            }
        }
        else {
            res.push_back(children[i]);
        }
    }
    if (res.size() == 1 && !have_bad) {
        way[v] = res[0];
    } else {
        way[v] = {-1, v};
    }
}

bool HAVE_ANS = true;

void dfs2(int v, int p, int have, int dep) {
    if (g[v].size() == 1) {
        return;
    }
    if (g[v].size() == 2) {
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs2(to, v, have + 1, dep + 1);
        }
        return;
    }
    int bad = 0;
    int bad_to = -1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (way[to].first == -1 || way[to].first - dep != have) {
            ++bad;
            bad_to = to;
        } else {
            int cur = way[to].second;
            while (cur != v) {
                used[cur] = true;
                cur = par[cur];
            }
        }
    }
    if (bad > 1) {
        HAVE_ANS = false;
        return;
    }
    dfs2(bad_to, v, have + 1, dep + 1);
}

int get_len(int len) {
    while (len % 2 == 0) {
        len /= 2;
    }
    return len;
}

void solve(bool read) {
    int n;
    cin >> n;
    g.resize(n);
    used.assign(n, false);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 2) {
            root = i;
            break;
        }
    }
    if (root == -1) {
        cout << get_len(n - 1) << endl;
        return;
    }
    par.assign(n, -1);
    way.resize(n);
    dfs(root, root, 0);

    int rest = n;
    vector<vector<int>> new_g(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            for (int to : g[i]) {
                if (!used[to]) {
                    new_g[i].push_back(to);
                }
            }
        } else {
            --rest;
        }
    }
    new_g.swap(g);

    if (way[root].first != -1) {
        cout << get_len(way[root].first) << endl;
        return;
    }

    int bad = 0;
    int bad_to = -1;
    int good_to = -1;
    for (int to : g[root]) {
        if (way[to].first == -1) {
            ++bad;
            bad_to = to;
        } else {
            good_to = to;
        }
    }
    if (bad > 1 || g[root].size() > 2) {
        cout << "-1\n";
        return;
    }
    if (bad == 0) {
        cout << get_len(rest - 1) << endl;
        return;
    }
    int have = ((good_to == -1) ? 0 : way[good_to].first) + 1;
    dfs2(bad_to, root, have, 1);

    if (!HAVE_ANS) {
        cout << "-1\n";
        return;
    }

    rest = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++rest;
        }
    }
    cout << get_len(rest - 1) << endl;

}