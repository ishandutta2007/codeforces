//
//  main.cpp
//  bank
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

string st, tt[5], ii[1111];
bool negative = false;
int h = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> st;
    if (st[0] == '-') negative = true;
    int start = 0;
    if (negative == true) start = 1;
    for (int i = start; i < st.size(); i++)
    {
        if (st[i] == '.') 
        {
            ++h;
            continue;
        }
        tt[h] = tt[h] + st[i];
    }
    while (tt[1].size() < 2) tt[1] = tt[1] + '0';
    int l = 0, r = tt[0].size() - 1;
    while ( l < r ) swap( tt[0][l++], tt[0][r--] );
    h = -1;
    for (int i = 0; i < tt[0].size(); i++)
    {
        if (i % 3 == 0) ++h;
        ii[h] = ii[h] + tt[0][i];
    }
    for (int i = 0; i < 1111; i++)
    {
        if (ii[i].size() == 0) break;
        int l = 0, r = ii[i].size() - 1;
        while (l < r) swap( ii[i][l++], ii[i][r--] );
    }
    if (negative == true) cout << '(';
    cout << '$';
    for (int i = h; i > 0; i--) cout << ii[i] << ',';
    cout << ii[0] << '.';
    for (int i = 0; i < 2; i++) cout <<  tt[1][i];
     if (negative == true) cout << ')';
    return 0;
}