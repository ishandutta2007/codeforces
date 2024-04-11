#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
char ans[maxN][maxN];
char val[maxN][maxN];
vector < char > all;
void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    int tot = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> val[i][j];
            tot += (val[i][j] == 'R');
        }
    }
    vector < pair < int, int > > path;
    for (int i = 0; i < r; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < c; j++) path.emplace_back(i, j);
        }
        else {
            for (int j = c - 1; j >= 0; j--) path.emplace_back(i, j);
        }
    }
    int cnt_big = (tot) % k;
    int sz_big = (tot + k - 1) / k;
    if (cnt_big == 0) cnt_big = k;
    int where = 0;
    for (int i = 0; i < k; i++) {
        int cnt = 0;
        if (i < cnt_big) cnt = sz_big;
        else cnt = sz_big - 1;
        int cur = 0;
        while (cur < cnt) {
            ans[path[where].first][path[where].second] = all[i];
            if (val[path[where].first][path[where].second] == 'R') cur++;
            where++;
        }
        if (i == k - 1) {
            while (where < path.size()) {
                ans[path[where].first][path[where].second] = all[i];
                where++;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 26; i++) all.emplace_back((char)(i + 'a'));
    for (int i = 0; i < 26; i++) all.emplace_back((char)(i + 'A'));
    for (int i = 0; i < 10; i++) all.emplace_back((char)(i + '0'));
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}