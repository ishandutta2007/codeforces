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

    long long n;
    cin >> n;

    map<long long, vector<long long>> ms;

    for (long long i = 0; i < n; ++i)
    {
        long long a;
        cin >> a;

        for (long long i = 2; i * i <= a; ++i)
        {
            long long v = 1;

            while (a % i == 0)
            {
                v *= i;
                a /= i;
            }

            if (v > 1)
                ms[i].push_back(v);
        }

        if (a > 1)
            ms[a].push_back(a);
    }

    long long answer = 1;

    for (auto s : ms)
    {
        auto x = s.second;
        sort(x.begin(), x.end());

        if (x.size() == n)
            answer *= x[1];
        else if (x.size() == n - 1)
            answer *= x[0];
    }

    cout << answer << endl;

    return 0;
}