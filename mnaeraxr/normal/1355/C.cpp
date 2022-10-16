#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<long long> diff(d + 1);

    for (int i = 0; i <= d; ++i)
    {
        int l = max(c - i, a);
        int r = min(b, d - i);
        diff[i] = max(0, r - l + 1);

        if (i)
            diff[i] += diff[i - 1];
    }

    long long ans = 0;

    for (int i = b; i <= c; ++i)
    {
        ans += diff[i - 1];
    }

    cout << ans << endl;

    return 0;
}