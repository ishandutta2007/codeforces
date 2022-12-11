//
//  main.cpp
//  lucky invent
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

char s1[111111], s2[111111];
int n, c47, c74;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s1 ); gets( s2 );
    n = strlen( s1 );
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '4' && s2[i] == '7') ++c47;
        if (s1[i] == '7' && s2[i] == '4') ++c74;
    }
    cout << max(c47, c74);
    return 0;
}