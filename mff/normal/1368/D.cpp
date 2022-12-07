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

    vector<long long> b(20);
    vector<long long> r(n);

    for (int i = 0; i < n; ++i)
    {
        long long u;
        cin >> u;

        for (int j = 0; j < 20; ++j)
        {
            if (u >> j & 1)
                b[j]++;
        }
    }

    long long answer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 20; ++j)
            if (b[j])
            {
                b[j]--;
                r[i] |= 1 << j;
            }

        answer += r[i] * r[i];
    }

    cout << answer << endl;

    return 0;
}