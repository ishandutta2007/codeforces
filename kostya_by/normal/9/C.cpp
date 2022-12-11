//
//  main.cpp
//  ones and zeroes
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

int n, ans, cur, len;

void gen(int pos)
{
    if (pos == len)
    {
        if (cur <= n && cur != 0)
        {
            ++ans;
        }
        //cout << cur << endl;
    }
    if (pos < len)
    {   
        for (int i = 0; i < 2; i++)
        {
            if (i == 0 && pos == 0) continue;
            cur *= 10;
            cur += i;
            gen(pos + 1);
            cur /= 10;
        }
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        len = i;
        gen( 0 );
    }
    if (n == 1000000000) ++ans;
    cout << ans;
    return 0;
}