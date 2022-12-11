//
//  main.cpp
//  lucky sum
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

int l, r, len;
long long cur;
long long ans = 0;
long long a[2] = {4, 7};
vector<long long> ll;

void gen(int pos)
{
    if (pos == len)
    {
        ll.pb( cur );
    }
    if (pos < len)
    {
        for (int i = 0; i < 2; i++)
        {
            cur *= 10;
            cur += a[i];
            gen( pos + 1 );
            cur /= 10;
        }
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> l >> r;
    for (int i = 1; i <= 10; i++)
    {
        len = i;
        gen( 0 );
    }
    for (int i = 0; i < ll.size(); i++)
    {
        long long l1, r1;
        if (i == 0) l1 = 1; else l1 = ll[i - 1] + 1;
        r1 = ll[i];
        l1 = max( l1, 1ll * l );
        r1 = min( r1, 1ll * r );
        if (l1 > r1) continue;
        long long a = r1 - l1 + 1;
        long long b = ll[i];
        ans += a * b;
    }
    cout << ans;
    return 0;
}