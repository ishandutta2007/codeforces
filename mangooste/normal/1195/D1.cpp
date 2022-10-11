#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    // #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back

const ll MOD = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<ll> power(21);
    power[0] = 1;
    for (int i = 1; i < 21; i++)
        power[i] = (power[i - 1] * 10) % MOD;
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &el : a)
        cin >> el;
    vector<vector<ll>> func(11, vector<ll>(n));
    for (int len = 1; len < 11; len++)
        for (int i = 0; i < n; i++) {
            string cur = a[i];
            ll cur_ans = 0;
            for (int j = 0; j < len && j < cur.size(); j++) {
                cur_ans += power[2 * j] * (cur[cur.size() - 1 - j] - '0');
                cur_ans %= MOD;
            }
            for (int j = len; j < cur.size(); j++) {
                cur_ans += power[2 * len + j - len] * (cur[cur.size() - 1 - j] - '0');
                cur_ans %= MOD;
            }
            func[len][i] = cur_ans;
        }
    vector<vector<ll>> sm(11, vector<ll>(11));
    for (int i = 0; i < n; i++)
        for (int len = 1; len < 11; len++) {
            sm[a[i].size()][len] += func[len][i];
            sm[a[i].size()][len] %= MOD;
        }
    vector<int> cnt(11, 0);
    for (auto el : a)
        cnt[el.size()]++;
    debug(func[1][0]);
    debug(func[2][0]);
    debug(func[3][0]);
    debug(func[1][1]);
    debug(func[2][1]);
    debug(func[3][1]);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int len = 1; len < 11; len++) {
            ll cur_ans = 0;
            ll cur_cnt = cnt[len];
            ll cur_sm = sm[len][a[i].size()];
            for (int j = 0; j < len && j < a[i].size(); j++) {
                cur_ans += power[2 * j + 1] * (a[i][a[i].size() - 1 - j] - '0');
                cur_ans %= MOD;
            }
            for (int j = len; j < a[i].size(); j++) {
                cur_ans += power[2 * len + j - len] * (a[i][a[i].size() - 1 - j] - '0');
                cur_ans %= MOD;
            }
            cur_ans %= MOD;
            ans += cur_ans * cur_cnt + cur_sm;
            ans %= MOD;
        }
    cout << ans << '\n';
}