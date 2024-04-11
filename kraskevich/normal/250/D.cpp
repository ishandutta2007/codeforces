#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>
#include <cmath>

using namespace std;


//#define DEBUG 1

const double inf = 1e18;
const int N = 2 * 100 * 1000;
double yL[N], yR[N], len[N];
double ans = inf;
int n, m, ansL, ansR;
double a, b;

double sqr(double A)
{
    return A * A;
}

void updRes(int i, int j)
{
    double cur = sqrt( sqr(a) + sqr(yL[i]) ) + sqrt( sqr(b - a) + sqr(yL[i] - yR[j]) ) + len[j];
    if (cur < ans)
    {
        ans = cur;
        ansL = i + 1;
        ansR = j + 1;
    }
}
    
int main()
{
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
    #endif
    
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; ++i)
         cin >> yL[i];
    for (int i = 0; i < m; ++i)
        cin >> yR[i];
    for (int i = 0; i < m; ++i)
        cin >> len[i];
    
    int pos = 0;
    for (int i = 0; i < m; ++i)
    {
        double wanty = a / b * yR[i];
        while (pos < n - 1 && yL[pos] <= wanty)
            ++pos;
        for (int j = max(0, pos - 1); j < min(n, pos + 1); ++j)
            updRes(j, i);
    }
    
    cout << ansL << " " << ansR;
    
    
    return 0;
}