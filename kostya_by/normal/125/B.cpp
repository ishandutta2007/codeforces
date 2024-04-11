//
//  main.cpp
//  simple xml
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

vector< string > ss;
string s;
int h = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    for (int i = 0; i < s.size();)
    {
        int pls = 3;
        string cur = "";
        for (int j = 0; j < 3; j++) cur = cur + s[i + j];
        if (s[i + 1] == '/')
        {
            cur = cur + s[i + 3];
            ++pls;
        }
        i += pls;
        ss.pb( cur );
    }
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i].size() == 4) --h;
        for (int j = 0; j < 2 * h; j++) putchar( ' ' );
        cout << ss[i] << endl;
        if (ss[i].size() == 3) ++h;
    }
    return 0;
}