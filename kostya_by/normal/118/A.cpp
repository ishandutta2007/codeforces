//
//  main.cpp
//  Bijection
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

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s, ans;
    cin >> s;
    ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i') continue;
        ans = ans + '.' + s[i];
    }
    cout << ans;
    return 0;
}