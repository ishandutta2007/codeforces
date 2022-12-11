//
//  main.cpp
//  kalevich and chess
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

char ss[8];
int a[8][8], ans = 111111, rr[8], cc[8], s1 = 0, s2 = 0;

bool check()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (a[i][j] == 0 && ( rr[i] == 1 || cc[j] == 1 )) return false;
            if (a[i][j] == 1 && rr[i] == 0 && cc[j] == 0) return false;
        }
    }
    return true;
}

void gen1(int pos)
{
    if (pos == 8)
    {
        if (check() == true) ans = min(ans, s1 + s2);
    }
    if (pos < 8)
    {
        for (int i = 0; i < 2; i++)
        {
            cc[pos] = i;
            s2 += i;
            gen1(pos + 1);
            s2 -= i;
        }
    }
}

void gen2(int pos)
{
    if (pos == 8)
    {
        gen1(0);
    }
    if (pos < 8)
    {
        for (int i = 0; i < 2; i++)
        {
            rr[pos] = i;
            s1 += i;
            gen2(pos + 1);
            s1 -= i;
        }
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 0; i < 8; i++)
    {
        gets( ss );
        for (int j = 0; j < 8; j++) if (ss[j] == 'W') a[i][j] = 0; else a[i][j] = 1;
    }
    gen2(0);
    cout << ans;
    return 0;
}