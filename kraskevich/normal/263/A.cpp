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

#define pii pair<int, int>
#define F first
#define S second

int ABS(int a)
{
    return a > 0 ? a : -a;
}

void solve()
{
    int x, y, a;
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
        {
            cin >> a;
            if (a)
                x = i, y = j;
        }

    cout << ABS(x - 3) + ABS(y - 3);
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}