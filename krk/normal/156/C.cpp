#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 105;
const int Maxm = 2605;
const int Maxd = 26;
const int mod = 1000000007;

int ways[Maxn][Maxm];
int t;
string s;

int main()
{
    ways[0][0] = 1;
    for (int i = 1; i < Maxn; i++)
        for (int j = 0; j < Maxm; j++)
            for (int l = 0; l < Maxd; l++)
                if (j - l >= 0) ways[i][j] = (ways[i][j] + ways[i - 1][j - l]) % mod;
    scanf("%d", &t);
    while (t--) {
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) sum += s[i] - 'a';
        printf("%d\n", (ways[s.length()][sum] - 1 + mod) % mod);
    }
    return 0;
}