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

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

void openFiles()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}


void solve()
{
    int n, k;
    cin >> n >> k;

    if (n == 1 && k == 1)
    {
        cout << 'a';
        return;
    }
    if (k > n || k == 1)
    {
        cout << -1;
        return;
    }

    int suf = k - 2;
    for (int i = 0; i < n - suf; ++i)
    {
        if (i % 2 == 0)
            cout << 'a';
        else
            cout << 'b';
    }
    for (int i = n - suf; i < n; ++i)
        cout << char('c' + i - (n - suf));
}

int main()
{
    ios_base::sync_with_stdio(0);
    //openFiles();

    solve();

    return 0;
}