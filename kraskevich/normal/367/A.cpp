#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    s = '#' + s;
    int n = s.length();
    vector<int> sX(n, 0);
    vector<int> sY(n, 0);
    vector<int> sZ(n, 0);
    for (int i = 1; i < n; i++)
    {
        sX[i] = sX[i - 1] + (s[i] == 'x' ? 1 : 0);
        sY[i] = sY[i - 1] + (s[i] == 'y' ? 1 : 0);
        sZ[i] = sZ[i - 1] + (s[i] == 'z' ? 1 : 0);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        int x = sX[r] - sX[l];
        int y = sY[r] - sY[l];
        int z = sZ[r] - sZ[l];
        if (x < y)
            swap(x, y);
        if (x < z)
            swap(x, z);
        if (y < z)
            swap(y, z);
        assert(x >= y && y >= z);
        if (x == y && y == z)
        {
            cout << "YES\n";
            continue;
        }
        if (x == y && z == x - 1)
        {
            cout << "YES\n";
            continue;
        }
        if (y == x - 1 && y == z)
        {
            cout << "YES\n";
            continue;
        }
        if (r - l <= 2)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }

    return 0;
}