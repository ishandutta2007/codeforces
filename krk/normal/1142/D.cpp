#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <bool, int> bi;

const int Maxd = 11;
const int Maxm = 20;
const int Maxn = 100005;

int nxt[Maxd];
char str[Maxn];
int slen;
bi rang[Maxn][Maxm][Maxd];
ll res;

int main()
{
    nxt[0] = 10;
    for (int i = 1; i < Maxd; i++)
        nxt[i] = (nxt[i - 1] + i - 1) % Maxd;
    scanf("%s", str); slen = strlen(str);
    for (int i = 0; i < slen; i++) {
        int cur = str[i] - '0';
        for (int d = 0; d < Maxd; d++)
            rang[i][0][d] = cur < d? bi(true, (nxt[d] + cur) % Maxd): bi(false, 0);
    }
    for (int j = 1; j < Maxm; j++)
        for (int i = 0; i + (1 << j) <= slen; i++)
            for (int d = 0; d < Maxd; d++)
                if (!rang[i][j - 1][d].first) rang[i][j][d] = bi(false, 0);
                else rang[i][j][d] = rang[i + (1 << j - 1)][j - 1][rang[i][j - 1][d].second];
    for (int t = 0; t < slen; t++) if (str[t] != '0') {
        int cur = str[t] - '0';
        int i = t + 1;
        for (int j = Maxm - 1; j >= 0; j--) if (i + (1 << j) <= slen)
            if (rang[i][j][cur].first) {
                cur = rang[i][j][cur].second;
                i += 1 << j;
            }
        res += i - t;
    }
    cout << res << endl;
    return 0;
}