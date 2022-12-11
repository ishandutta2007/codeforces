//
//  main.cpp
//  sum_of_median
//
//  Created by Sokol Kostya's MacBook on 08.02.11.
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
//#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

struct Tevent
{
    int type, x;
    void print()
    {
        cout << type << " ";
        if (type != 3) cout << x;
        cout << endl;
    };
};

Tevent event[111111];
int n;
long long sqrtd[222][5], a[111111], num[222];
char s[3];
string ss = "   ";
map<int, int> mp;
set<int> st;
set<int>::iterator ii;

void modify1(int x)
{
    int nn = 0;
    for (int i = 1; i <= 200; i++)
    {
        int left = 500 * (i - 1) + 1, right = 500 * i;
        if (right < x) 
        {
            nn += num[i];
            continue;
        }
        if (left > x)
        {
            long long ss[5];
            for (int j = 0; j < 5; j++) ss[j] = sqrtd[i][(j - 1 + 5) % 5];
            for (int j = 0; j < 5; j++) sqrtd[i][j] = ss[j];
            continue;
        }
        num[i]++;
        for (int j = 0; j < 5; j++) sqrtd[i][j] = 0;
        for (int j = left; j <= right; j++)
        {
            if (a[j] == 0) continue;
            ++nn;
            sqrtd[i][nn % 5] += a[j];
        }
    }
}

void modify2(int x)
{
    int nn = 0;
    for (int i = 1; i <= 200; i++)
    {
        int left = 500 * (i - 1) + 1, right = 500 * i;
        if (right < x) 
        {
            nn += num[i];
            continue;
        }
        if (left > x)
        {
            long long ss[5];
            for (int j = 0; j < 5; j++) ss[j] = sqrtd[i][(j + 1 + 5) % 5];
            for (int j = 0; j < 5; j++) sqrtd[i][j] = ss[j];
            continue;
        }
        num[i]--;
        for (int j = 0; j < 5; j++) sqrtd[i][j] = 0;
        for (int j = left; j <= right; j++)
        {
            if (a[j] == 0) continue;
            ++nn;
            sqrtd[i][nn % 5] += a[j];
        }
    }
}

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        ss[0] = s[0]; ss[1] = s[1]; ss[2] = s[2]; 
        if (ss == "add")
        {
            event[i].type = 1;
            int x;
            scanf("%d", &x);
            event[i].x = x;
            st.insert( x );
        }
        if (ss == "del")
        {
            event[i].type = 2;
            int x;
            scanf("%d", &x);
            event[i].x = x;
        }
        if (ss == "sum")
        {
            event[i].type = 3;
        }
        //event[i].print();
    }
    ii = st.begin();
    int i = 1;
    while (ii != st.end())
    {
        int val = (*ii);
        mp[val] = i++;
        ii++;
    }
    for (int i = 0; i < n; i++)
    {
        if (event[i].type == 1)
        {
            int x = mp[ event[i].x ];
            a[x] = event[i].x;
            modify1( x );
        }
        if (event[i].type == 2)
        {
            int x = mp[ event[i].x ];
            a[x] = 0;
            modify2( x );
        }
        if (event[i].type == 3)
        {
            long long res = 0;
            for (int j = 1; j <= 200; j++) res += sqrtd[j][3];
            #ifdef WIN32
                printf("%I64d\n",res);
            #else
               // printf("%lld\n",res);
            #endif
        }
    }
    return 0;
}