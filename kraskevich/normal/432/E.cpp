#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int N = 111;

char c[N][N];
int n, m;

bool good(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

bool can(int xl, int xr, int yl, int yr, char let)
{
    if (xl < -1 || xr > n)
        return false;
    if (yl < -1 || yr > m)
        return false;
    for (int i = xl; i <= xr; i++)
        for (int j = yl; j <= yr; j++)
        {
            int cnt = 0;
            if (i == xl || i == xr)
                cnt++;
            if (j == yl || j == yr)
                cnt++;
            if (cnt == 2)
                continue;
            if (xl + 1 <= i && i <= xr - 1 && yl + 1 <= j && j <= yr - 1)
            {
                if (good(i, j) && c[i][j] >= 'A')
                    return false;
            }
            else
            {
                if (good(i, j) && c[i][j] == let)
                    return false;
            }
        }
    return true;
}

void put(int xl, int xr, int yl, int yr, char cur)
{
    for (int i = xl; i <= xr; i++)
        for (int j = yl; j <= yr; j++)
            c[i][j] = cur;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        //freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        fill(c[i], c[i] + m, '0');
    for (;;)
    {
        bool any = false;
        for (int i = 0; i < n && !any; i++)
            for (int j = 0; j < m && !any; j++)
            {
                if (c[i][j] >= 'A')
                    continue;
                any = true;
                char ch = 'A';
                int d = 1;
                while (!can(i - 1, i + d, j - 1, j + d, ch))
                    ch++;
                put(i, i, j, j, ch);
                for (;;)
                {
                    put(i, i + d - 1, j, j + d - 1, '0');
                    d++;
                    if (!can(i - 1, i + d, j - 1, j + d, ch))
                        break;
                    if (ch == 'B')
                        cerr << i << " " << j << " " << ch << endl;
                    bool mn = true;
                    put(i, i + d - 2, j, j + d - 2, ch);
                    for (char small = 'A'; small < ch; small++)
                        if (can(i - 1, i + 1, j + d - 2, j + d, small))
                            mn = false;
                    if (!mn)
                        break;
                }
                d--;
                put(i, i + d - 1, j, j + d - 1, ch);
            }

        if (!any)
            break;

        /*for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << c[i][j];
            cout << "\n";
        }
        cout << endl;*/
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << c[i][j];
        cout << "\n";
    }

    return 0;
}