//
//  main.cpp
//  soda drinking
//
//  Created by Sokol Kostya's MacBook on 28.04.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

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
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a, b, c, d, e, aa, bb, cc;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> a >> b >> c >> d >> e;
    a *= b;
    c *= d;
    cin >> aa;
    bb = 1;
    cin >> cc;
    aa *= n;
    bb *= n;
    cc *= n;
    cout << min( a / aa, min( c / bb, e / cc) );
    return 0;
}