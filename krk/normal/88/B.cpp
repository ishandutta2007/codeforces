#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

const int Maxn = 30;
const int Maxl = 26;

int n, m, x;
char B[Maxn][Maxn];
int needLow[Maxl], needUp[Maxl];
int res;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) cin >> B[i][j];
    fill(needLow, needLow + Maxl, -1);
    fill(needUp, needUp + Maxl, -1);
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          if (B[i][j] != 'S' && (needLow[B[i][j] - 'a'] != 0 || needUp[B[i][j] - 'a'] != 0)) {
                              needLow[B[i][j] - 'a'] = 0;
                              for (int i2 = 0; i2 < n; i2++)
                                 for (int j2 = 0; j2 < m; j2++) 
                                    if (B[i2][j2] == 'S') {
                                       if (needUp[B[i][j] - 'a'] == -1)
                                          needUp[B[i][j] - 'a'] = 1;
                                       if ((i - i2) * (i - i2) + (j - j2) * (j - j2) <= x * x)
                                          needUp[B[i][j] - 'a'] = 0;
                                    }
          }
    int q; cin >> q;
    int i;
    for (i = 0; i < q; i++) {
        char c; cin >> c;
        if (isupper(c))
           if (needUp[c - 'A'] == -1) break;
           else res += needUp[c - 'A'];
        else if (needLow[c - 'a'] == -1) break;
             else res += needLow[c - 'a'];
    }
    if (i < q) cout << "-1\n";
    else cout << res << endl;
    return 0;
}