#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, a[2222][2222], hh[2222], vv[2222], ans = 0;
char s[2222];

int main (int argc, const char * argv[])
{
    cin >> n;
    gets(s);
    for (int i = 1; i <= n; i++)
    {
        gets(s);
        for (int j = 1; j <= n; j++) if (s[j - 1] == '0') a[i][j] = 0; else a[i][j] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int ii = i;
        int jj = n;
        while (ii != jj) 
        {
            int now = a[ii][jj] + hh[jj] + vv[ii];
            if (now % 2 == 1)
            {
                ans++;
                hh[jj]++; vv[ii]++;
            }
            --jj;
        }
        a[ii][jj] += hh[jj] + vv[ii];
        a[ii][jj] %= 2;
    }
    memset(vv, 0, sizeof(vv));
    memset(hh, 0, sizeof(hh));
    for (int i = n; i >= 1; i--)
    {
        int ii = i;
        int jj = 1;
        while (ii != jj) 
        {
            int now = a[ii][jj] + hh[jj] + vv[ii];
            if (now % 2 == 1)
            {
                ans++;
                hh[jj]++; vv[ii]++;
            }
            ++jj;
        }
        a[ii][jj] += hh[jj] + vv[ii];
        a[ii][jj] %= 2;
    }
    for (int i = 1; i <= n; i++)
    {
        int ii = i;
        int jj = i;
        if (a[ii][jj] == 1) ++ans;
    }
    cout << ans;
    return 0;
}