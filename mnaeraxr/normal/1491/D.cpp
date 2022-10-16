#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a > b)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        int t = 0;
        while (b)
        {
            t += a & 1;
            a >>= 1;

            if (b & 1)
            {
                if (t == 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    t--;
                }
            }
            b >>= 1;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}