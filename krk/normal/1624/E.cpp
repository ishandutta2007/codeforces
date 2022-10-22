#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 1005;

char tmp[Maxn];
int T;
int n, m;
map <string, ii> twos, threes;
int dp[Maxn];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        twos.clear(); threes.clear();
        for (int i = 0; i < n; i++) {
            string s; Read(s);
            for (int j = 0; j < s.length(); j++) {
                if (j + 2 <= s.length())
                    twos[s.substr(j, 2)] = ii(i + 1, j + 1);
                if (j + 3 <= s.length())
                    threes[s.substr(j, 3)] = ii(i + 1, j + 1);
            }
        }
        fill(dp, dp + m + 1, 0);
        string s; Read(s);
        dp[0] = 1;
        for (int i = 0; i < m; i++) if (dp[i]) {
            if (i + 2 <= m) {
                auto it = twos.find(s.substr(i, 2));
                if (it != twos.end())
                    dp[i + 2] = 2;
            }
            if (i + 3 <= m) {
                auto it = threes.find(s.substr(i, 3));
                if (it != threes.end())
                    dp[i + 3] = 3;
            }
        }
        int v = m;
        if (!dp[v]) printf("-1\n");
        else {
            vector <iii> res;
            while (v > 0) {
                int len = dp[v];
                v -= dp[v];
                ii wh = len == 2? twos[s.substr(v, 2)]: threes[s.substr(v, 3)];
                res.push_back(iii(ii(wh.second, wh.second + len - 1), wh.first));
            }
            printf("%d\n", int(res.size()));
            for (int i = int(res.size()) - 1; i >= 0; i--)
                printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
        }
    }
    return 0;
}