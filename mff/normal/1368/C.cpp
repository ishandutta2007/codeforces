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

    vector<int> x = {0, 0, 1, 1, 2, 2, 2};
    vector<int> y = {1, 2, 0, 2, 0, 1, 2};

    int n;
    cin >> n;

    vector<pair<int, int>> res;

    res.push_back({0, 0});
    n++;

    int X = 0, Y = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            res.push_back({X + x[j], Y + y[j]});
        }

        X += 2;
        Y += 2;
    }

    cout << res.size() << endl;

    for (auto p : res)
        cout << p.first << " " << p.second << endl;

    return 0;
}