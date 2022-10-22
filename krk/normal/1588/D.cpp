#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxl = 52;
const int Maxn = 10;
const int Maxm = 1 << Maxn;
const int Maxs = Maxl * Maxm;
const int Maxlen = 1000;

int T;
int n;
char str[Maxn][Maxlen];
int slen[Maxn];
vector <int> my[Maxl][Maxn];
int un[Maxs];
int mp[Maxs];
ii dp[Maxs];
char res[Maxlen];

char toChar(int x)
{
    if (x < 26) return x + 'a';
    else return x - 26 + 'A';
}

int toInt(char ch)
{
    return islower(ch)? ch - 'a': ch - 'A' + 26;
}

bool Less(const int &a, const int &b)
{
    int i1 = a / (1 << n), i2 = b / (1 << n);
    int mask1 = a % (1 << n), mask2 = b % (1 << n);
    if (i1 == i2)
        for (int i = 0; i < n; i++)
            if (bool(mask1 & 1 << i) != bool(mask2 & 1 << i))
                return bool(mask1 & 1 << i) < bool(mask2 & 1 << i);
    return my[i1][0][bool(mask1 & 1)] < my[i2][0][bool(mask2 & 1)];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < Maxl; j++)
                my[j][i].clear();
            scanf("%s", str[i]);
            slen[i] = strlen(str[i]);
            for (int j = 0; j < slen[i]; j++)
                my[toInt(str[i][j])][i].push_back(j);
        }
        int sz = 0;
        for (int i = 0; i < Maxl; i++)
            for (int mask = 0; mask < 1 << n; mask++) {
                bool ok = true;
                for (int j = 0; j < n && ok; j++)
                    ok = my[i][j].size() > int(bool(mask & 1 << j));
                if (ok) un[sz++] = i * (1 << n) + mask;
            }
        sort(un, un + sz, Less);
        for (int i = 0; i < sz; i++)
            mp[un[i]] = i;
        fill(dp, dp + sz, ii(1, -1));
        ii mx = ii(0, 0);
        int wth = 0;
        for (int i = 0; i < sz; i++) {
            int let = un[i] / (1 << n);
            int mask = un[i] % (1 << n);
            for (int j = 0; j < Maxl; j++) {
                int mask2 = 0;
                bool ok = true;
                for (int z = 0; z < n && ok; z++) {
                    int nd = my[let][z][bool(mask & 1 << z)];
                    if (my[j][z].empty() || my[j][z].back() <= nd) { ok = false; continue; }
                    if (my[j][z][0] <= nd) mask2 |= 1 << z;
                }
                if (!ok) continue;
                int u = j * (1 << n) + mask2;
                int ind = mp[u];
                assert(i < ind);
                dp[ind] = max(dp[ind], ii(dp[i].first + 1, i));
            }
            if (dp[i] > mx) {
                mx = dp[i];
                wth = i;
            }
        }
        int rep = mx.first;
        int rlen = 0;
        printf("%d\n", rep);
        while (rep--) {
            res[rlen++] = toChar(un[wth] / (1 << n));
            wth = dp[wth].second;
        }
        reverse(res, res + rlen);
        res[rlen] = '\0';
        printf("%s\n", res);
    }
    return 0;
}