//
//  main.cpp
//  knb1
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

string s1, s2, s3;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1 >> s2 >> s3;
    s1 = s1[0];
    s2 = s2[0];
    s3 = s3[0];
    
    if (s1 == s2)
    {
        if (s1 == "p" && s3 == "s")
        {
            cout << "S";
            return 0;
        }
        if (s1 == "s" && s3 == "r")
        {
            cout << "S";
            return 0;
        }
        if (s1 == "r" && s3 == "p")
        {
            cout << "S";
            return 0;
        }
        cout << "?";
        return 0;
    }
    
    if (s2 == s3)
    {
        if (s2 == "p" && s1 == "s")
        {
            cout << "F";
            return 0;
        }
        if (s2 == "s" && s1 == "r")
        {
            cout << "F";
            return 0;
        }
        if (s2 == "r" && s1 == "p")
        {
            cout << "F";
            return 0;
        }
        cout << "?";
        return 0;
    }
    
    if (s1 == s3)
    {
        if (s1 == "p" && s2 == "s")
        {
            cout << "M";
            return 0;
        }
        if (s1 == "s" && s2 == "r")
        {
            cout << "M";
            return 0;
        }
        if (s1 == "r" && s2 == "p")
        {
            cout << "M";
            return 0;
        }
        cout << "?";
        return 0;
    }
    cout << "?";
    return 0;
}