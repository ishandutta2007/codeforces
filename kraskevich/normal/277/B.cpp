#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second

void openFiles()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int d = 100 * 1000 * 1000;

void solve()
{
    int n, m;
    cin >> n >> m;

    if (n == 6 && m == 3 || n == 5 && m == 3)
    {
        cout << -1;
        return;
    }

    vector<int> x, y;
    int curx = 0;
    int cury = 0;
    int dy = 100 * 100;
    int dx = 0;
    for (int i = 0; i < m - 1; ++i)
    {
        x.push_back(curx);
        y.push_back(cury);
        curx += dx;
        cury += dy;
        dx = 1000 * 1000;
        --dy;
    }
    x.push_back(curx - dx);
    if (m == 3)
        x.back() += dx;
    y.push_back(0);

    int rest = n - m;

    if (rest == 0)
    {
        for (int i = 0; i < n; ++i)
            cout << x[i] - d << " " << y[i] << endl;
        return;
    }
    if (rest == 1)
    {
        x.push_back(1);
        y.push_back(1);
        for (int i = 0; i < n; ++i)
            cout << x[i] - d << " " << y[i] << endl;
        return;
    }
    if (rest == 2)
    {
        x.push_back(1);
        y.push_back(1);
        x.push_back(x[m - 1] - 1);
        y.push_back(1);
        for (int i = 0; i < n; ++i)
            cout << x[i] - d << " " << y[i] << endl;
        return;
    }
    if (rest == 3)
    {
        x.push_back(1);
        y.push_back(1);
        x.push_back(x[m - 1] - 1);
        y.push_back(1);
        x.push_back(x[m - 1] - 1);
        y.push_back(y[m - 2] - 1);
        for (int i = 0; i < n; ++i)
            cout << x[i] - d << " " << y[i] << endl;
        return;
    }

    curx = 1;
    cury = 1;
    dy = 299;
    dx = 0;
    for (int i = 0; i < rest - 1; ++i)
    {
        if (i == rest - 2)
            curx = x[m - 1] - 1;
        x.push_back(curx);
        y.push_back(cury);
        curx += dx;
        cury += dy;
        dx = 1000 * 1000;
        if(i)
            --dy;
    }

    y.back()--;
    x.push_back(x[m - 1] - 1);
    y.push_back(1);
    for (int i = 0; i < n; ++i)
        cout << x[i] - d << " " << y[i] << endl;
}


int main()
{
    ios_base::sync_with_stdio(0);

    //openFiles();
    solve();

    return 0;
}