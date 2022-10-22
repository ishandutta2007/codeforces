#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 200005;
const int Maxl = 20;

char tmp[Maxl + 5];
int n;
string s[Maxn];
int mask[Maxn];
int m;
int add;
int best[Maxl + 1][1 << Maxl];

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Read(s[i]);
        for (int j = 0; j < s[i].length(); j++)
            mask[i] = 2 * mask[i] + int(s[i][j] - '0');
        m = s[i].length();
    }
    fill((int*)best, (int*)best + (Maxl + 1) * (1 << Maxl), Inf);
    best[0][0] = m;
    for (int i = 1; i < n; i++) {
        int nw = Inf;
        for (int j = 0; j <= m; j++)
            nw = min(nw, best[j][mask[i] >> (m - j)] + m - j);
        int sam = m;
        while ((mask[i - 1] & ((1 << sam) - 1)) != (mask[i] >> (m - sam))) sam--;
        int sh = m - sam;
        for (int j = 0; j <= m; j++) {
            int nmask = (mask[i - 1] & ((1 << j) - 1));
            best[j][nmask] = min(best[j][nmask], nw - sh);
        }
        add += sh;
    }
    int res = Inf;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j < 1 << i; j++)
            res = min(res, best[i][j]);
    res += add;
    cout << res << endl;
    return 0;
}