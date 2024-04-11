#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    int ans = 0, cur = 1;
    for (int i = 0; i < n; ++i)
    {
        int l, r; cin >> l >> r;
        cur += x * ( (l - cur) / x);
        ans += r - cur + 1;
        cur = r + 1;
    }

    cout << ans << endl;
    return 0;
}