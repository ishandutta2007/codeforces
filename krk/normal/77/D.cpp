#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxd = 7;
const int Maxn = 255;
const int mod = 1000000007;

vector <string> pic[2][Maxd];
int n, m;
string B[4 * Maxn];
bool v[Maxn][Maxn], h[Maxn][Maxn];
int best[2][Maxn];

void Prepare()
{
     pic[0][0].push_back("..."); pic[0][0].push_back("..."); pic[0][0].push_back("...");
     pic[0][1].push_back("..."); pic[0][1].push_back(".O."); pic[0][1].push_back("...");
     pic[0][2].push_back("..O"); pic[0][2].push_back("..."); pic[0][2].push_back("O..");
     pic[0][3].push_back("..O"); pic[0][3].push_back(".O."); pic[0][3].push_back("O..");
     pic[0][4].push_back("O.O"); pic[0][4].push_back("..."); pic[0][4].push_back("O.O");
     pic[0][5].push_back("O.O"); pic[0][5].push_back(".O."); pic[0][5].push_back("O.O");
     pic[0][6].push_back("O.O"); pic[0][6].push_back("O.O"); pic[0][6].push_back("O.O");
     pic[1][0] = pic[0][0]; pic[1][1] = pic[0][1];
     pic[1][2].push_back("O.."); pic[1][2].push_back("..."); pic[1][2].push_back("..O");
     pic[1][3].push_back("O.."); pic[1][3].push_back(".O."); pic[1][3].push_back("..O");
     pic[1][4] = pic[0][4]; pic[1][5] = pic[0][5];
     pic[1][6].push_back("OOO"); pic[1][6].push_back("..."); pic[1][6].push_back("OOO"); 
}

bool checkPic(int wh, const vector <string> &V)
{
     for (int i = 0; i < Maxd; i++)
        if (V == pic[wh][i]) return true;
     return false;
}

void getBoard()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i <= 4 * n; i++)
       cin >> B[i];
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) {
           vector <string> tmp;
           for (int l = 1; l <= 3; l++)
              tmp.push_back(B[4 * i + l].substr(4 * j + 1, 3));
           v[i][j] = checkPic(0, tmp); h[i][j] = checkPic(1, tmp);
       }
}

int checkVer(int col)
{
    if (n % 2) return 0;
    for (int i = 0; i < n; i++)
       if (!v[i][col]) return 0;
    return 1;
}

int getWays(int col)
{
    int curbest[2][Maxn] = {0};
    curbest[0][n - 1] = v[n - 1][col] && v[n - 1][col + 1]; 
    curbest[1][n - 1] = h[n - 1][col] && h[n - 1][col + 1];
    for (int i = n - 2; i >= 0; i--) {
        curbest[0][i] = (v[i][col] && v[i][col + 1]) * curbest[1][i + 1];
        curbest[1][i] = (h[i][col] && h[i][col + 1]) * curbest[1][i + 1] +
                        (v[i][col] && v[i][col + 1]) * curbest[0][i + 1];
        curbest[1][i] %= mod; 
    }
    int res = curbest[1][0];
    if (checkVer(col) && checkVer(col + 1)) res--;
    if (res < 0) res += mod;
    return res;
}

int main()
{
    Prepare();
    getBoard();
    best[0][m - 1] = checkVer(m - 1); best[1][m - 1] = 0;
    if (m == 1) cout << best[0][m - 1] + best[1][m - 1] << endl;
    else {
         best[0][m - 2] = checkVer(m - 2) * (best[0][m - 1] + best[1][m - 1]);
         best[1][m - 2] = getWays(m - 2);
         for (int j = m - 3; j >= 0; j--) {
             best[0][j] = checkVer(j) * (best[0][j + 1] + best[1][j + 1]) % mod;
             best[1][j] = ll(getWays(j)) * ll((best[0][j + 2] + best[1][j + 2])) % ll(mod);
         }
         cout << (best[0][0] + best[1][0]) % mod << endl;
    }
    return 0;
}