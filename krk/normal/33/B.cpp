#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxl = 26;
const int Inf = 1000;

string a, b;
int cost[Maxl][Maxl];
int res;
string s;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> a >> b;
    if (a.length() != b.length()) { cout << "-1\n"; return 0; }
    fill((int*)cost, (int*)cost + Maxl * Maxl, Inf);
    for (int i = 0; i < Maxl; i++) cost[i][i] = 0;
    int n; cin >> n;
    while (n--) {
          char a, b;
          int w;
          cin >> a >> b >> w;
          cost[a - 'a'][b - 'a'] = min(cost[a - 'a'][b - 'a'], w);
    }
    for (int k = 0; k < Maxl; k++)
       for (int i = 0; i < Maxl; i++)
          for (int j = 0; j < Maxl; j++)
             cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    int i;
    for (i = 0; i < a.length(); i++) {
        int toadd = Inf; s += " ";
        for (int j = 0; j < Maxl; j++) {
            int cur = cost[a[i] - 'a'][j] + cost[b[i] - 'a'][j];
            if (cur < toadd) {
                    toadd = cur;
                    s[i] = 'a' + j;
            }
        }
        if (toadd == Inf) break;
        res += toadd;
    }
    if (i < a.length()) cout << "-1\n";
    else cout << res << endl << s << endl;
    return 0;
}