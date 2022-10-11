#include <bits/stdc++.h>
using namespace std;

const int M = 505, DX[5] = {0, 1, 0, -1, 0}, DY[5] = {1, 0, -1, 0, 0};

int m, n, cnt = -1;
string s[M];

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
        for (int j = 0; j < n; j++)
            cnt += (s[i][j] == '*');
    }
    for (int i = 1; i < m - 1; i++)
        for (int j = 1; j < n - 1; j++)
        {
            bool chk = true;
            for (int k = 0; k < 5; k++)
                chk &= (s[i + DX[k]][j + DY[k]] == '*');
            if (chk)
            {
                for (int x = i - 1; x >= 0 && s[x][j] == '*'; x--)
                    cnt--;
                for (int x = i + 1; x < m && s[x][j] == '*'; x++)
                    cnt--;
                for (int y = j - 1; y >= 0 && s[i][y] == '*'; y--)
                    cnt--;
                for (int y = j + 1; y < n && s[i][y] == '*'; y++)
                    cnt--;
                return cout << (cnt == 0 ? "YES" : "NO"), 0;
            }
        }
    cout << "NO";
}