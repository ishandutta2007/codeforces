#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
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
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

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

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

//#define int li
//const int mod = 1000000007;

const int C = 20;
vector<vector<int>> g;
vector<int> cnt, max_cnt;
vector<char> used;
vector<int> num;

vector<int> comp;

void dfs1(int v, int p) {
    cnt[v] = 1;
    max_cnt[v] = 0;
    comp.push_back(v);
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        dfs1(to, v);
        cnt[v] += cnt[to];
        max_cnt[v] = max(max_cnt[v], cnt[to]);
    }
}

vector<li> subtree_sum;

int PREF_ADD_TIMER = 1;

vector<int> current_mask;

int pref_add_timer[1 << C];
int pref_add[1 << C];

bool is_palindromic(int mask) {
    return (mask & (mask - 1)) == 0;
}

bool need_add = false;
li root_val = 0;

vector<int> order;

void dfs2(int v, int p, int msk, int msk_with) {
    order.push_back(v);
    msk ^= (1 << num[v]);
    msk_with ^= (1 << num[v]);
    if (is_palindromic(msk_with) && need_add) {
        ++subtree_sum[v];
        ++root_val;
    }
    current_mask[v] = msk;
    for (int i = -1; i < C; ++i) {
        int need_mask = msk;
        if (i >= 0) {
            need_mask ^= (1 << i);
        }
        if (pref_add_timer[need_mask] == PREF_ADD_TIMER) {
            int val = pref_add[need_mask];
            subtree_sum[v] += val;
            if (need_add) {
                root_val += val;
            }
        }
    }
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        dfs2(to, v, msk, msk_with);
    }
}

vector<li> ans;

void dfs3(int v, int p) {
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        dfs3(to, v);
        subtree_sum[v] += subtree_sum[to];
    }
    ans[v] += subtree_sum[v];
}

void kill(int v) {
    if (used[v]) {
        return;
    }
    comp.clear();
    dfs1(v, v);
    int center = -1;
    for (int x : comp) {
        if (max_cnt[x] <= cnt[v] / 2 && cnt[v] - cnt[x] <= cnt[v] / 2) {
            center = x;
            break;
        }
    }
    assert(center != -1);
    v = center;
    used[v] = true;
    vector<int> children;
    for (int to : g[v]) {
        if (!used[to]) {
            children.push_back(to);
        }
    }
    for (int x : comp) {
        subtree_sum[x] = 0;
    }
    root_val = 1;
    for (int w = 0; w < 2; ++w) {
        need_add = w;
        ++PREF_ADD_TIMER;
        for (int to : children) {
            order.clear();
            dfs2(to, v, 0, 1 << num[v]);
            for (int x : order) {
                int mask = (current_mask[x] ^ (1 << num[v]));
                if (pref_add_timer[mask] != PREF_ADD_TIMER) {
                    pref_add_timer[mask] = PREF_ADD_TIMER;
                    pref_add[mask] = 0;
                }
                ++pref_add[mask];
            }
        }
        reverse(all(children));
    }
    ans[v] += root_val;
    for (int to : children) {
        dfs3(to, v);
    }

    /*cout << "center: " << v + 1 << endl;
    for (int i = 0;i < 5; ++i) {
        cout << ans[i] << " \n"[i + 1 == 5];
    }*/

    for (int to : children) {
        kill(to);
    }
}

void solve(bool read) {
    int n;
    //read= false;
    if (read) {
        cin >> n;
    } else {
        n = 200000;
    }
    g.resize(n);
    cnt.resize(n);
    max_cnt.resize(n);
    used.assign(n, false);
    for (int i = 1; i < n; ++i) {
        int a, b;
        if (read) {
            cin >> a >> b;
            --a;
            --b;
        } else {
            a = i;
            b = i - 1;
        }
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string s;
    if (read) {
        cin >> s;
    } else {
        for (int i = 0; i < n; ++i) {
            s += (char)('a' + rand() % 20);
        }
    }
    num.resize(n);
    for (int i = 0; i < n; ++i) {
        num[i] = s[i] - 'a';
    }
    subtree_sum.assign(n, 0);
    ans.assign(n, 0);
    current_mask.resize(n);
    kill(0);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i + 1 == n];
    }

}