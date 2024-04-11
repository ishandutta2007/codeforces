#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <string.h>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

const int N = 1000 * 1000 + 10;
int ans[N];

void solve()
{
    int n, k;
    scanf("%d%d", & n, & k);
    if (k * 3 > n)
    {
        cout << -1;
        return;
    }
    fill(ans, ans + n, -1);
    int p1 = 0;
    int p2 = k;
    int p3 = k + 1;
    for (int i = 0; i < k; ++i)
    {
        ans[p1] = i + 1;
        ans[p2] = i + 1;
        ans[p3] = i + 1;
        p1++;
        p2 += 2;
        p3 += 2;
    }
    for (int i = 0; i < n; ++i)
        if (ans[i] == -1)
            ans[i] = k;
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();


    return 0;

}