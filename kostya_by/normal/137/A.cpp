//
//  main.cpp
//  cards and photoes
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

string st;
char cur;
int tmp = 0, ans = 0;

int main (int argc, const char * argv[])
{
    cin >> st;
    for (int i = 0; i < st.size(); i++)
    {
        if (tmp == 0)
        {
            cur = st[i];
            tmp = 1;
            continue;
        }
        if (st[i] == cur)
        {
            ++tmp;
            if (tmp == 5)
            {
                ++ans;
                tmp = 0;
            }
            continue;
        }
        ++ans;
        cur = st[i];
        tmp = 1;
    }
    if (tmp != 0) ++ans;
    cout << ans;
    return 0;
}