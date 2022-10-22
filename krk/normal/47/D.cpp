#include <iostream>
#include <string>
using namespace std;

const int Maxm = 10;

int n, m, lft[Maxm];
long long ans;
string guess[Maxm], pret = "00000000000000000000000000000000000000";

void Generate(int lvl)
{
     int i;
     char c;
     if (lvl == n) {
             for (i = 0; i < m; i++)
                if (lft[i] != 0) break;
             if (i < m) return;
             ans++;
     } else {
            for (c = '0'; c <= '1'; c++) {
                pret[lvl] = c;
                for (i = 0; i < m; i++)
                   if (guess[i][lvl] == c) lft[i]--;
                for (i = 0; i < m; i++)
                   if (lft[i] < 0) break;
                if (i == m) Generate(lvl+1);
                for (i = 0; i < m; i++)
                   if (guess[i][lvl] == c) lft[i]++;
            }
     }
}

int main()
{
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
       cin >> guess[i] >> lft[i];
    Generate(0);
    cout << ans << endl;
    return 0;
}