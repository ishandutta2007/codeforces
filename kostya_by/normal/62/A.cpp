//
//  main.cpp
//  student_dream
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

string ans = "NO";

bool check(int girl, int boy)
{
    if (girl > boy + 1) return false;
    if (2 * (girl + 1) < boy) return false;
    return true;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (check(a, d) || check(b, c)) ans = "YES";
    cout << ans;
    return 0;
}