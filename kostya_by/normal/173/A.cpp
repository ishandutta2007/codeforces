//
//  main.cpp
//  KNB
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
//#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

char aa[1111111], bb[1111111];
int n, m, nn, nm, a, b, pa, pb;

int check(char a, char b)
{
    if (a == 'R' && b == 'S') return 1;
    if (a == 'P' && b == 'R') return 1;
    if (a == 'S' && b == 'P') return 1;
    return 0;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> nn; gets(aa); gets(aa); gets(bb);
    n = strlen( aa );
    m = strlen( bb );
    nm = n * m;
    for (int i = n; i < nm; i++) aa[i] = aa[i - n];
    for (int i = m; i < nm; i++) bb[i] = bb[i - m];
    for (int i = 0; i < nm; i++)
    {
        a += check(bb[i], aa[i]);
        b += check(aa[i], bb[i]);
        if (i < (nn % nm) ) pa = a;
        if (i < (nn % nm) ) pb = b;
    }
    cout << (nn / nm) * a + pa << " " << (nn / nm) * b + pb;
    return 0;
}