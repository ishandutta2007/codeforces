#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 5000;
const int Maxd = 4;
const string dir = "LURD.";

struct pos {
       int c;
       pair <int, int> to[Maxd];
};

int n, m;
vector <pos> B[Maxn];
int res, cnt;

void Try(int r, int c, int col)
{
     if (r == -1 || c == -1) {
           if (col == res) cnt++;
           else if (col > res) { res = col; cnt = 1; }
     } else {
            for (int i = 0; i < Maxd; i++) {
                pair <int, int> p = B[r][c].to[i];
                if (p.first != -1 && p.second != -1) 
                   B[p.first][p.second].to[(i + 2) % Maxd] = B[r][c].to[(i + 2) % Maxd];
            }
            int wh = B[r][c].c;
            Try(B[r][c].to[wh].first, B[r][c].to[wh].second, col + 1);
            for (int i = 0; i < Maxd; i++) {
                pair <int, int> p = B[r][c].to[i];
                if (p.first != -1 && p.second != -1)
                   B[p.first][p.second].to[(i + 2) % Maxd] = make_pair(r, c);
            }
     }
}

int main()
{
    cin >> n >> m; cin.ignore();
    for (int i = 0; i < n; i++) {
        B[i].resize(m);
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            B[i][j].c = dir.find(c);
        }
    }
    // Precomputation
    for (int i = 0; i < n; i++) {
        int st = -1;
        for (int j = 0; j < m; j++)
            if (B[i][j].c != Maxd) { B[i][j].to[0] = make_pair(i, st); st = j; }
        st = -1;
        for (int j = m - 1; j >= 0; j--)
            if (B[i][j].c != Maxd) { B[i][j].to[2] = make_pair(i, st); st = j; }
    }
    for (int j = 0; j < m; j++) {
        int st = -1;
        for (int i = 0; i < n; i++)
            if (B[i][j].c != Maxd) { B[i][j].to[1] = make_pair(st, j); st = i; }
        st = -1;
        for (int i = n - 1; i >= 0; i--)
            if (B[i][j].c != Maxd) { B[i][j].to[3] = make_pair(st, j); st = i; }
    }
    // Calculation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j].c != Maxd) Try(i, j, 0);
    cout << res << " " << cnt << endl;
    return 0;
}