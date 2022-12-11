//
//  main.cpp
//  cubic
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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

int a, b;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b;
    a = max(a, b);
    if (a == 1) cout << "1/1";
    if (a == 2) cout << "5/6";
    if (a == 3) cout << "2/3";
    if (a == 4) cout << "1/2";
    if (a == 5) cout << "1/3";
    if (a == 6) cout << "1/6";
    return 0;
}