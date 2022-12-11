//
//  main.cpp
//  brackets1
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

int ans = 0, cur = 0;
char st[1111111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st );
    int n = strlen( st );
    for (int i = 0; i < n; i++)
    {
        if ( st[i] == '(' )
        {
            ++ans;
            ++cur;
            continue;
        }
        if (cur == 0) continue;
        --cur;
        ++ans;
    }
    ans -= cur;
    cout << ans;
    return 0;
}