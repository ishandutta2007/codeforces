#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;
int s[200010] = {0};
bool c_s[200010] = {0};

void init()
{
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
    s[3] = 2;
    s[4] = 3;
    c_s[0] = 1;
    c_s[1] = 1;
    c_s[2] = 1;
    c_s[3] = 1;
    c_s[4] = 1;
}

int cal_s(int i)
{
    if (!c_s[i])
    {
        if (i < 9)
        {
            s[i] = i - (i + 1) / 2 + cal_s((i + 1) / 2) + 1;
            c_s[i] = 1;
        }
        else if (i < 25)
        {
            s[i] = i - (i + 2) / 3 + cal_s((i + 2) / 3) + 1;
            c_s[i] = 1;
        }
        else if (i < 100)
        {
            s[i] = i - (i + 4) / 5 + cal_s((i + 4) / 5) + 1;
            c_s[i] = 1;
        }
        else if (i < 10000)
        {
            s[i] = i - (i + 9) / 10 + cal_s((i + 9) / 10) + 1;
            c_s[i] = 1;
        }
        else
        {
            s[i] = i - (i + 99) / 100 + cal_s((i + 99) / 100) + 1;
            c_s[i] = 1;
        }
    }
    return s[i];
}

void solve(int i)
{
    if (i == 3)
    {
        cout << "3 2\n3 2\n";
        return;
    }
    if (i == 4)
    {
        cout << "3 4\n4 2\n4 2\n";
        return;
    }
    int upper;
    if (i < 9)
        upper = (i + 1) / 2;
    else if (i < 25)
        upper = (i + 2) / 3;
    else if (i < 100)
        upper = (i + 4) / 5;
    else if (i < 10000)
        upper = (i + 9) / 10;
    else
        upper = (i + 99) / 100;

    for (int j = upper + 1; j < i; j++)
        cout << j << " " << i << '\n';
    cout << i << " " << upper << '\n';
    cout << i << " " << upper << '\n';
    solve(upper);
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << cal_s(n) << '\n';
        solve(n);
    }
}