//
//  main.cpp
//  telephone_code
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

char st[33333][22];
int n, m;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n; gets( st[0] );
    for (int i = 0; i < n; i++) gets( st[i] );
    m = int( strlen( st[0] ) );
    for (int i = 0; i < m; i++)
    {
        bool fl = true;
        for (int j = 1; j < n; j++) if (st[0][i] != st[j][i]) fl = false;
        if (fl == false)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}