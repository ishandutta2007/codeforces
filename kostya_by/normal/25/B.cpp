//
//  main.cpp
//  phone numbers
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

int n, from[111];
string ss;
bool ff[111];
vector< pair<int, int> > ans;

void fun(int ll, int rr)
{
    ll--; rr--;
    for (int i = ll; i <= rr; i++) cout << ss[i];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ff[0] = true;
    cin >> n >> ss;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= 3; j++)
        {
            if (i - j < 0) continue;
            if (ff[i - j] == true)
            {
                ff[i] = true;
                from[i] = i - j;
            }
        }
    }
    int nn = n;
    while (nn != 0)
    {
        ans.pb( mp( from[nn] + 1, nn ) );
        nn = from[nn];
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        fun( ans[i].first, ans[i].second );
        if (i != 0) cout << '-';
    }
    return 0;
}