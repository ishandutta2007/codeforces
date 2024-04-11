//
//  main.cpp
//  hardwork
//
//  Created by Sokol Kostya's MacBook on 13.05.11.
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

string s1, s2, s3, s123, s132, s213, s231, s312, s321, res, cc;

void scan()
{
    res = "";
    cin >> cc;
    int n = cc.size();
    for (int i = 0; i < n; i++)
    {
        if (cc[i] == '-' || cc[i] == '_' || cc[i] == ';') continue;
        cc[i] = tolower( cc[i] );
        res = res + cc[i];
    }
    
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scan();
    s1 = res;
    scan();
    s2 = res;
    scan();
    s3 = res;
    s123 = s1 + s2 + s3;
    s132 = s1 + s3 + s2;
    s213 = s2 + s1 + s3;
    s231 = s2 + s3 + s1;
    s312 = s3 + s1 + s2;
    s321 = s3 + s2 + s1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scan();
        bool fl = false;
        fl |= res == s123;
        fl |= res == s132;
        fl |= res == s213;
        fl |= res == s231;
        fl |= res == s312;
        fl |= res == s321;
        if (fl == true) printf("ACC\n"); else printf("WA\n");
    }
    return 0;
}