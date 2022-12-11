//
//  main.cpp
//  chat
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

int nn = 0, ans = 0;
char st[1111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while (gets( st ) != '\0')
    {
        if (st[0] == '+')
        {
            ++nn;
            continue;
        }
        if (st[0] == '-')
        {
            --nn;
            continue;
        }
        int ii;
        for (int i = 0; i < strlen( st ); i++) if ( st[i] == ':' )
        {
            ii = i;
            break;
        }
        ++ii;
        int n = strlen( st );
        ans += nn * (n - ii);
    }
    cout << ans;
    return 0;
}