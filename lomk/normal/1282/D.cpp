/*input

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif

// mt19937 rd(0);
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

struct GraderX {
    string ans = "bbbbb";
    // string ans;
    GraderX() {
        // int n = 100;
        // loop(i, 1, n) if (rd() % 2 == 0) ans += "a"; else ans += "b";
    }
    int ask(string sj) {
        auto &si = ans;
        int n = si.size(); int m = sj.size();
        int dp[n + 1][m + 1]; memset(dp, 60, sizeof(dp));
        dp[0][0] = 0;
        loop(i, 0, n) {
            loop(j, 0, m) {
                if (i == j && i == 0) continue;
                if (i >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if (j >= 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                if (i >= 1 && j >= 1) {
                    dp[i][j] = min(dp[i][j], (si[i - 1] != sj[j - 1]) + dp[i - 1][j - 1]);
                }
            }
        }
        // print(si, sj, dp[n][m]);
        return dp[n][m];
    }
} Grader;

map<string, int> cache;
int ask(string inp) {
    if (cache.find(inp) != cache.end()) return cache[inp];
    int ret;
#ifdef UncleGrandpa
    ret = Grader.ask(inp);
#else
    cout << inp << endl;
    cin >> ret;
#endif
    if (ret == 0) exit(0);
    cache[inp] = ret;
    return ret;
}

string genStr(char c, int rep) {
    string ret; loop(i, 1, rep) ret += c;
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    const int LIM = 300;
    string cur = genStr('a', LIM);
    auto reca = ask(cur);

    cur = genStr('b', LIM);
    auto recb = ask(cur);

    const int numa = 300 - reca; const int numb = 300 - recb;
    const int len = numa + numb;
    cur = genStr('a', len);
    int curAns = numb; // when string is "a" * len
    string ans;
    loop(i, 0, len - 1) {
        if (i == len - 1) {
            int cura = 0;
            for (auto it : ans) cura += (it == 'a');
            if (cura < numa) ans += 'a';
            else ans += 'b';
            break;
        }
        cur[i] = 'b';
        if (ask(cur) < curAns) ans += 'b';
        else ans += 'a';
        cur[i] = 'a';
    }
    ask(ans);
    assert(false);
    exit(0);
}