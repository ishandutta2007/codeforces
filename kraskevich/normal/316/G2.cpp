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

const int N = 2222;
vector<string> t;
vector<int> lo, hi;
int sum[N];
bool ok[N];
int st[N];
int res = 0;

void cnt(string b, string a)
{
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
    for (int i = 0; i < n; i++)
    {
        if (i > b.length())
            sum[z[i]]++;
    }
}

void work(string a, int start)
{
    int n = a.length();
    fill(ok, ok + n + 1, 1);
    for (int i = 0; i < t.size(); i++)
    {
        fill(sum, sum + n + 1, 0);
        cnt(a, t[i]);
        for (int j = n - 1; j >= 0; j--)
            sum[j] += sum[j + 1];
        for (int j = 0; j <= n; j++)
            if (sum[j] < lo[i] || sum[j] > hi[i])
                ok[j] = false;
    }
    for (int j = start; j <= n; j++)
        if (ok[j])
            res++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string sss;
    cin >> sss;

    int q;
    cin >> q;
    t.resize(q);
    lo.resize(q);
    hi.resize(q);
    for (int i = 0; i < q; i++)
        cin >> t[i] >> lo[i] >> hi[i];


    for (int f = 0; f < sss.length(); f++)
    {
        string t = sss.substr(f, sss.length() - f);
        string s = t + '$' + sss;
       // cerr << s << endl;
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
        st[f] = 1;
        for (int i = 0; i < n; i++)
            if (i > t.length() && i - (int)t.length() - 1 < f)
                st[f] = max(st[f], z[i] + 1);
    }

    /*for (int i = 0; i < sss.length(); i++)
        cout << st[i] << " ";
    cout << endl;*/

    int n = sss.length();
    for (int i = 0; i < n; i++)
    {
        string a = sss.substr(i, n - i);
        work(a, st[i]);
    }

    cout << res;

    return 0;
}