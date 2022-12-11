//
//  main.cpp
//  chess
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

string p1, p2;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a1, b1, a2, b2, ans = 0;
    cin >> p1 >> p2;
    a1 = p1[0] - 'a';
    b1 = p1[1] - '1';
    a2 = p2[0] - 'a';
    b2 = p2[1] - '1';
    //cout << a1 << " " << b1 << endl << a2 << " " << b2 << endl;  
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (i == a1 || j == b1) continue;
            int dx = i - a2, dy = j - b2;
            if (dx < 0) dx = -dx; 
            if (dy < 0) dy = -dy;
            int mn = min(dx, dy);
            int mx = max(dx, dy);
            if (mn == 1 && mx == 2) continue;
            dx = i - a1, dy = j - b1;
            if (dx < 0) dx = -dx; 
            if (dy < 0) dy = -dy;
            mn = min(dx, dy);
            mx = max(dx, dy);
            if (mn == 1 && mx == 2) continue;
            if (i == a1 && j == b1) continue;
            if (i == a2 && j == b2) continue;
            //cout << i << " " << j << endl;
            ++ans;
        }
    cout << ans;
    return 0;
}