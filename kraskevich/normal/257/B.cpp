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

int get_diff(int n, int m)
{
    int last = 0;
    int res = 0;
    --n;
    for (int i = 0; n && m; ++i)
    {
        if (i % 2 == 0)
        {
            if (last == 0)
                --m, last = 1;
            else
                --n, last = 0;
            ++res;
        }
        else
        {
            if (last == 0)
                --n;
            else
                --m;
        }
    }
    return res + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    if (n == 0 || m == 0)
    {
        cout << n + m - 1 << " " << 0;
        return 0;
    }

    int tot = n + m - 1;
    int second = min(get_diff(n, m), get_diff(m, n));
    cout << tot - second << " " << second;

    return 0;
}