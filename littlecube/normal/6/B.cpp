#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, m;
    map<char, bool> r;
    char c, d[110][110] = {{0}};
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ((d[i + 1][j] == c || d[i - 1][j] == c || d[i][j + 1] == c || d[i][j - 1] == c) && d[i][j] != '.' && d[i][j] != 0 && d[i][j] != c)
                r[d[i][j]] = 1;
    cout << r.size();
}