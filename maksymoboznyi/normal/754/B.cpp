#include <bits/stdc++.h>

using namespace std;
char a[101][101];
int main()
{
    for (int i = 1 ; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (a[i][j] == 'x')
            {
                if (a[i-1][j-1] == 'x' && a[i+1][j+1] == '.')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i+1][j+1] == 'x' && a[i-1][j-1] == '.')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i+1][j-1] == 'x' && a[i-1][j+1] == '.')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i-1][j+1] == 'x' && a[i+1][j-1] == '.')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i-1][j] == 'x' && a[i+1][j] == '.')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i+1][j] == 'x' && a[i-1][j] == '.')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i][j+1] == 'x' && a[i][j-1] == '.')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i][j-1] == 'x' && a[i][j+1] == '.')
                {
                    cout << "YES";
                    return 0;
                }
            }

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (a[i][j] == '.')
            {

                if (a[i-1][j-1] == 'x' && a[i+1][j+1] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i+1][j+1] == 'x' && a[i-1][j-1] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i+1][j-1] == 'x' && a[i-1][j+1] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i-1][j+1] == 'x' && a[i+1][j-1] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i-1][j] == 'x' && a[i+1][j] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i+1][j] == 'x' && a[i-1][j] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i][j+1] == 'x' && a[i][j-1] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
                if (a[i][j-1] == 'x' && a[i][j+1] == 'x')
                {
                    cout << "YES";
                    return 0;
                }
            }

    cout << "NO";
    return 0;
}