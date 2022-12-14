#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<string> field;

int main()
{
    cin >> n >> m;

    field.resize(n);
    for (size_t i = 0; i < n; i++)
        cin >> field[i];

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            {
            if (field[i][j] == '*') continue;

            int sum = 0;
            if (i > 0             ) if (field[i-1][j  ] == '*') sum++;

            if (i > 0   && j > 0  ) if (field[i-1][j-1] == '*') sum++;

            if (           j > 0  ) if (field[i  ][j-1] == '*') sum++;

            if (i < n-1 && j > 0  ) if (field[i+1][j-1] == '*') sum++;

            if (i < n-1           ) if (field[i+1][j  ] == '*') sum++;

            if (i < n-1 && j < m-1) if (field[i+1][j+1] == '*') sum++;

            if (           j < m-1) if (field[i  ][j+1] == '*') sum++;

            if (i > 0   && j < m-1) if (field[i-1][j+1] == '*') sum++;


            if (field[i][j] == '.')
                {
                if (sum == 0) continue;
                else
                    {
                    cout << "NO" << endl;
                    return 0;
                    }
                }
            else if (field[i][j] - '0' == sum) continue;
            else
                {
                cout << "NO" << endl;
                return 0;
                }
            }

    cout << "YES" << endl;

    return 0;
}