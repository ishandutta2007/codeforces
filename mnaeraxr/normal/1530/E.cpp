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

namespace asl
{
    template <typename T>
    using vec = std::vector<T>;

} 

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void check(string s, string r)
{
    sort(s.begin(), s.end());
    sort(r.begin(), r.end());
    assert(s == r);
}

void solve()
{
    string s;
    cin >> s;

    vec<int> freq(26);
    int tot = 0;

    for (auto c : s)
        if (++freq[c - 'a'] == 1)
            tot++;

    if (tot == 1)
    {
        cout << s << endl;
        
        return;
    }

    int m = s.length();

    int j = 0;
    while (j < 26 && freq[j] != 1)
        ++j;

    if (j < 26)
    {
        string r;
        r += (char)('a' + j);
        freq[j]--;
        for (int i = 0; i < 26; ++i)
            for (int k = 0; k < freq[i]; ++k)
                r += (char)('a' + i);

        check(s, r);
        cout << r << endl;
        
        return;
    }

    j = 0;
    while (freq[j] == 0)
        ++j;

    int n = s.length();
    if (freq[j] <= n / 2 + 1)
    {
        string r;
        r += (char)('a' + j);
        freq[j]--;

        for (int i = j + 1; i < 26; ++i)
        {
            for (int k = 0; k < freq[i]; ++k)
            {
                if (freq[j])
                {
                    r += (char)('a' + j);
                    freq[j]--;
                }
                r += (char)('a' + i);
            }
        }

        if (freq[j])
            r += (char)('a' + j);

        check(s, r);
        cout << r << endl;
        
        return;
    }

    if (tot > 2)
    {
        string r;
        r += (char)('a' + j);
        int k = j + 1;
        while (freq[k] == 0)
            ++k;
        r += (char)('a' + k);
        freq[k]--;

        int k2 = k + 1;
        while (freq[k2] == 0)
            k2++;

        for (int i = 1; i < freq[j]; ++i)
            r += (char)('a' + j);
        r += (char)('a' + k2);
        freq[k2]--;

        for (int i = j + 1; i < 26; ++i)
            for (int p = 0; p < freq[i]; ++p)
                r += (char)('a' + i);

        check(s, r);
        cout << r << endl;
        return;
    }

    if (tot == 2)
    {
        string r;
        r += (char)('a' + j);
        int k = j + 1;
        while (freq[k] == 0)
            ++k;

        for (int i = 0; i < freq[k]; ++i)
            r += (char)('a' + k);

        for (int i = 1; i < freq[j]; ++i)
            r += (char)('a' + j);
        check(r, s);
        cout << r << endl;
        
        return;
    }

    assert(false);
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