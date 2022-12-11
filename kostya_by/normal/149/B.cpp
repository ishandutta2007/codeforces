//
//  main.cpp
//  cf106task2
//
//  Created by Sokol Kostya's MacBook on 10.02.11.
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

vector< long long > aa, bb;
string s, a = "", b = "";
bool fl = false;

bool ok(long long base)
{
    long long a = 0, b = 0, pt = 1;
    for (int i = 0; i < aa.size(); i++)
    {
        a += pt * aa[i];
        pt *= base;
    }
    pt = 1;
    for (int i = 0; i < bb.size(); i++)
    {
        b += pt * bb[i];
        pt *= base;
    }
    if (a >= 0 && a <= 23 && b >= 0 && b <= 59) return true;
    return false;
};

int main (int argc, const char * argv[])
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ':') 
        {
            fl = true;
            continue;
        }
        if (fl == false)
        {
            int nn = s[i] - '0';
            if (nn >= 0 && nn <= 9)
            {
                aa.push_back(nn);
                continue;
            }
            nn = s[i] - 'A';
            aa.push_back( nn + 10 );
            continue;
        }
        int nn = s[i] - '0';
        if (nn >= 0 && nn <= 9)
        {
            bb.push_back(nn);
            continue;
        }
        nn = s[i] - 'A';
        bb.push_back( nn + 10 );
    }
    int ll = 0, rr = aa.size() - 1;
    while (ll < rr)
    {
        swap( aa[ll], aa[rr] );
        ++ll; --rr;
    }
    while (aa.size() > 1 && aa.back() == 0) aa.erase( aa.end() - 1 );
    ll = 0, rr = bb.size() - 1;
    while (ll < rr)
    {
        swap( bb[ll], bb[rr] );
        ++ll; --rr;
    }
    while (bb.size() > 1 && bb.back() == 0) bb.erase( bb.end() - 1 );
    if (aa.size() * bb.size() == 1)
    {
        if (aa[0] >= 0 && aa[0] <= 23) cout << -1; else cout << 0;
        return 0;
    }
    int mx = 0;
    for (int i = 0; i < aa.size(); i++) mx = max(mx, int(aa[i]));
    for (int i = 0; i < bb.size(); i++) mx = max(mx, int(bb[i]));
    int cnt = 0;
    mx++;
    for (int i = mx; ; i++)
    {
        long long ii = i;
        if (ok(ii))
        {
            cnt++;
            cout << i << " ";
            continue;
        }
        break;
    }
    if (cnt == 0) cout << 0;
    return 0;
}