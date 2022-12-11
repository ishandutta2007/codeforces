//
//  main.cpp
//  broken_checker
//
//  Created by Sokol Kostya's MacBook on 30.05.11.
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

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a, b;
    cin >> a;
    if (a == 1) b = 2; //
    if (a == 2) b = 3; 
    if (a == 3) b = 1; //
    if (a == 4) b = 2;
    if (a == 5) b = 1;
    cout << b;
    return 0;
}