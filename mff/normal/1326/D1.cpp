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

using namespace std;

#define endl '\n'

vector<int> manacher(const string &s)
{
    int n = 2 * s.length();
    vector<int> rad(n);

    for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
    {
        for (; i >= j && i + j + 1 < n && s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j)
            ;
        rad[i] = j;
        for (k = 1; i >= k &&
                    rad[i] >= k && rad[i - k] != rad[i] - k;
             ++k)
            rad[i + k] = min(rad[i - k], rad[i] - k);
    }

    return rad;
}

bool is_pal(const vector<int> &rad, int b, int e)
{
    int n = rad.size() / 2;
    return b >= 0 && e < n && rad[b + e] >= e - b + 1;
}

string solve(string &s)
{
    int t = 0, n = s.length();

    while (2 * (t + 1) <= s.length())
    {
        if (s[t] == s[n - 1 - t])
            ++t;
        else
            break;
    }

    auto man = manacher(s);

    // 0 1 2 3 4 5 | 6
    // 1

    int B = 0, E = 0, R = 1;

    auto check = [&](int b, int e) {
        int r = e - b + 1;
        int le = b;
        int ri = n - 1 - e;
        if (min(le, ri) <= t)
        {
            int border = min(le, ri);
            int size = 2 * border + e - b + 1;
            if (size > R)
            {
                R = size;
                B = b;
                E = e;
            }
        }
    };

    for (int i = 0; i < man.size(); i += 2)
    {
        int b = i / 2 - man[i] / 2;
        int e = i / 2 + man[i] / 2;
        check(b, e);
    }

    for (int i = 1; i < man.size(); i += 2)
    {
        if (man[i] == 0)
            continue;
        int b = i / 2 - man[i] / 2 + 1;
        int e = i / 2 + man[i] / 2;
        check(b, e);
    }

    string res = "";

    int r = E - B + 1;
    int le = B;
    int ri = n - 1 - E;
    int border = min(le, ri);

    for (int i = 0; i < border; ++i)
    {
        res += s[i];
    }

    for (int i = B; i <= E; ++i)
    {
        res += s[i];
    }

    for (int i = n - border; i < n; ++i)
    {
        res += s[i];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        string a = solve(s);
        cout << a << endl;
    }

    return 0;
}