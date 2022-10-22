#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>

#define vec vector
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    LL n;

    cin >> n;

    if(n % 2) cout << "black\n";
    else cout << "white\n1 2\n";
    
    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}