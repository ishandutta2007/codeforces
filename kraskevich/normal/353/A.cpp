#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int up = 0;
    int down = 0;
    bool was = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a %= 2;
        b %= 2;
        up += a;
        down += b;
        if (a + b == 1)
            was = true;
    }
    up %= 2;
    down %= 2;
    if (up == 0 && down == 0)
    {
        cout << 0;
        return 0;
    }
    if (up + down == 1)
    {
        cout << -1;
        return 0;
    }
    if (was)
        cout << 1;
    else
        cout << -1;

    return 0;
}