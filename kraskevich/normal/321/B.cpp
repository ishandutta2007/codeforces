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

#define PII pair<int, int>
#define F first
#define S second

typedef long long LL;


vector<int> c, aj, dj;
int n, m, x;
string t;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> x;
        if (t == "ATK")
            aj.push_back(x);
        else
            dj.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        c.push_back(x);
    }
    sort(c.begin(), c.end());
    sort(aj.begin(), aj.end());
    sort(dj.begin(), dj.end());
    int res = 0;
    for (int cnt = 1; cnt <= min(c.size(), aj.size()); cnt++)
    {
        int cur = 0;
        bool ok = true;
        int f = 0;
        for (int i = (int)c.size() - cnt; i < (int)c.size(); i++)
        {
            if (c[i] < aj[f])
            {
                ok = false;
                break;
            }
            cur += c[i] - aj[f];
            f++;
        }
        if (ok)
            res = max(res, cur);
    }
    multiset<int> have(c.begin(), c.end());
    bool ok = true;
    int cur = 0;
    for (int i = 0; i < dj.size(); i++)
    {
        x = dj[i];
        auto it = have.upper_bound(x);
        if (it == have.end())
        {
            ok = false;
            break;
        }
        have.erase(it);
    }
    for (int i = 0; i < aj.size(); i++)
    {
        x = aj[i];
        auto it = have.lower_bound(x);
        if (it == have.end())
        {
            ok = false;
            break;
        }
        have.erase(it);
        cur += *it - x;
    }
    for (auto v: have)
        cur += v;
    if (ok)
        res = max(res, cur);

    cout << res;

    return 0;
}