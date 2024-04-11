#include <iostream>
#include <stdio.h>
using namespace std;

const int mod = 1e9 + 9;
int n, m;
long long f[2005], pow[205], Hash[205][2005];
string s, t[205];
bool chk = false;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            f[i] = (((f[i] * 31) % mod) + s[j] - 'a') % mod;
    }
    pow[0] = 1;
    for (int i = 1; i <= m; i++)
        pow[i] = (pow[i - 1] * 31) % mod;
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
        Hash[i][0] = 0;
        for (int j = 1; j <= t[i].length(); j++)
            Hash[i][j] = (((Hash[i][j - 1] * 31) % mod) + t[i][j - 1] - 'a') % mod;
    }
    for (int i = 1; i <= n - m + 1; i++)
        for (int j = 1; j <= n - m + 1; j++)
        {
            chk = true;
            for (int k = 1; k <= m; k++)
            {
                long long tmp = (Hash[k][j + m - 1] - ((Hash[k][j - 1] * pow[m]) % mod) + mod) % mod;
                if (f[i + k - 1] != tmp)
                {
                    chk = false;
                    break;
                }
            }
            if (chk)
            {
                cout << i << " " << j;
                return 0;
            }
        }
	return 0;
}