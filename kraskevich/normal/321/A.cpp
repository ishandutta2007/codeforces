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

const int N = 111;

long long dx[N], dy[N];
long long x, y, tx, ty;

bool ok(LL a1, LL b1, LL c1, LL a2, LL b2, LL c2)
{
    c1 -= b1;
    c2 -= b2;
    if (a1 == 0 && a2 == 0)
        return c1 == 0 && c2 == 0;
    if (a1 == 0)
        swap(a1, a2), swap(c1, c2);
    LL k;
    if (c1 % a1)
        return false;
    else
        k = c1 / a1;
    if (k < 0)
        return false;
    if (a2 * k != c2)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    cin >> x >> y;
    dx[0] = dy[0] = 0;
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        dx[i+1] = dx[i];
        dy[i+1] = dy[i];
        if (s[i] == 'U')
            dy[i+1]++;
        if (s[i] == 'D')
            dy[i+1]--;
        if (s[i] == 'L')
            dx[i+1]--;
        if (s[i] == 'R')
            dx[i+1]++;
    }
    tx = dx[n];
    ty = dy[n];
    for (int i = 0; i <= n; i++)
    {
        long long a1 = tx;
        long long b1 = dx[i];
        long long c1 = x;
        long long a2 = ty;
        long long b2 = dy[i];
        long long c2 = y;
        if (ok(a1, b1, c1, a2, b2, c2))
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}