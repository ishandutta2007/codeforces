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

const int SHIFT = 100500;
char buf[2 * SHIFT + 10];
vector<pair<int, int>> poses[26];
vector<char> used;
vector<string> s;
int L, R;

bool is_add(int id, int pos, int start_pos) {
    int buf_pos = start_pos;
    for (int j = pos; j >= 0; --j) {
        if (buf_pos < L) {
            buf[buf_pos] = s[id][j];
            --L;
        } else if (buf[buf_pos] != s[id][j]) {
            return false;
        }
        --buf_pos;
    }
    buf_pos = start_pos;
    for (int j = pos; j < s[id].length(); ++j) {
        if (buf_pos >= R) {
            buf[buf_pos] = s[id][j];
            ++R;
        } else if (buf[buf_pos] != s[id][j]) {
            return false;
        }
        ++buf_pos;
    }
    return true;
}

void solve(bool read) {
    int n;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); ++j) {
            int c = s[i][j] - 'a';
            if (!poses[c].empty() && poses[c].back().first == i) {
                cout << "NO\n";
                return;
            }
            poses[c].push_back({i, j});
        }
    }
    used.assign(n, false);
    vector<string> ans;
    for (int start = 0; start < n; ++start) {
        if (used[start]) {
            continue;
        }
        //cout << start << endl;
        used[start] = true;
        for (int i = 0; i < s[start].length(); ++i) {
            buf[SHIFT + i] = s[start][i];
        }
        L = SHIFT, R = SHIFT + (int) s[start].length();
        int l = L, r = L;
        while (true) {
            if (l == L && r == R) {
                break;
            }
            while (r < R) {
                int c = buf[r] - 'a';
                while (!poses[c].empty()) {
                    auto cur = poses[c].back();
                    poses[c].pop_back();
                    int id = cur.first;
                    int pos = cur.second;
                    used[id] = true;
                    if (!is_add(id, pos, r)) {
                        cout << "NO\n";
                        return;
                    }
                }
                ++r;
            }
            while (l > L) {
                --l;
                int c = buf[l] - 'a';
                while (!poses[c].empty()) {
                    auto cur = poses[c].back();
                    poses[c].pop_back();
                    int id = cur.first;
                    int pos = cur.second;
                    used[id] = true;
                    if (!is_add(id, pos, l)) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }

        string cur;
        for (int i = L; i < R; ++i) {
            cur += buf[i];
        }
        ans.push_back(cur);
    }

    sort(all(ans));

    string result;
    for (auto& x : ans) {
        result += x;
    }

    map<char, int> mapa;
    for (char c : result) {
        ++mapa[c];
        if (mapa[c] > 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << result << "\n";

}