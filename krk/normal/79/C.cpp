#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 10, Maxp = 100005;

int n;
string s, bor[Maxn];
int sbor[Maxp], best[Maxp];

bool Equal(int j, int from)
{
     for (int i = 0; i < bor[j].length(); i++)
        if (bor[j][i] != s[from+i]) return false;
     return true;
}

int main()
{
    cin >> s >> n;
    for (int i = 0; i < n; i++) cin >> bor[i];
    fill(sbor, sbor+Maxp, Maxp);
    for (int i = 0; i < s.length(); i++)
       for (int j = 0; j < n; j++)
          if (bor[j].length() <= i+1 && Equal(j, i+1-bor[j].length()))
             sbor[i] = min(sbor[i], int(bor[j].length()));
    best[0] = min(1, sbor[0]-1);
    int ans = best[0], from = 0;
    for (int i = 1; i < s.length(); i++) {
        best[i] = min(best[i-1]+1, sbor[i]-1);
        if (best[i] > ans) {
                    ans = best[i];
                    from = i;
        }
    }
    if (ans == 0 && from == 0) cout << "0 0\n";
    else cout << ans << " " << from-ans+1 << endl;
    return 0;
}