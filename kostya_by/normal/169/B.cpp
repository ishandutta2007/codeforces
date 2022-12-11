//
//  main.cpp
//  digit replacing
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
int n, m, num[10];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s1 ); gets( s2 );
    n = strlen( s1 );
    m = strlen( s2 );
    for (int i = 0; i < m; i++) num[ s2[i] - '0' ]++;
    for (int i = 0; i < n; i++)
    {
        int cur = s1[i] - '0';
        for (int j = 9; j > cur; j--)
        {
            if (num[j] != 0)
            {
                s1[i] = '0' + j;
                --num[j];
                break;
            }
        }
    }
    puts( s1 );
    return 0;
}