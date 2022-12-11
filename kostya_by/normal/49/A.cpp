//
//  main.cpp
//  detective
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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
int last;

bool letter(char c)
{
    if ('a' <= c && c <= 'z') return true;
    if ('A' <= c && c <= 'Z') return true;
    return false;
}

bool check(char c)
{
    if (c == 'a') return true;
    if (c == 'e') return true;
    if (c == 'i') return true;
    if (c == 'o') return true;
    if (c == 'u') return true;
    if (c == 'y') return true;
    
    if (c == 'A') return true;
    if (c == 'E') return true;
    if (c == 'I') return true;
    if (c == 'O') return true;
    if (c == 'U') return true;
    if (c == 'Y') return true;
    
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st );
    for (int i = 0; i < strlen( st ); i++)
    {
        if (letter( st[i] ) == false) continue;
       // cout << st[i];
        if (check( st[i] ) == true) last = 1; else last = 2;
    }
    //cout << endl;
    if (last == 1) cout << "YES"; else cout << "NO";
    return 0;
}