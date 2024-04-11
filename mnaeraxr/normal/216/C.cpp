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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> total(n + m + 1);
    vector<int> answer;

    auto hire = [&](int x, int t) {
        for (int i = 0; i < t; ++i)
        {
            answer.push_back(x + 1);
        }

        for (int i = 0; i < n; ++i)
        {
            if (x + i >= n + m + 1)
                break;

            total[x + i] += t;
        }
    };

    hire(0, k);

    for (int i = 1; i < n + m; ++i)
    {
        if (total[i] == 0)
            hire(i - 1, 1);

        if (total[i] < k)
            hire(i, k - total[i]);
    }

    if (total.back() == 0)
        hire(n + m - 1, 1);

    cout << answer.size() << endl;
    for (auto x : answer)
        cout << x << " ";
    cout << endl;

    return 0;
}