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


const int N = 3 * 1000 * 1000;
int ans[N];
bool was[N];

void solve()
{
    int n;
    cin >> n;

    cout << n * 1ll * (n + 1) << endl;

    fill(was, was + n + 1, 0);

    int pw = 1;
    while (pw < n)
    {
        pw = pw * 2;
        pw++;
    }

    for (int i = n; i >= 0; --i)
    {
        int cur = pw;
        for (;;)
        {
            int want = (i ^ cur);
            if (want > n || was[want])
                cur /= 2;
            else
                break;
        }
        ans[i] = (i ^ cur);
        was[ans[i]] = true;
    }
    for (int i = 0; i <= n; ++i)
        cout << ans[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}