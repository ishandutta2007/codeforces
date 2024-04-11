//
//  main.cpp
//  epic game
//
//  Created by Sokol Kostya's MacBook on 15.01.11.
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

int nod(int a, int b)
{
    if (a != 0) return nod(b % a, a); else return b;
}

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    if (s1 == s2) cout << 0;
    if (s1 < s2)  cout << -1;
    if (s1 > s2)  cout << 1;
    return 0;
}