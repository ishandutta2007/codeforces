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

long long m, l, r, k;
long long res = 1;

struct matrix
{
    vector<vector<long long> > a;

    matrix()
    {
        a.assign(2, vector<long long>(2, 0));
    }

    matrix operator * (matrix b)
    {
        matrix c;
        c.a[0][0] = c.a[0][1] = c.a[1][0] = c.a[1][1] = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                {
                    c.a[i][j] += a[i][k] * b.a[k][j] % m;
                    c.a[i][j] %= m;
                }
        return c;
    }
};

long long get_fib(long long x)
{
    matrix b;
    b.a[0][0] = 1;
    b.a[0][1] = 1;
    b.a[1][0] = 1;
    b.a[1][1] = 0;
    matrix e;
    e.a[0][0] = e.a[1][1] = 1;
    e.a[0][1] = e.a[1][0] = 0;
    while (x > 0)
    {
        if (x % 2)
            e = e * b;
        b = b * b;
        x /= 2;
    }
    return e.a[0][1];
}

vector<long long> d;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> m >> l >> r >> k;

    for (int x = 1; x <= (int)2e6; x++)
        d.push_back(x);
    for (int x = 1; x <= (int)2e6; x++)
    {
        long long fl = l / x;
        d.push_back(fl + 1);
        if (fl > 0)
        {
            d.push_back(fl);
        }
        if (fl - 1 > 0)
            d.push_back(fl - 1);
    }
    for (int x = 1; x <= (int)2e6; x++)
    {
        long long fl = r / x;
        d.push_back(fl + 1);
        if (fl > 0)
        {
            d.push_back(fl);
        }
        if (fl - 1 > 0)
            d.push_back(fl - 1);
    }

    //sort(d.begin(), d.end());
    //d.resize(unique(d.begin(), d.end()) - d.begin());

    for (long long x: d)
    {
        if (x > r)
            continue;
        long long hi = r / x * x;
        long long lo = (l / x + (l % x ? 1 : 0)) * x;
        long long curr = (hi - lo) / x + 1;
        if (curr >= k)
        {
            //cout << x << endl;
            res = max(res, x);
        }
    }

    cout << get_fib(res);


    return 0;
}