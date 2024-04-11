#include <iostream>
#include <string>
using namespace std;

const int mod = 1000000007;
const int Maxn = 5005;

string s, t;
int f[Maxn][Maxn][2];
int res;

int main()
{
    getline(cin, s); getline(cin, t);
    for (int i = 0; i < s.length(); i++) {
        f[i][0][0] = 1;
        for (int j = 0; j < t.length(); j++)
            for (int l = 0; l < 2; l++) {
                if (s[i] == t[j]) {
                    res = (res + f[i][j][l]) % mod;
                    f[i + 1][j + 1][1] = (f[i + 1][j + 1][1] + f[i][j][l]) % mod;
                }
                f[i][j + 1][l] = (f[i][j + 1][l] + f[i][j][l]) % mod;
            }
    }
    cout << res << endl;
    return 0;
}