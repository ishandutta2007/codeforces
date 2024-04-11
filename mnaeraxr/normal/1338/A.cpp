#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t-->0) {
        int n; cin >> n;

        long long mx = -1000000000;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            long long u; cin >> u;
            ans = max(ans, mx - u);
            mx = max(mx, u);
        }

        int tot = 0;

        while (ans >= (1LL << tot))
            tot++;

        cout << tot << endl;
    }

    return 0;
}