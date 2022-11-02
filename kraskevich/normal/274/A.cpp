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

const int N = 100 * 1000 + 10;
long long a[N];
long long k;
int n;
int color[N];

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (k == 1)
    {
        cout << n;
        return;
    }

    sort(a, a + n);
    fill(color, color + n, 0);
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (color[i])
            continue;
        int cur = 0;
        long long v = a[i];
        for (int j = 0;; ++j)
        {
            int pos = lower_bound(a, a + n, v) - a;
            if (pos >= n)
                break;
            if (a[pos] != v)
                break;
            color[pos] = 1;
            ++cur;
            v *= k;
        }
        res += (cur / 2 + cur % 2);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}