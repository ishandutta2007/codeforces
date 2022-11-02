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

const int N = 55;
int a[55];

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    reverse(a, a + n);

    if (k > n)
    {
        cout << -1;
        return;
    }
    if (k == n)
    {
        cout << a[k - 1] << " " << 0;
    }
    else
    {
        if (a[k - 1] == a[k])
            cout << -1;
        else
            cout << a[k - 1] << " " << 0;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}