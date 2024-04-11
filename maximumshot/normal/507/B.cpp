// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    LD r, x, y, sx, sy;

    cin >> r >> x >> y >> sx >> sy;

    LD dist = sqrt((sx - x) * (sx - x) + (sy - y) * (sy - y));

    cout << ceil(dist / (2 * r)) << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();
 
    return 0;
}