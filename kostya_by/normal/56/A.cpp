//
//  main.cpp
//  bar
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

bool number(char c)
{
    if ('0' <= c && c <= '9') return true;
    return false;
}

int n, ans = 0;
string st;

string lib[11] = { "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"}; 

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> st;
        if ( number( st[0] ) == true )
        {
            while (st.size() < 4) st = '0' + st;
            if (st < "0018") ++ans;
            continue;
        }
        for (int j = 0; j < 11; j++) if (lib[j] == st) ++ans;
    }
    cout << ans;
    return 0;
}