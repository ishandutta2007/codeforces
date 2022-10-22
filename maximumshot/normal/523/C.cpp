#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

bool solve()
{
    string s, t;

    cin >> s >> t;

    int n, m;

    n = (int)s.size();
    m = (int)t.size();

    int l = m + 1, r = -1;
    int pos = 0;

    for(int i(0);i < m;i++)
    {
        if(t[i] == s[pos]) pos++;
        if(pos == n)
        {
            l = i;
            break;
        }
    }

    pos = n - 1;

    for(int i(m - 1);i >= 0;i--)
    {
        if(t[i] == s[pos]) pos--;
        if(pos == -1)
        {
            r = i;
            break;
        }
    }

    cout << max(0, r - l) << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}