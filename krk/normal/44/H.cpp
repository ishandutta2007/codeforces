#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 50;

long long ways[Maxn][10];
string s;

long long getWays(int pos, int dig)
{
     if (pos == s.length() - 1) return 1;
     if (!ways[pos][dig]) {
                          int sum = dig + s[pos+1] - '0';
                          if (sum % 2) ways[pos][dig] += getWays(pos+1, sum/2+1);
                          ways[pos][dig] += getWays(pos+1, sum/2);
     }
     return ways[pos][dig];
}

int main()
{
    long long ans = 0;
    cin >> s;
    for (int i = 0; i < 10; i++)
       ans += getWays(0, i);
    int i, dig = s[0] - '0';
    for (i = 1; i < s.length(); i++)
       if (abs(s[i] - '0' - dig) <= 1) dig = s[i] - '0';
       else break;
    if (i == s.length()) ans--;
    cout << ans << endl;
    return 0;
}