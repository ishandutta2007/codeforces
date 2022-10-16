#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>
#include <complex>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<long long>> a(n + 1, vector<long long>(n + 1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = (1LL << (i + j)) * (i & 1);
            cout << a[i][j] << " \n"[j == n];
        }
    }
    cout.flush();

    int q;
    cin >> q;

    while (q--)
    {
        long long k;
        cin >> k;

        int x = 1, y = 1;

        vector<pair<int, int>> path(1, make_pair(1, 1));

        while (x < n && y < n)
        {
            if (a[x + 1][y])
            {
                if (k & a[x + 1][y])
                    path.push_back(make_pair(++x, y));
                else
                    path.push_back(make_pair(x, ++y));
            }
            else
            {
                if (k & a[x][y + 1])
                    path.push_back(make_pair(x, ++y));
                else
                    path.push_back(make_pair(++x, y));
            }
        }

        while (x < n)
            path.push_back(make_pair(++x, y));

        while (y < n)
            path.push_back(make_pair(x, ++y));

        for (auto [x, y] : path)
            cout << x << " " << y << endl;
        cout.flush();
    }

    return 0;
}