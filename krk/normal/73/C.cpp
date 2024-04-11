#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxl = 26;
const int Maxs = 101;
const int Maxk = 101;

string s;
int k, n;
int bon[Maxl][Maxl], dp[Maxl][Maxs][Maxk];

int getDP(int l, int n, int k)
{
     if (k < 0) return -Inf;
     if (n == s.length()-1) return 0;
     if (dp[l][n][k] < -Inf) {
                     int best = -Inf;
                     for (int c = 'a'; c <= 'z'; c++)
                        if (s[n+1] == c) best = max(best, getDP(c-'a', n+1, k) + bon[l][c-'a']);
                        else best = max(best, getDP(c-'a', n+1, k-1) + bon[l][c-'a']);
                     dp[l][n][k] = best;
     }
     return dp[l][n][k];
}

int main()
{
    char a, b;
    int c;
    cin >> s >> k;
    cin >> n;
    while (n--) {
          cin >> a >> b >> c;
          bon[a-'a'][b-'a'] = c;
    }
    fill((int*)dp, (int*)dp+Maxl*Maxs*Maxk, -Inf-1);
    int best = -Inf;
    for (char c = 'a'; c <= 'z'; c++)
       if (s[0] == c) best = max(best, getDP(c-'a', 0, k));
       else best = max(best, getDP(c-'a', 0, k-1));
    cout << best << endl;
    return 0;
}