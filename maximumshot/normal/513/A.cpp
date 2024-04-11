#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 62);    
const double pi = acos(-1.0);

using namespace std;

LL Abs (LL x) {return (x >= 0ll?x : -x);}

bool solve()
{
    int n1, n2, k1, k2;

    cin >> n1 >> n2 >> k1 >> k2;

    if(n1 > n2) cout << "First";
    else cout << "Second";

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}