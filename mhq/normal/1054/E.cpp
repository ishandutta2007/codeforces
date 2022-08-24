#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector < pair < int, int > > ans[2];
const int maxN = 305;
string start[maxN][maxN], en[maxN][maxN];
int st_row[maxN], en_row[maxN], en_col[maxN], st_col[maxN];
int n, m;
string stupid[maxN][maxN];
int qq = 0;
void move(int x1, int y1, int x2, int y2, int num) {
    for (int i = 0; i < num; i++) {
        /*  stupid[x2][y2] = stupid[x1][y1].back() + stupid[x2][y2];
          //cout << stupid[x1][y1];
          stupid[x1][y1].pop_back();

          cout << "AFTER OPERATION" << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

          for (int k = 1; k <= n; k++) {
              for (int jj = 1; jj <= m; jj++) {
                  cout << stupid[k][jj] << " ";
              }
              cout << "\n";
          }
          cout << "--------" << endl;
          qq++;*/
        ans[0].push_back(make_pair(x1, y1));
        ans[1].push_back(make_pair(x2, y2));
    }
}
int len[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //  freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> start[i][j];
            //   stupid[i][j] = start[i][j];
            s += start[i][j].size();
            st_row[i] += start[i][j].size();
            st_col[j] += start[i][j].size();
        }
    }
    // cout << stupid[1][1] << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> en[i][j];
            en_row[i] += en[i][j].size();
            en_col[j] += en[i][j].size();
        }
    }
    /*for (int i = 1; i <= n; i++) {
        cout << st_row[i] << " " << st_col[i] << " " << en_col[i] << " " << en_col[i] << endl;
    }*/
    int ix = 0, iy = 0;
    for (int i = 1; i <= n; i++) {
        if (ix != 0) break;
        for (int j = 1; j <= m; j++) {
            if (en_row[i] + en_col[j] - 2 * en[i][j].size() >= st_row[i] + st_col[j] - 2 * start[i][j].size()) {
                ix = i;
                iy = j;
                break;
            }
        }
    }
    // cout << ix << " " << iy << endl;
    assert(ix > 0);
    int otherx = 1;
    if (ix == otherx) otherx++;
    int othery = 1;
    if (iy == othery) othery++;
    for (int j = 1; j <= m; j++) {
        if (j == iy) continue;
        move(ix, j, otherx, j, start[ix][j].size());
        start[otherx][j] = start[ix][j] + start[otherx][j];
        start[ix][j] = "";
    }
    for (int i = 1; i <= n; i++) {
        if (i == ix) continue;
        move(i, iy, i, othery, start[i][iy].size());
        start[i][othery] = start[i][iy] + start[i][othery];
        start[i][iy] = "";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == ix || j == iy) continue;
            while (!start[i][j].empty()) {
                if (start[i][j].back() == '0') {
                    move(i, j, ix, j, 1);
                    len[ix][j]++;
                    start[i][j].pop_back();
                }
                else {
                    move(i, j, i, iy, 1);
                    len[i][iy]++;
                    start[i][j].pop_back();
                }
            }
        }
    }
    while (!start[ix][iy].empty()) {
        if (start[ix][iy].back() == '0') {
            move(ix, iy, ix, othery, 1);
            len[ix][othery]++;
            start[ix][iy].pop_back();
        }
        else {
            move(ix, iy, otherx, iy, 1);
            len[otherx][iy]++;
            start[ix][iy].pop_back();
        }
    }
    string need = "";
    vector < pair < int, int > > order;
    order.emplace_back(ix, iy);
    need = en[ix][iy];
    for (int i = 1; i <= n; i++) {
        if (i == ix) continue;
        order.emplace_back(i, iy);
        need += en[i][iy];
    }
    for (int j = 1; j <= m; j++) {
        if (j == iy) continue;
        order.emplace_back(ix, j);
        need += en[ix][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == ix || j == iy) continue;
            order.emplace_back(i, j);
            need += en[i][j];
        }
    }
    int cnt = 0;
    string cop_need = need;
    while (!cop_need.empty()) {
        if (cop_need.back() == '0') {
            for (int j = 1; j <= m; j++) {
                if (len[ix][j] > 0) {
                    move(ix, j, ix, iy, 1);
                    len[ix][j]--;
                    break;
                }
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (len[i][iy] > 0) {
                    move(i, iy, ix, iy, 1);
                    len[i][iy]--;
                    break;
                }
            }
        }
        cop_need.pop_back();
    }
    for (int i = order.size() - 1; i >= 1; i--) {
        int x = order[i].first;
        int y = order[i].second;
        if (x != ix && y != iy) {
            move(ix, iy, x, iy, en[x][y].size());
            move(x, iy, x, y, en[x][y].size());
        }
        else if (x == ix) {
            move(ix, iy, ix, y, en[x][y].size());
        }
        else {
            move(ix, iy, x, iy, en[x][y].size());
        }
    }
    cout << ans[0].size() << '\n';
    for (int i = 0; i < ans[0].size(); i++) {
        cout << ans[0][i].first << " " << ans[0][i].second << " " << ans[1][i].first << " " << ans[1][i].second << '\n';
    }
    return 0;
}