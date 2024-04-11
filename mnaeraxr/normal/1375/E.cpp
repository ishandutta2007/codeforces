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
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>
#include <complex>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    vector<pair<int, int>> res;

    for (int i = n - 1; i >= 0; --i)
    {
        vector<int> pos;

        for (int j = 0; j < i; ++j)
        {
            if (v[j] > v[i])
                pos.push_back(j);
        }

        sort(pos.begin(), pos.end(), [&](int a, int b) {
            return v[a] < v[b];
        });

        for (auto x : pos)
        {
            swap(v[x], v[i]);
            res.push_back({x, i});
        }
    }

    cout << res.size() << endl;
    for (auto p : res)
    {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    return 0;
}