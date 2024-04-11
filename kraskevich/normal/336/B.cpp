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
#include <list>

using namespace std;

#define PII pair<int, int>
#define PLL pair<long long, long long>
#define PIL pair<int, long long>
#define PLI pair<long long, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __dv__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__
#define y0 y100500_0
#define y1 y100500_1
#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 100 * 1000 + 10;
LL sum[N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    LL m, r;
    cin >> m >> r;
    double res = 0;
    double s2 = sqrt(2);
    sum[0] = 0;
    for (int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + 2ll * i;
    LD c = r / ((LD)m * m);
    for (int i = 1; i <= m; i++)
    {
        double mid = 2;
        double L = 0, R = 0;
        if (i > 1)
        {
            double lup = (2 + s2) + (i - 2) * (2 * s2);
            double lhor = sum[i - 2];
            L = lup + lhor;
        }
        if (i < m)
        {
            double rup = (m - i - 1) * (2 * s2) + (2 + s2);
            double rhor = sum[m - i - 1];
            R = rup + rhor;
        }
        res += (mid + L + R) * c;
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res;

    return 0;
}