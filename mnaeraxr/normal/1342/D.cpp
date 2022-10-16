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

    int n, k;
    cin >> n >> k;

    vector<int> freq(k + 1);

    for (int i = 0; i < n; ++i)
    {
        int u;
        cin >> u;
        freq[u]++;
    }

    vector<int> lim(k + 1);

    for (int i = 0; i < k; ++i)
    {
        cin >> lim[i + 1];
    }

    int total = 0, acc = 0;

    for (int i = k; i; --i)
    {
        acc += freq[i];
        total = max(total, (acc + lim[i] - 1) / lim[i]);
    }

    vector<vector<int>> answer(total);

    for (int i = k, p = 0; i; --i)
    {
        for (int j = 0; j < freq[i]; ++j)
            answer[p++ % total].push_back(i);
    }

    cout << answer.size() << endl;

    for (auto row : answer)
    {
        cout << row.size();

        for (auto x : row)
            cout << " " << x;
        cout << endl;
    }

    return 0;
}