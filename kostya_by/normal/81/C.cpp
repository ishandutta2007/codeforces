//
//  main.cpp
//  average_achivement
//
//  Created by Sokol Kostya's MacBook on 18.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tmark
{
    int id, val;
};

int ans[100000], n, a, b;
Tmark marks[100000];

bool cmp1(Tmark m1, Tmark m2)
{
    if (m1.val > m2.val) return true;
    if (m1.val == m2.val && m1.id < m2.id) return true;
    return false;
}

bool cmp2(Tmark m1, Tmark m2)
{
    if (m1.val > m2.val) return true;
    if (m1.val == m2.val && m1.id > m2.id) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    scanf("%d%d%d",&n,&a,&b);
    if (a == b)
    {
        for (int i = 0; i < a; i++) ans[i] = 1;
        for (int i = 0; i < n; i++) if (ans[i] == 1) printf("1 "); else printf("2 ");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int aa;
        scanf("%d",&aa);
        marks[i].val = aa;
        marks[i].id = i;
    }
    if (a < b)
    {
        sort(marks, marks + n, cmp1);
        for (int i = 0; i < a; i++) ans[marks[i].id] = 1; 
        for (int i = 0; i < n; i++) if (ans[i] == 1) printf("1 "); else printf("2 ");
        return 0;
    }
    sort(marks, marks + n, cmp2);
    for (int i = 0; i < b; i++) ans[marks[i].id] = 1;
    for (int i = 0; i < n; i++) if (ans[i] == 1) printf("2 "); else printf("1 ");
    return 0;
}