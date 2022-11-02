#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
string bad = "Poor Inna and pony!";

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;
    int x1 = INF;
    int x2 = INF;
    i--;
    if (i % a == 0)
        x1 = i / a;
    i++;
    if ((n - i) % a == 0)
        x2 = (n - i) / a;
    vector<int> x;
    x.push_back(x1);
    x.push_back(x2);
    int y1 = INF;
    int y2 = INF;
    j--;
    if (j % b == 0)
        y1 = j / b;
    j++;
    if ((m - j) % b == 0)
        y2 = (m - j) / b;
    vector<int> y;
    y.push_back(y1);
    y.push_back(y2);
    int res = INF;
    for (int xx : x)
        for (int yy : y)
        {
            if (xx == INF || yy == INF)
                continue;
            int diff = max(xx, yy) - min(xx, yy);
            if (diff == 0)
            {
                res = min(res, xx);
                continue;
            }
            if (diff % 2 == 0)
            {
                if (yy < xx)
                    if (max(m - j, j - 1) >= b)
                        res = min(res, xx);
                if (xx < yy)
                    if (max(n - i, i - 1) >= a)
                        res = min(res, yy);
            }
        }
    if (res < INF)
        cout << res;
    else
        cout << bad;

    return 0;
}