#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxk = 100005;

int n, m;
char B[Maxn][Maxn];
int srow[Maxn][Maxn], scol[Maxn][Maxn];
int k;
char where[Maxk];
int len[Maxk];
vector <char> res;

bool Check(int r, int c)
{
     for (int i = 0; i < k; i++)
        if (where[i] == 'N') {
                     int nr = r - len[i];
                     if (nr < 0 || B[nr][c] == '#' || scol[c][r] - scol[c][nr] > 0) return false;
                     r = nr;
        } else if (where[i] == 'S') {
               int nr = r + len[i];
               if (nr >= n || scol[c][nr] - scol[c][r] > 0) return false;
               r = nr;
        } else if (where[i] == 'E') {
               int nc = c + len[i];
               if (nc >= m || srow[r][nc] - srow[r][c] > 0) return false;
               c = nc;
        } else if (where[i] == 'W') {
               int nc = c - len[i];
               if (nc < 0 || B[r][nc] == '#' || srow[r][c] - srow[r][nc] > 0) return false;
               c = nc;
        }
     return true;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          cin >> B[i][j];
    cin >> k;
    for (int i = 0; i < k; i++)
       cin >> where[i] >> len[i];
    for (int i = 0; i < n; i++) {
        srow[i][0] = B[i][0] == '#';
        for (int j = 1; j < m; j++)
           srow[i][j] = srow[i][j - 1] + (B[i][j] == '#');
    }
    for (int j = 0; j < m; j++) {
        scol[j][0] = B[0][j] == '#';
        for (int i = 1; i < n; i++)
           scol[j][i] = scol[j][i - 1] + (B[i][j] == '#');
    }
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          if ('A' <= B[i][j] && B[i][j] <= 'Z')
             if (Check(i, j)) res.push_back(B[i][j]);
    if (res.empty()) cout << "no solution\n";
    else {
         sort(res.begin(), res.end());
         for (int i = 0; i < res.size(); i++)
            cout << res[i];
         cout << endl;
    }
    return 0;
}