//
//  main.cpp
//  superagent
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

string st[3], ans = "YES";

void check(int i, int j, int ii, int jj)
{
    if (st[i][j] != st[ii][jj]) ans = "NO";
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> st[0] >> st[1] >> st[2];
    check(0, 0, 2, 2);
    check(0, 1, 2 ,1);
    check(0, 2, 2, 0);
    check(1, 0, 1, 2);
    cout << ans;
    return 0;
}