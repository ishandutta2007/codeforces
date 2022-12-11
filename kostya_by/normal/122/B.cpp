//
//  main.cpp
//  lucky_substr
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

map<string, int> mmp;
map<string, int>::iterator it;
string st, cur, res;
int num = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> st;
    for (int i = 0; i < st.size(); i++)
    {
        cur = "";
        for (int j = i; j < st.size(); j++)
        {
            if (st[j] != '4' && st[j] != '7') break;
            cur = cur + st[j];
            mmp[cur]++;
        }
    }
    res = "-1";
    for ( it = mmp.begin(); it != mmp.end(); it++)
    {
        if ((*it).second > num)
        {
            num = (*it).second;
            res = (*it).first;
        }
        if ((*it).second == num)
        {
            if (res > (*it).first) res = (*it).first;
        }
    }
    cout << res;
    return 0;
}