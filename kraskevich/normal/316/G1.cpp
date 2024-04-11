#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

set<string> ans;
vector<string> t;
vector<int> lo, hi;

int cnt(string b, string a)
{
    if (b.length() > a.length())
        return 0;
    //cout << b << " " << a << " ";
    string s = b + '&' + a;
    int n = s.length();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        if (z[i] == b.length())
            res++;
    //cout << res << endl;
    return res;
}

bool good(string a)
{
    for (int i = 0; i < t.size(); i++)
    {
        int cur = cnt(a, t[i]);
        if (cur < lo[i] || cur > hi[i])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int q;
    cin >> q;
    t.resize(q);
    lo.resize(q);
    hi.resize(q);
    for (int i = 0; i < q; i++)
        cin >> t[i] >> lo[i] >> hi[i];

    int n = s.length();
    for (int i = 0; i < n; i++)
        for (int j = 1; i + j - 1 < n; j++)
        {
            string a = s.substr(i, j);
            if (ans.count(a))
                continue;
            if (good(a))
                ans.insert(a);
        }

    cout << ans.size();

    return 0;
}