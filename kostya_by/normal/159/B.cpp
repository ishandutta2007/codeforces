//
//  main.cpp
//  taskB
//
//  Created by Sokol Kostya's MacBook on 09.03.11.
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

vector<int> pens[1111];
vector<int> caps[1111];
int color_of_pens[1111], color_of_caps[1111];
int n, m, ans1 = 0, ans2 = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        pens[y].pb( x );
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        caps[y].pb( x );
    }
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j < pens[i].size(); j++) color_of_pens[ pens[i][j] ]++;
        for (int j = 0; j < caps[i].size(); j++) color_of_caps[ caps[i][j] ]++;
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j <= 1000; j++)
        {
            int now = min( color_of_pens[j], color_of_caps[j] );
            ans1 += now;
            ans2 += now;
            color_of_pens[j] -= now;
            color_of_caps[j] -= now;
            sum1 += color_of_pens[j];
            sum2 += color_of_caps[j];
            color_of_pens[j] = color_of_caps[j] = 0;
        }
        ans1 += min(sum1, sum2);
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}