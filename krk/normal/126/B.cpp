#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

int l, r, Z[Maxn];

int main()
{
    string s;
    getline(cin, s);
    for (int i = 1; i < s.length(); i++)
        if (i <= r) {
              Z[i] = min(Z[i - l], r - i + 1);
              if (i + Z[i] - 1 >= r) {
                    while (i + Z[i] < s.length() && s[i + Z[i]] == s[Z[i]]) Z[i]++;
                    if (Z[i]) {
                              l = i; r = i + Z[i] - 1;
                    }
              }
        } else {
               while (i + Z[i] < s.length() && s[i + Z[i]] == s[Z[i]]) Z[i]++;
               if (Z[i]) {
                         l = i; r = i + Z[i] - 1;
               }
        }
    int mx = 0;
    for (int i = 1; i < s.length(); i++)
        mx = max(mx, min(Z[i], int(s.length()) - i - 1));
    while (mx && Z[s.length() - mx] != mx) mx--;
    if (mx) cout << s.substr(0, mx) << endl;
    else cout << "Just a legend\n";
    return 0;
}