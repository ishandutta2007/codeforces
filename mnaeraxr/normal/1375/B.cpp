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

#define endl '\n'

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    bool ok = true;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            b[i][j] = int(i > 0) + int(i + 1 < n) + int(j > 0) + int(j + 1 < m);
            ok &= a[i][j] <= b[i][j];
        }

    if (ok)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cout << b[i][j] << " \n"[j + 1 == m];
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}