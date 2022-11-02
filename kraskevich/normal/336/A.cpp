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



int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    LL xx, yy;
    cin >> xx >> yy;
    LL x = xx;
    LL y = yy;
    if (x < 0)
        x = -x;
    if (y < 0)
        y = -y;
    LL tx = x;
    LL ty = y;
    x += ty;
    y += tx;
    if (xx < 0)
        x = -x;
    if (yy < 0)
        y = -y;
    if (x < 0)
    {
        cout << x << " " << 0 << " " << 0 << " " << y;
    }
    else
    {
        cout << 0 << " " << y << " " << x << " " << 0;
    }

    return 0;
}