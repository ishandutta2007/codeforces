#include <bits/stdc++.h>
using namespace std;

const int K = 1005, MX = 14;
const long long INF = 1E18;

int k, c, n;
long long dp[1 << MX][K];
pair<long long, int> tmp[K];
string s, sc[MX];
vector<int> pos;

struct aho_corasick {
    int cnt = 0, kmp[K], ch[K][MX], nxt[K][MX];
    long long dp[K];

    void add(string &s, int c) {
        int cur = 0;
        for (char &c : s) {
            if (ch[cur][c - 'a'] == 0) {
                ch[cur][c - 'a'] = ++cnt;
            }
            cur = ch[cur][c - 'a'];
        }
        dp[cur] += c;
    }

    void BFS() {
        queue<int> q;
        for (q.push(0); !q.empty(); q.pop()) {
            int u = q.front();
            dp[u] += dp[kmp[u]];
            for (int i = 0; i < MX; i++) {
                if (ch[u][i] > 0) {
                    int v = ch[u][i];
                    q.push(v);
                    nxt[u][i] = v;
                    kmp[v] = nxt[kmp[u]][i];
                    if (kmp[v] == v) {
                        kmp[v] = 0;
                    }
                } else {
                    nxt[u][i] = nxt[kmp[u]][i];
                }
            }
        }
    }

    pair<long long, int> traverse(string s, int st) {
        long long ret = 0;
        for (char &c : s) {
            st = nxt[st][c - 'a'];
            ret += dp[st];
        }
        return {ret, st};
    }
} acs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < MX; i++) {
        sc[i] += (char)(i + 'a');
    }
    cin >> k;
    while (k--) {
        cin >> s >> c;
        acs.add(s, c);
    }
    acs.BFS();
    cin >> s; n = s.size();
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '?') {
            pos.push_back(i);
        }
    }
    pos.push_back(n);
    for (int i = 0; i < (1 << MX); i++) {
        fill(dp[i], dp[i] + acs.cnt + 1, -INF);
    }
    auto [val, st] = acs.traverse(s.substr(0, pos[0]), 0);
    dp[0][st] = val;
    for (int i = 1; i < (int)pos.size(); i++) {
        string cur = s.substr(pos[i - 1] + 1, pos[i] - pos[i - 1] - 1);
        for (int prv = 0; prv <= acs.cnt; prv++) {
            tmp[prv] = acs.traverse(cur, prv);
        }
        for (int msk = 0; msk < (1 << MX); msk++) {
            if (__builtin_popcount(msk) == i) {
                for (int ch = 0; ch < MX; ch++) {
                    if (msk >> ch & 1) {
                        for (int prv = 0; prv <= acs.cnt; prv++) {
                            auto [val, st] = acs.traverse(sc[ch], prv);
                            val += tmp[st].first; st = tmp[st].second;
                            dp[msk][st] = max(dp[msk][st], dp[msk ^ (1 << ch)][prv] + val);
                        }
                    }
                }
            }
        }
    }
    long long ans = -INF;
    for (int msk = 0; msk < (1 << MX); msk++) {
        if (__builtin_popcount(msk) == (int)pos.size() - 1) {
            ans = max(ans, *max_element(dp[msk], dp[msk] + acs.cnt + 1));
        }
    }
    cout << ans;
}