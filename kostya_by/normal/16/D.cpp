//
//  main.cpp
//  logging
//
//  Created by Sokol Kostya's MacBook on 21.01.11.
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
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, cnt = 1;

struct Tdate
{
    int hh, mm;
    int next()
    {
        ++mm;
        if (mm == 60)
        {
            mm = 0;
            ++hh;
        }
        if (hh == 24)
        {
            hh = 0;
            return 1;
        }
        return 0;
    }
    int ord(char c)
    {
        int res = c - '0';
        return res;
    }
    void get_date()
    {
        char s[111];
        gets(s);
        hh = ord(s[1]) * 10 + ord(s[2]);
        mm = ord(s[4]) * 10 + ord(s[5]);
        if (s[7] == 'p') hh += 12;
        if (hh == 12) hh = 0;
        if (hh == 24) hh = 12;
    }
};

bool operator!=(Tdate d1, Tdate d2)
{
    if (d1.hh == d2.hh && d1.mm == d2.mm) return false;
    return true;
};

bool operator==(Tdate d1, Tdate d2)
{
    if (d1.hh == d2.hh && d1.mm == d2.mm) return true;
    return false;
};

Tdate dates[111], now;

char s[111];

int main (int argc, const char * argv[])
{
    cin >> n; gets(s);
    for (int i = 0; i < n; i++) dates[i].get_date();
    now = dates[0];
    int in_row = 1;
    for (int i = 1; i < n; i++)
    {
        //cout << in_row << endl;
        if (in_row == 10)
        {
            cnt += now.next();
            in_row = 1;
        }
        if (now != dates[i])
        {
            in_row = 1;
        }
        if (now == dates[i])
        {
            ++in_row;
        }
        while (now != dates[i]) cnt += now.next();
    }
    cout << cnt;
    return 0;
}