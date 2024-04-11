//
//  main.cpp
//  fashion numbers
//
//  Created by Sokol Kostya's MacBook on 30.05.11.
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

map<int, int> mmp;
vector<int> v;
int n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i * (i + 1) / 2 <= 1000000000; i++)
    {
        v.pb( i * (i + 1) / 2 );
        mmp[i * (i + 1) / 2] = 1;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (n - v[i] < 0) break;
        if (mmp[ n - v[i] ] == 1)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}