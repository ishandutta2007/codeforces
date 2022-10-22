#include <iostream>
#include <string>
using namespace std;

const int Maxm = 101;
const int Maxn = 51;
const int Maxl = 201;
const int corr = 100;

string s;
int n;
bool canbe[Maxm][Maxn][Maxl][2];

int main()
{
    getline(cin, s); cin >> n;
    canbe[0][0][corr][0] = true;
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j <= n; j++)
            for (int l = 0; l < Maxl; l++)
                for (int k = 0; k < 2; k++)
                    if (canbe[i][j][l][k])
                       if (s[i] == 'F') {
                                if (k == 0) canbe[i + 1][j][l + 1][k] = true;
                                else canbe[i + 1][j][l - 1][k] = true;
                                if (j < n) canbe[i + 1][j + 1][l][1 - k] = true;
                       } else {
                              canbe[i + 1][j][l][1 - k] = true;
                              if (j < n)
                                 if (k == 0) canbe[i + 1][j + 1][l + 1][k] = true;
                                 else canbe[i + 1][j + 1][l - 1][k] = true;
                       }
    for (int j = 2; j <= n; j++)
        for (int l = 0; l < Maxl; l++)
            for (int k = 0; k < 2; k++)
                canbe[s.length()][j][l][k] = canbe[s.length()][j][l][k] || 
                                             canbe[s.length()][j - 2][l][k];
    int cand = 100;
    while (cand &&
           !canbe[s.length()][n][-cand + corr][0] && !canbe[s.length()][n][-cand + corr][1] &&
           !canbe[s.length()][n][cand + corr][0] && !canbe[s.length()][n][cand + corr][1]) cand--;
    cout << cand << endl;
    return 0;
}