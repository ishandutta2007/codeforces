#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <ctime>
#include <ctype.h>

using namespace std;


int main()
{
    vector<int> res;
    int a, b, n;

    cin >> a >> b >> n;
    res.push_back(a);

    int mod = a % b;
    for (int i = 0; i < n; ++i)
    {
        mod *= 10;
        mod %= b;
        int d = 0;
        for (; d < 10; ++d)
            if ((mod + d) % b == 0)
            {
                mod += d;
                mod %= b;
                res.push_back(d);
                break;
            }
        if (d == 10)
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < res.size(); ++i)
        cout << res[i];

    return 0;
}