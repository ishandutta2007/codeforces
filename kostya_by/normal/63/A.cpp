//
//  main.cpp
//  disaster
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

string names[111], cc;
vector< pair<int, int> > pp;
int n;

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> names[i] >> cc;
        if (cc == "rat") cur = 0;
        if (cc == "woman") cur = 1;
        if (cc == "child") cur = 1;
        if (cc == "man") cur = 2;
        if (cc == "captain") cur = 3;
        //cout << cur << " " << i << endl;
        pp.pb( mp( cur, i ) );
    }
    sort(pp.begin(), pp.end());
    for (int i = 0; i < n; i++) cout << names[ pp[i].second ] << endl;
    return 0;
}