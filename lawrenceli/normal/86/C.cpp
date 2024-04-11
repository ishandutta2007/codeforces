#include <bits/stdc++.h>

using namespace std;

char dna[4] = {'A', 'C', 'G', 'T'};

const int maxn = 1005;
const int mod = 1e9 + 9;

int n, m;
string s[11];
string suf[105]; int sze;

int maxs[105]; //corresponds to a match
int nxt[105][4], nxtl[105][4];

int match(string a, string b) {
    int k = b.length();
    if (k > a.length()) return -1;
    if (a.substr(a.length() - k, k) != b) return -1;
    return k;
}

void initsuf() {
    for (int i = 0; i < sze; i++)
        for (int j = 0; j < 4; j++) {
            string t = suf[i] + dna[j];
            int best = -1, bi = 0;
            for (int k = 0; k < sze; k++) {
                int len = match(t, suf[k]);
                if (len > best) {
                    best = len;
                    bi = k;
                }
            }
            nxtl[i][j] = best;
            nxt[i][j] = bi;
        }

    for (int i = 0; i < sze; i++)
        for (int j = 0; j < m; j++)
            if (match(suf[i], s[j]) != -1)
                maxs[i] = max(maxs[i], int(s[j].length()));
}

int dp[maxn][105][11];

void add(int& a, int b) { a = (a + b) % mod; }

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    suf[sze++] = "";
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++)
            suf[sze++] = s[i].substr(0, j + 1);
    }

    sort(suf, suf + sze);
    sze = unique(suf, suf + sze) - suf;
    assert(suf[0] == "");
    
    initsuf();

    //for (int i = 0; i < sze; i++) cout << suf[i] << ' ' << good[i] << endl;

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < sze; j++)
            for (int k = 0; k < 10; k++) {
                int v = dp[i][j][k];
                if (!v) continue;
                assert(suf[j].length() >= k);
                for (int c = 0; c < 4; c++) {
                    int l = nxtl[j][c], j2 = nxt[j][c];
                    if (k + 1 <= l) {
                        if (maxs[j2] >= k + 1) add(dp[i + 1][j2][0], v);
                        else add(dp[i + 1][j2][k + 1], v);
                    }
                }
            }

    int ans = 0;
    for (int j = 0; j < sze; j++) add(ans, dp[n][j][0]);
    cout << ans << '\n';
}