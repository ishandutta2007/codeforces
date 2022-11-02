#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

const int maxn = 505;
const int maxm = 100100;

int n, m, x0, y0;
bool used[maxn][maxn];
char s[maxm];
int l;
int ans[maxm];

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> x0 >> y0 >> s;
    l = strlen(s);

    int cnt = 0;
    for (int i = 0; i < l; i++) {
        if (!used[x0][y0]) ans[i] = 1, cnt++, used[x0][y0] = 1;
        if (s[i] == 'U') x0--;
        else if (s[i] == 'D') x0++;
        else if (s[i] == 'L') y0--;
        else y0++;

        if (x0 < 1) x0 = 1;
        else if (x0 > n) x0 = n;
        if (y0 < 1) y0 = 1;
        else if (y0 > m) y0 = m;
    }

    for (int i = 0; i < l; i++) cout << ans[i] << ' ';
    cout << n * m - cnt << '\n';
}