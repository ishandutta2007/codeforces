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
#include <cctype>
#include <ctime>

using namespace std;

const int N = 100 * 1000 + 1;
int a[N];
int q[N];

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> q[i];

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    reverse(a, a + n);

    int mnq = 100 * 1000 + 1;
    for (int i = 0; i < m; ++i)
        mnq = min(mnq, q[i]);

    int sum = 0;
    vector<bool> take(n, true);

    int i = mnq;
    while (i < n)
    {
        if (i < n)
            take[i] = false;
        i++;
        if (i < n)
            take[i] = false;
        i += mnq + 1;
    }

    for (int i = 0; i < n; ++i)
        if (take[i])
            sum += a[i];

    cout << sum;


    return 0;
}