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
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    reverse(a, a + n);

    int ptr = 0;
    while (k < m)
    {
        if (ptr == n)
            break;
        k += a[ptr] - 1;
        ++ptr;
    }

    if (k < m)
        cout << -1;
    else
        cout << ptr;

    return 0;
}