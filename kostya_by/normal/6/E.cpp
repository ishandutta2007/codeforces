//
//  main.cpp
//  exposure
//
//  Created by Sokol Kostya's MacBook on 08.02.11.
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

class cmp1
{
public:
    bool operator()(pair<int,int> p1, pair<int,int> p2)
    {
        if (p1.first < p2.first) return true;
        if ((p1.first == p2.first) && (p1.second < p2.second)) return true;
        return false;
    };
};

class cmp2
{
public:
    bool operator()(pair<int,int> p1, pair<int,int> p2)
    {
        if (p1.first > p2.first) return true;
        if ((p1.first == p2.first) && (p1.second < p2.second)) return true;
        return false;
    };
};

set< pair<int,int> , cmp1> s1;
set< pair<int,int> , cmp1>::iterator i1;
set< pair<int,int> , cmp2> s2;
set< pair<int,int> , cmp2>::iterator i2;

int a[111111], ll, rr, n, ans[111111], kk, aa = 1, bb = 0;


int main (int argc, const char * argv[])
{
    scanf("%d%d", &n, &kk);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    ll = 0;
    rr = 0;
    s1.insert( mp(a[rr], rr) );
    s2.insert( mp(a[rr], rr) );
    ans[0] = 0;
    while (rr + 1 != n)
    {
        ++rr;
        s1.insert( mp(a[rr], rr) );
        s2.insert( mp(a[rr], rr) );
        while ( (*s2.begin()).first - (*s1.begin()).first > kk )
        {
            s1.erase( s1.find( mp(a[ll], ll) ) );
            s2.erase( s2.find( mp(a[ll], ll) ) );
            ++ll;
        }
        //cout << ll << " " << rr << " " << (*s2.begin()).first << " " <<   (*s1.begin()).first << endl;
        ans[rr] = ll;
        aa = max(aa, rr - ll + 1);
    }
    for (int i = 0; i < n; i++) if (i - ans[i] + 1 == aa) bb++;
    printf("%d %d\n", aa, bb);
    for (int i = 0; i < n; i++) if (i - ans[i] + 1 == aa) printf("%d %d\n", ans[i] + 1, i + 1);
    return 0;
}