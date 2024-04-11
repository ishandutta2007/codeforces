//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 19.04.11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
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

string a, b;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b;
    int aa = 0, bb = 0;
    for ( int i = 0; i < a.size(); i++ ) aa += a[i] - '0';
    for ( int i = 0; i < b.size(); i++ ) bb += b[i] - '0';
    if ( aa % 2 == 1 ) aa++;
    if ( aa >= bb ) cout << "YES"; else cout << "NO";
    return 0;
}