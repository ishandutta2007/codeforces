//
//  main.cpp
//  word
//
//  Created by Sokol Kostya's MacBook on 28.04.11.
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

bool small(char c)
{
    if ('a' <= c && c <= 'z') return true;
    return false;
}

bool big(char c)
{
    if ('A' <= c && c <= 'Z') return true;
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int val1 = 0, val2 = 0;
    string st;
    cin >> st;
    for (int i = 0; i < st.size(); i++)
    {
        if (small( st[i] ) == true) ++val1; else ++val2; 
    }
    if (val1 >= val2) 
        for (int i = 0; i < st.size(); i++) st[i] = tolower( st[i] ); else
            for (int i = 0; i < st.size(); i++) st[i] = toupper( st[i] );
    cout << st;
    return 0;
}