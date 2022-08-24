#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector < vector < int > > ans(n, vector < int > (m, -1));
    int c1 = 0;
    int c2 = 1;
    int curX = 0;
    int curY = 0;
    int curEnX = n - 1;
    int curEnY = m - 1;
    while (true) {
        if (ans[curX][curY] == -1) {
            ans[curX][curY] = c1;
            c1 += 2;
            if (curX % 2 == 0) curY++;
            else {
                curY--;
            }
            if (curY < 0) {
                curY = 0;
                curX++;
            }
            else if (curY == m) {
                curY = m - 1;
                curX++;
            }
            if (ans[curEnX][curEnY] == -1) {
                ans[curEnX][curEnY] = c2;
                c2 += 2;
                if ((n - 1 - curEnX) % 2 == 0) curEnY--;
                else curEnY++;
                if (curEnY < 0) {
                    curEnY = 0;
                    curEnX--;
                }
                else if (curEnY == m){
                    curEnY = m - 1;
                    curEnX--;
                }
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }
    vector < pair < int, int > > who(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            assert(ans[i][j] != -1);
            who[ans[i][j]] = make_pair(i, j);
        }
    }
   /* map < pair < int, int >, bool > mp;
    for (int i = 0; i + 1 < n * m; i++) {
        if (mp.count(make_pair(who[i + 1].first - who[i].first, who[i + 1].second - who[i].second))) assert(false);
        mp[make_pair(who[i + 1].first - who[i].first, who[i + 1].second - who[i].second)] = true;
    }*/
    for (int i = 0; i < n * m; i++) {

        cout << who[i].first + 1 << " " << who[i].second + 1 << '\n';
    }
    return 0;
}