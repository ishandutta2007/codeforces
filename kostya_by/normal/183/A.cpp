//
//  main.cpp
//  shtab
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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

int n;
long long a = 1, b = 1;
string st;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n); 
    for (int i = 0; i < n; i++)
    {
        cin >> st;
        if (st == "ULDR") 
        {
            ++a; ++b;
            continue;
        }
        if (st == "UR" || st == "DL") ++a; else ++b;
    }
    cout << a * b;
    return 0;
}