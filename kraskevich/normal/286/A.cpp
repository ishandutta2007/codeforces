#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

bool good(vector<int> p)
{
    for (int i = 0; i < p.size(); ++i)
        if (p[p[i]] != p.size() - i - 1)
            return false;
    return true;
}

void print(vector<int> p)
{
    for (int i = 0; i < p.size(); ++i)
        cout << p[i] + 1 << " ";
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;

    if (n % 4 >= 2)
    {
        cout << -1;
        return;
    }

    vector<int> ans(n, n / 2);
    int hi = n - 1;
    int lo = 0;
    for (int l = 0, r = 1, x = n - 2, y = n - 1; r < x; x -= 2, y -= 2, l += 2, r += 2)
    {
        ans[l] = lo + 1;
        ans[r] = hi;
        ans[x] = lo;
        ans[y] = hi - 1;
        hi -= 2;
        lo += 2;
    }
    print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}