//
//  main.cpp
//  very_lucky_numbers
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

string ss = "47";
char s[111111], cur[111111];
int n, c[2];
bool fl = false;

void gen_min(int len)
{
    for (int i = 0; i < len; i++) cur[i] = '7';
    for (int i = 0; i < len / 2; i++) cur[i] = '4';
}

void gen_max(int len)
{
    for (int i = 0; i < len; i++) cur[i] = '4';
    for (int i = 0; i < len / 2; i++) cur[i] = '7';
}

bool cc()
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] > cur[i]) return true;
        if (s[i] < cur[i]) return false;
    }
    return false;
}

void gen(int pos, bool bg)
{
    if (fl == true) return;
    if (pos == n)
    {
        fl = true;
    }
    for (int i = 0; i < 2; i++)
    {
        if (fl == true) return;
        if (c[i] == 0) continue;
        if (bg == true)
        {
            --c[i];
            cur[pos] = ss[i];
            gen( pos + 1, true );
            ++c[i];
            continue;
        }
        if (s[pos] > ss[i]) continue;
        bool ff = true;
        if (s[pos] == ss[i]) ff = false;
        --c[i];
        cur[pos] = ss[i];
        gen( pos + 1, ff );
        ++c[i];
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s );
    n = int( strlen( s ) );
    if (n % 2 == 1) 
    {
        gen_min(n + 1);
        for (int i = 0; i <= n; i++) putchar( cur[i] );
        return 0;
    }
    gen_max(n);
    if (cc() == true)
    {
        gen_min(n + 2);
        for (int i = 0; i <= n + 1; i++) putchar( cur[i] );
        return 0;
    }
    c[0] = c[1] = n / 2;
    gen( 0, false );
    for (int i = 0; i < n; i++) putchar( cur[i] );
    return 0;
}