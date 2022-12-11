//
//  main.cpp
//  dragons
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

int a, b, c, d, n, ans = 0;

int main (int argc, const char * argv[])
{
    cin >> a >> b >> c >> d >> n;
    for (int i = 1; i <= n; i++) if (i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0) ++ans;
    cout << ans;
    return 0;
}