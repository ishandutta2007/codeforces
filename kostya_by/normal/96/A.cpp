//
//  main.cpp
//  epic game
//
//  Created by Sokol Kostya's MacBook on 15.01.11.
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

int nod(int a, int b)
{
    if (a != 0) return nod(b % a, a); else return b;
}

int main (int argc, const char * argv[])
{
    string s1;
    cin >> s1;
    for (int i = 0; i < (int(s1.size()) - 7 + 1); i++)
    {   
        //cout << i << endl;
        if (s1[i] == s1[i + 1] && s1[i + 1] == s1[i + 2] && s1[i + 2] == s1[i + 3] && s1[i + 3] == s1[i + 4] && s1[i + 4] == s1[i + 5] && s1[i + 5] == s1[i + 6]) 
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}