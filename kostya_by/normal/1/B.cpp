//
//  main.cpp
//  el_tables
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

string numb[1111111];
char cur[1111];
string tt[11];
int n, h;
int last; // 0 - nothing, 1 - letter, 2 - number

bool number(char c)
{
    if ('0' <= c && c <= '9') return true;
    return false;
}

int get_num()
{
    int res = 0;
    for (int i = 0; i < tt[0].size(); i++)
    {
        res *= 26;
        res += tt[0][i] - 'A' + 1;
    }
    return res;
}

void do_first()
{
    int aa = get_num();
    cout << 'R' << tt[1] << 'C' << aa << endl;
}

void get_st()
{
    int aa = 0;
    for (int i = 0; i < tt[1].size(); i++) aa = (10 * aa) + tt[1][i] - '0';
    tt[4] = "";
    while (aa != 0)
    {
        int cur = aa % 26;
        if (cur == 0) { cur = 26; aa /= 26; --aa;} else  aa /= 26;
        tt[4] = tt[4] + char( cur + 'A' - 1 );
    }
    int l = 0, r = tt[4].size() - 1;
    while (l < r) swap( tt[4][l++], tt[4][r--] );
}

void do_second()
{
    swap(tt[1], tt[3]);
    get_st();
    cout << tt[4] << tt[3] << endl;
}


int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n; gets( cur );
    for (int q = 0; q < n; q++)
    {
        last = 0;
        h = 0;
        gets( cur );
        tt[0] = "";
        for (int i = 0; i < strlen( cur ); i++)
        {
            if (number( cur[i] ) == true)
            {
                if (last == 1)
                {
                    ++h;
                    tt[h] = "";
                }
                last = 2;
                tt[h] = tt[h] + cur[i];
                continue;
            }
            if (last == 2)
            {
                ++h;
                tt[h] = "";
            }
            last = 1;
            tt[h] = tt[h] + cur[i];
            continue;
        }
        if (h == 1) do_first();
        if (h == 3) do_second(); 
    }
    return 0;
}