//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 22.12.11.
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
char st[ 100010 ];
vector< char > ans;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st );
    n = strlen( st );
    bool fl = false;
    for ( int i = 0; i < n; i++ )
    {
        if ( st[i] == '0' && fl == false )
        {
            fl = true;
            continue;
        }
        ans.pb( st[i] ); 
    }
    if ( fl == false ) ans.pop_back();
    for ( int i = 0; i < ans.size(); i++ ) putchar( ans[i] );
    return 0;
}