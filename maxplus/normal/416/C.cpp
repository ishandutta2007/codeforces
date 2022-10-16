#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

struct table{
    int rn, cap;
};

struct comp{
    int cap, pr;
};

table m[10000];
comp v[10000];
int tak[10000];
bool t[10000];

bool compare(table a, table b)
{return a.cap < b.cap;}

int main()
{
    int n, k, b = 0, bj, am = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i].cap >> v[i].pr;
    cin >> k;
    for (int i = 0; i < k; ++i)
        cin >> m[i].cap;
    for (int i = 0; i < 10000; ++i)
        m[i].rn = i;

    sort (m, m + k, compare);

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
            if (!t[j])
                if (v[j].cap <= m[i].cap && v[j].pr > b)
                {
                    b = v[j].pr;
                    bj = j;
                }

        if (b != 0)
        {
            t[bj] = 1;
            tak[m[i].rn] = bj + 1;
            am++;
            sum += v[bj].pr;
            b = 0;
        }
    }

    cout << am << ' ' << sum << '\n';
    for (int i = 0; i < k; ++i)
        if (tak[i] != 0)
            cout << tak[i] << ' ' << i + 1 << '\n';
    return 0;
}