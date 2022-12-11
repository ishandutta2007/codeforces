//
//  main.cpp
//  internet_cf
//
//  Created by Sokol Kostya's MacBook on 19.11.11.
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

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin >> s;
    if ( s[0] == 'h' )
    {
        for ( int i = 0; i < 4; i++ ) cout << s[i];
        s.erase( 0, 4 );
    } else
    {
        for ( int i = 0; i < 3; i++ ) cout << s[i];
        s.erase( 0, 3 );
    }
    cout << "://";
    for ( int i = 1; i < s.size(); i++ )
    {
        if ( s[i] == 'r' && s[i + 1] == 'u' )
        {
            string s1, s2;
            for ( int j = 0; j < i; j++ ) s1 += s[j];
            for ( int j = i + 2; j < s.size(); j++ ) s2 += s[j];
            cout << s1 << ".ru";
            if ( s2.size() != 0 ) cout << "/" << s2;
            return 0;
        }
    }
    return 0;
}