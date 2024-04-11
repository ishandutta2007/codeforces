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

#define int li

const int mod = 1000000007;

set<string> have;

void rec(string s, int pos, string our, int len) {
    if (pos == s.length()) {
        if (our.length() == len) {
            have.insert(our);
            //cerr << our << endl;
        }
        return;
    }
    for (int i = 0; i + our.length() <= len; ++i) {
        rec(s, pos + 1, our + string(i, s[pos]), len);
    }
}

void solve(bool read) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    /*s = string(5000, 'a');
    for (int i = 0; i < s.length(); ++i) {
        s[i] = char('a' + rand() % 26);
    }*/

    /*rec(s, 0, "");
    cerr << "have: " << have.size() << endl;

    set<string> used;
    used.insert(s);
    set<string> match;
    match.insert(s);
    while (!used.empty()) {
        auto cur = *used.begin();
        used.erase(used.begin());
        for (int pos = 0; pos < cur.length(); ++pos) {
            if (pos > 0) {
                auto q = cur;
                q[pos - 1] = q[pos];
                if (!match.count(q)) {
                    match.insert(q);
                    used.insert(q);
                }
            }
            if (pos + 1 < cur.length()) {
                auto q = cur;
                q[pos + 1] = q[pos];
                if (!match.count(q)) {
                    match.insert(q);
                    used.insert(q);
                }
            }
        }
    }

    for (auto cur : have) {
        if (!match.count(cur)) {
            cerr << cur << endl;
            return;
        }
    }
    cerr << "match: " << match.size() << endl;*/

    string t;
    for (int i = 0; i < s.length(); ) {
        int j = i;
        while (j < s.length() && s[i] == s[j]) {
            ++j;
        }
        t += s[i];
        i = j;
    }

    /*rec(t, 0, "", s.length());
    cerr << have.size() << endl;*/

    vector<vector<int>> last_dps(26, vector<int>(s.length() + 1, 0));
    vector<int> dp(s.length() + 1, 0);
    vector<int> add_all(s.length() + 1, 0);
    add_all[1] = 1;
    int ans = 0;
    for (int state = 0; state < t.length(); ++state) {
        int c = t[state] - 'a';
        for (int len = 1; len <= s.length(); ++len) {
            dp[len] = (add_all[len] + dp[len - 1] - last_dps[c][len]) % mod;
        }
        for (int len = 1; len <= s.length(); ++len) {
            last_dps[c][len] += dp[len];
            last_dps[c][len] %= mod;
        }
        for (int len = 1; len <= s.length(); ++len) {
            add_all[len] += dp[len - 1];
            add_all[len] %= mod;
        }
        ans = (ans + dp[s.length()]) % mod;
    }
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << "\n";

}