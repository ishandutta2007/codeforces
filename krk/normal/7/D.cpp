#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 10000005;
const int Maxm = 5000005;

int n;
string s;
int Z[Maxn], deg[Maxm];
int res;

int main()
{
    getline(cin, s); n = s.length();
    string tmp = s; reverse(tmp.begin(), tmp.end());
    s += tmp;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); i++)
        if (i <= r) {
              Z[i] = min(Z[i - l], r - i + 1);
              if (i + Z[i] > r) {
                    while (i + Z[i] < s.length() && s[i + Z[i]] == s[Z[i]]) Z[i]++;
                    l = i;
                    r = i + Z[i] - 1;
              }
        } else {
               while (i + Z[i] < s.length() && s[i + Z[i]] == s[Z[i]]) Z[i]++;
               if (Z[i]) {
                         l = i;
                         r = i + Z[i] - 1;
               }
        }
    deg[0] = 1; res += 1;
    for (int i = 1; i < n; i++) {
        int lend = (i - 1) / 2;
        if (Z[s.length() - 1 - i] >= i + 1) {
                   deg[i] = deg[lend] + 1;
                   res += deg[i];
        }
    }
    cout << res << endl;
    return 0;
}