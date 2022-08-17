#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
#include <unistd.h>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 100111, max_x = 101, max_c = 12, inf = 1000111222;

int n, q, c;

int cnt[max_c][max_x][max_x];
int cnt_pr[max_c][max_x][max_x];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> q >> c;
    int x, y, s;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> s;
        --x, --y;
        cnt[s][y][x]++;
    }
    for (int curc = 0; curc <= c; ++curc) {
        for (int i = 0; i <= max_x; ++i) {
            for (int j = 0; j <= max_x; ++j) {
                if (i == 0 && j == 0) cnt_pr[curc][i][j] = cnt[curc][i][j];
                else if (i == 0) cnt_pr[curc][i][j] = cnt[curc][i][j] + cnt_pr[curc][i][j - 1];
                else if (j == 0) cnt_pr[curc][i][j] = cnt[curc][i][j] + cnt_pr[curc][i - 1][j];
                else cnt_pr[curc][i][j] = cnt[curc][i][j] + cnt_pr[curc][i-1][j] + cnt_pr[curc][i][j-1] - cnt_pr[curc][i - 1][j-1];
            }
        }
    }
    while (q--) {

        ll ans = 0;
        int i1, j1, i2, j2;
        ll t;
        cin >> t >> j1 >> i1 >> j2 >> i2;
        --i1, --j1, --i2, --j2;
        for (int curc = 0; curc <= c; ++curc) {
            ll cntc = cnt_pr[curc][i2][j2];
            if (i1 && j1) cntc += cnt_pr[curc][i1 - 1][j1 - 1];
            if (i1) cntc -= cnt_pr[curc][i1-1][j2];
            if (j1) cntc -= cnt_pr[curc][i2][j1 - 1];
            ll cur_ans = cntc * ((curc + t) % (c + 1));
            ans += cur_ans;
        }
        cout << ans << endl;
    }
    return 0;

}