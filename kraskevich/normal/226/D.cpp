#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int N = 100;
int a[N][N];
int row[N];
int col[N];
int n, m;

bool work()
{
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < m; j++)
            s += a[i][j];
        if (s < 0)
        {
            for (int j = 0; j < m; j++)
                a[i][j] = -a[i][j];
            row[i]++;
            return true;
        }
    }
    for (int j = 0; j < m; j++)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
            s += a[i][j];
        if (s < 0)
        {
            for (int i = 0; i < n; i++)
                a[i][j] = -a[i][j];
            col[j]++;
            return true;
        }
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    fill(row, row + N, 0);
    fill(col, col + N, 0);

    while (work());

    vector<int> r, c;
    for (int i = 0; i < n; i++)
        if (row[i] % 2)
            r.push_back(i + 1);
    for (int i = 0; i < m; i++)
        if (col[i] % 2)
            c.push_back(i + 1);

    cout << r.size() << " ";
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << " ";
    cout << endl;
    cout << c.size() << " ";
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;

    return 0;
}