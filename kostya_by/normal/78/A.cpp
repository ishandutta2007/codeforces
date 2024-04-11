//
//  main.cpp
//  haiku
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

char st[1111];
int num, n;

bool check(char c)
{
    if (c == 'a') return true;
    if (c == 'e') return true;
    if (c == 'i') return true;
    if (c == 'o') return true;
    if (c == 'u') return true;
    return false;
}


int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st );
    n = strlen( st );
    num = 0;
    for (int i = 0; i < n; i++) num += check( st[i] );
    if (num != 5)
    {
        cout << "NO";
        return 0;
    }
    
    gets( st );
    n = strlen( st );
    num = 0;
    for (int i = 0; i < n; i++) num += check( st[i] );
    if (num != 7)
    {
        cout << "NO";
        return 0;
    }
    
    gets( st );
    n = strlen( st );
    num = 0;
    for (int i = 0; i < n; i++) num += check( st[i] );
    if (num != 5)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}