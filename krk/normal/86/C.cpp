#include <bits/stdc++.h>
using namespace std;

const int K = 4;
const int Maxn = 1005;
const string acgt = "ACGT";
const int mod = 1000000009;

int ind[26];

struct Vertex {
    int next[K];
    int leaf = 0;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ind[ch - 'A'];
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = max(t[v].leaf, int(s.length()));
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
        t[v].leaf = max(t[v].leaf, t[t[v].link].leaf);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ind[ch - 'A'];
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int n, m;
string s;
int cur, dp[2][Maxn][Maxn];

int main()
{
    for (int i = 0; i < acgt.size(); i++)
        ind[acgt[i] - 'A'] = i;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        add_string(s);
    }
    dp[cur][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10; j++)
            for (int k = 0; k < t.size(); k++) if (dp[cur][j][k]) {
                int ways = dp[cur][j][k];
                dp[cur][j][k] = 0;
                for (int d = 0; d < 4; d++) {
                    int nk = go(k, acgt[d]);
                    int nj = j + 1;
                    get_link(nk);
                    if (t[nk].leaf >= nj) nj = 0;
                    dp[!cur][nj][nk] = (dp[!cur][nj][nk] + ways) % mod;
                }
            }
        cur = !cur;
    }
    int res = 0;
    for (int k = 0; k < t.size(); k++)
        res = (res + dp[cur][0][k]) % mod;
    printf("%d\n", res);
    return 0;
}