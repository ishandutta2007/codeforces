#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

ll ansmax, ansmin, anss;

void print()
{
    cout << ansmax << ' ' << ansmin << ' ' <<anss;

}

int main()
{
    //ifstream cin("input.txt");
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    if (n == 1)
    {
        if (k % m == 0)
        {
            cout << k / m << ' ' << k / m << ' ' << k / m;
            return 0;
        }
        else
        {
            ansmin = k / m;
            ansmax = k / m + 1;
            ll ost = k % m;
            if (y > ost)
            {
                anss = ansmin;
            }
            else
            {
                anss = ansmax;
            }
            print();
            return 0;
        }
    }

    if (n == 2)
    {
        if (k % (2*m) == 0)
        {
            cout << k / (2 * m) << ' ' << k / (2 * m) << ' ' << k / (2 * m);
            return 0;
        }
        else
        {
            ansmin = k / (2 * m);
            ansmax = k / (2 * m) + 1;
            ll ost = k % (2 * m);
            int s = m * (x - 1) + y;
            if (s > ost)
            {
                anss = ansmin;
            }
            else
            {
                anss = ansmax;
            }
            print();
            return 0;
        }
    }

    ll fs = 2 * n * m - 2 * m;
    ansmax = (k / fs) * 2;
    ansmin = k / fs;
    if (x == 1 || x == n)
    {
        anss = ansmin;
    }
    else
    {
        anss = ansmax;
    }

    ll ost = k % fs;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (ost == 0) goto m1;
            ost--;
            if (i == x && j == y)
            {
                anss++;
            }
            if (i == 2 && j == 1)
            {
                ansmax++;
            }
            if (i == n && j == m)
            {
                ansmin++;
            }
        }
    }

    for (int i = n - 1; i >= 2; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (ost == 0) goto m1;
            ost--;
            if (i == x && j == y)
            {
                anss++;
            }
            if (i == n - 1 && j == 1)
            {
                ansmax++;
            }
        }
    }

    m1:;
    if (ansmax == 0)
    {
        ansmax = 1;
    }
    print();

    return 0;
}