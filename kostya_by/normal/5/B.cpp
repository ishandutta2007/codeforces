//
//  main.cpp
//  center_aligment
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

char ss[1111][1111];
int len = 0, n;
bool fl = false;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (int i = 0; gets( ss[i] ) != '\0'; i++)
    {
        n = i + 1;
        len = max( len, int( strlen( ss[i] ) ) );
    }
    for (int i = 0; i < len + 2; i++) putchar('*'); printf("\n");
    for (int i = 0; i < n; i++)
    {
        putchar( '*' );
        int z = len - strlen( ss[i] );
        int a = z / 2;
        int b = z / 2;
        if (z % 2 == 1)
        {
            if (fl == false)
            {
                ++b;
                fl = true;
            } else
            {
                ++a;
                fl = false;
            }
        }
        for (int i = 0; i < a; i++) putchar(' ');
        cout << ss[i];
        for (int i = 0; i < b; i++) putchar(' ');
        printf("*\n");
    }
    for (int i = 0; i < len + 2; i++) putchar('*'); printf("\n");
    return 0;
}