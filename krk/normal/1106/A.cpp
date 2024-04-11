#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n;
string B[Maxn];
int res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < n; j++)
            res += B[i - 1][j - 1] == 'X' && B[i - 1][j + 1] == 'X' &&
                   B[i][j] == 'X' &&
                   B[i + 1][j - 1] == 'X' && B[i + 1][j + 1] == 'X';
    cout << res << endl;
    return 0;
}