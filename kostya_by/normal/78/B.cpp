//
//  main.cpp
//  easter eggs
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

string ss = "ROYGBIV";
int n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n / 7; i++) cout << ss;
    n %= 7;
    if (n == 1) cout << "G";
    if (n == 2) cout << "YG";
    if (n == 3) cout << "OYG";
    if (n == 4) cout << "OYGB";
    if (n == 5) cout << "OYGBI";
    if (n == 6) cout << "OYGBIV";
    return 0;
}