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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int c = 0;

    for (auto x : s)
    {
        if (x == '(')
            c++;
    }

    int t = n / 2 - c;

    if (t < 0)
    {
        cout << ":(" << endl;
        return;
    }

    int balance = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '?')
        {
            if (t > 0)
            {
                s[i] = '(';
                t--;
            }
            else
            {
                s[i] = ')';
            }
        }

        if (s[i] == '(')
            balance++;
        else
            balance--;

        if (balance <= 0 && i + 1 < n)
        {
            cout << ":(" << endl;
            return;
        }
    }

    if (balance != 0)
    {
        cout << ":(" << endl;
    }
    else
    {

        cout << s << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}