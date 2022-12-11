#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int a, five[1111][1111], two[1111][1111], ff[1111][1111], gg[1111][1111], n, xx = -1, yy = -1, from1[1111][1111], from2[1111][1111]; // 0 - came from up, 1 - came from left
bool nul[1111][1111];

void doNull(int ii, int jj)
{
    int i = 1, j = 1;
    cout << "1" << endl;
    while (i < ii)
    {
        cout << "D";
        ++i;
    }
    while (j < n)
    {
        cout << "R";
        ++j;
    }
    while (i < n)
    {
        cout << "D";
        ++i;
    }
}

void doFive()
{
    int i = n, j = n;
    cout << ff[n][n] << endl;
    string ans = "";
    while (true)
    {
        if (i == 1 && j == 1) break;
        if (from1[i][j] == 0)
        {
            --i;
            ans = 'D' + ans;
            continue;
        }
        if (from1[i][j] == 1)
        {
            --j;
            ans = 'R' + ans;
        }
    }
    cout << ans;
}

void doTwo()
{
    int i = n, j = n;
    cout << gg[n][n] << endl;
    string ans = "";
    while (true)
    {
        if (i == 1 && j == 1) break;
        if (from2[i][j] == 0)
        {
            --i;
            ans = 'D' + ans;
            continue;
        }
        if (from2[i][j] == 1)
        {
            --j;
            ans = 'R' + ans;
        }
    }
    cout << ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            if (a == 0)
            {
                xx = i;
                yy = j;
                nul[i][j] = true;
                continue;
            }
            while (a % 2 == 0)
            {
                two[i][j]++;
                a /= 2;
            }
            while (a % 5 == 0)
            {
                five[i][j]++;
                a /= 5;
            }
        }
   for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (nul[i][j] == true)
            {
                ff[i][j] = gg[i][j] = 1000001;
                continue;
            }
            if (i == 1 && j == 1)
            {
                ff[i][j] = five[i][j];
                gg[i][j] = two[i][j];
                continue;
            }
            if (i == 1)
            {
                if (ff[i][j - 1] == 1000001)
                {
                    ff[i][j] = gg[i][j] = 1000001;
                    continue;
                }
                ff[i][j] = five[i][j] + ff[i][j - 1];
                gg[i][j] = two[i][j] + gg[i][j - 1];
                from1[i][j] = from2[i][j] = 1;
                continue;
            }
            if (j == 1)
            {
                if (ff[i - 1][j] == 1000001)
                {
                    ff[i][j] = gg[i][j] = 1000001;
                    continue;
                }
                ff[i][j] = five[i][j] + ff[i - 1][j];
                gg[i][j] = two[i][j] + gg[i - 1][j];
                from1[i][j] = from2[i][j] = 0;
                continue;
            }
            int f1 = ff[i - 1][j], f2 = ff[i][j - 1];
            if (f1 == 1000001 && f2 == 1000001)
            {
                ff[i][j] = 1000001;
            }
            if (f1 != 1000001 && f2 == 1000001)
            {
                ff[i][j] = five[i][j] + f1;
                from1[i][j] = 0;
            }
            if (f1 == 1000001 && f2 != 1000001)
            {
                ff[i][j] = five[i][j] + f2;
                from1[i][j] = 1;
            }
            if (f1 != 1000001 && f2 != 1000001)
            {
                ff[i][j] = five[i][j];
                if (f1 < f2)
                {
                    ff[i][j] += f1;
                    from1[i][j] = 0;
                } else
                    {
                        ff[i][j] += f2;
                        from1[i][j] = 1;
                    }
            }
            //--------------------------------------------------------------
            f1 = gg[i - 1][j], f2 = gg[i][j - 1];
            if (f1 == 1000001 && f2 == 1000001)
            {
                gg[i][j] = 1000001;
            }
            if (f1 != 1000001 && f2 == 1000001)
            {
                gg[i][j] = two[i][j] + f1;
                from2[i][j] = 0;
            }
            if (f1 == 1000001 && f2 != 1000001)
            {
                gg[i][j] = two[i][j] + f2;
                from2[i][j] = 1;
            }
            if (f1 != 1000001 && f2 != 1000001)
            {
                gg[i][j] = two[i][j];
                if (f1 < f2)
                {
                    gg[i][j] += f1;
                    from2[i][j] = 0;
                } else
                    {
                        gg[i][j] += f2;
                        from2[i][j] = 1;
                    }
            }
        }
    }
    if (xx != -1)
    {
        if (min(ff[n][n], gg[n][n]) >= 1)
        {
            doNull(xx, yy);
            return 0;
        }
    }
    //cout << ff[n][n] << " " << gg[n][n] << endl;
    if (ff[n][n] < gg[n][n]) doFive(); else doTwo();
    return 0;
}