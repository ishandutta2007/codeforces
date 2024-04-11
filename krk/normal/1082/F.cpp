#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 505;
const int Maxk = 11;
const int Maxd = 10;
const int Inf = 1000000000;

int n, k;
string s;
int w;

struct trie {
    trie *ch[Maxd];
    int cnt;
    trie() {
        for (int i = 0; i < Maxd; i++)
            ch[i] = nullptr;
        cnt = 0;
    }
};

trie *tr;

void Add(trie *tr, int lvl, const string &s, int add)
{
    if (lvl >= s.length()) {
        tr->cnt += add;
        return;
    }
    int dig = s[lvl] - '0';
    if (!tr->ch[dig]) tr->ch[dig] = new trie();
    Add(tr->ch[dig], lvl + 1, s, add);
}

void Solve(trie *tr, int lvl, int dp[][Maxk])
{
    for (int i = 0; i <= lvl; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = Inf;
        dp[i][0] = (lvl - i) * tr->cnt;
    }
    int my[Maxk];
    for (int j = 0; j <= k; j++)
        my[j] = Inf;
    my[1] = 0;
    int oth[Maxn][Maxk];
    for (int i = 0; i < Maxd; i++) if (tr->ch[i]) {
        Solve(tr->ch[i], lvl + 1, oth);
        for (int l = 0; l <= lvl; l++)
            for (int j = k; j >= 0; j--) {
                int ways = dp[l][j]; dp[l][j] = Inf;
                for (int z = 0; j + z <= k; z++)
                    dp[l][j + z] = min(dp[l][j + z], ways + oth[l][z]);
            }
        for (int j = k; j > 0; j--) {
            int ways = my[j]; my[j] = Inf;
            for (int z = 0; j + z <= k; z++)
                my[j + z] = min(my[j + z], ways + oth[lvl][z]);
        }
    }
    for (int i = 0; i <= lvl; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = min(dp[i][j], my[j]);
}

int main()
{
    tr = new trie();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s >> w;
        Add(tr, 0, s, w);
    }
    int dp[Maxn][Maxk];
    Solve(tr, 0, dp);
    int res = Inf;
    for (int j = 0; j <= k; j++)
        res = min(res, dp[0][j]);
    printf("%d\n", res);
    return 0;
}