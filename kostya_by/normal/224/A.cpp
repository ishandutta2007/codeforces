//
//  main.cpp
//  task1_div2_upsolving
//
//  Created by Sokol Kostya's MacBook on 16.09.11.
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

int a, b, c, l1, l2, l3;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> a >> b >> c;
    for ( int i = 1; i <= a; i++ )
    {
        if ( a % i != 0 ) continue;
        int l1 = i, l2 = a / i;
        if ( ( b % l1 == 0 && c % l2 == 0 && b / l1 == c / l2 ) )
        {
            l3 = b / l1;
            cout << 4 * ( l1 + l2 + l3 );
            return 0;
        }
        swap(l1, l2);
        if ( ( b % l1 == 0 && c % l2 == 0 && b / l1 == c / l2 ) )
        {
            l3 = b / l1;
            cout << 4 * ( l1 + l2 + l3 );
            return 0;
        }
    }
    return 0;
}