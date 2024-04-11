#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> web(n);

    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j)
        {
            int v;
            cin >> v;
            web[i].push_back(v);
        }

        sort(web[i].begin(), web[i].end());
    }

    auto calc = [&](vector<int> &a, vector<int> &b, vector<int> &c) {
        int pb = 0, pc = 0;

        while (pb < b.size() && b[pb] < a[0])
            pb++;

        while (pc < c.size() && c[pc] < a[0])
            pc++;

        int res = 0;

        for (int i = 1; i < a.size(); ++i)
        {
            int tb = 0, tc = 0;

            while (pb < b.size() && b[pb] < a[i])
                ++pb, ++tb;
            while (pc < c.size() && c[pc] < a[i])
                ++pc, ++tc;

            res += tb != tc;
        }

        return res;
    };

    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        answer += calc(web[i], web[(i + n - 1) % n], web[(i + 1) % n]);
    }

    cout << answer << endl;

    return 0;
}