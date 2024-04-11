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

char c0;
vector<char> c;
long long ans = 0;
vector<bool> u(10, false);

void work(int pos)
{
    if (pos == c.size())
    {
        ans++;
        return;
    }
    for (int d = 0; d < 10; d++)
    {
        if (u[d] || c[pos] == c0 && d == 0)
            continue;
        u[d] = true;
        work(pos + 1);
        u[d] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    long long res = 1;
    int zero = 0;
    int n = s.length();
    if (s[0] == '0')
    {
        cout << '0';
        return 0;
    }
    if (s[0] == '?')
        res = 9;
    c0 = s[0];
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?' && i > 0)
            zero++;
        if ('0' <= s[i] && s[i] <= '9')
            continue;
        if ('A' <= s[i] && s[i] <= 'J')
            cnt[s[i] - 'A']++;
    }
    for (int i = 0; i < 10; i++)
        if (cnt[i])
            c.push_back(char('A' + i));
    if (c.size())
        work(0);
    else
        ans = 1;
    res *= ans;

    cout << res;
    for (int i = 0; i < zero; i++)
        cout << 0;

    return 0;
}