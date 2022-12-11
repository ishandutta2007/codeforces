//
//  main.cpp
//  cf95task5
//
//  Created by Sokol Kostya's MacBook on 25.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct tfr
{
    int x, y, id;
};

int n, m;

int ans[200000];
tfr fr[200000];
int num[10];

bool cmp1(tfr f1, tfr f2)
{
    if (f1.x < f2.x) return true;
    if ((f1.x == f2.x) && (f1.y < f2.y)) return true;
    return false;
}

bool cmp2(tfr f1, tfr f2)
{
    if (f1.y < f2.y) return true;
    if ((f1.y == f2.y) && (f1.x < f2.x)) return true;
    return false;
}

bool cmp3(tfr f1, tfr f2)
{
    if (f1.x + f1.y < f2.x + f2.y) return true;
    if ((f1.x + f1.y == f2.x + f2.y) && (f1.x < f2.x)) return true;
    return false;
}

bool cmp4(tfr f1, tfr f2)
{
    if (f1.x - f1.y < f2.x - f2.y) return true;
    if ((f1.x - f1.y == f2.x - f2.y) && (f1.x < f2.x)) return true;
    return false;
}

int h, t;

int main (int argc, const char * argv[])
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        fr[i].id = i;
        scanf("%d%d", &fr[i].x, &fr[i].y);
    }
    fr[m].x = 100000000;
    fr[m].y = -1000000;
    
    
    sort(fr, fr + m, cmp1);
    h = 0;
    t = 0;
    while (t != m)
    {
        while (fr[h].x == fr[t].x) ++t;
        --t;
        if (h < t)
            for (int i = h; i <= t; i++)
            {
                if ((i == h) || (i == t)) ++ans[fr[i].id]; else ans[fr[i].id] += 2;
            }
        h = t + 1;
        ++t;
    }
    
    
    
    
    sort(fr, fr + m, cmp2);
    h = 0;
    t = 0;
    while (t != m)
    {
        while (fr[h].y == fr[t].y) ++t;
        --t;
        if (h < t)
            for (int i = h; i <= t; i++)
            {
                if ((i == h) || (i == t)) ++ans[fr[i].id]; else ans[fr[i].id] += 2;
            }
        h = t + 1;
        ++t;
    }
    
    
    
//for (int i = 0; i < m; i++) cout << fr[i].x + fr[i].y << " ";
    sort(fr, fr + m, cmp3);
    h = 0;
    t = 0;
    //for (int i = 0; i < m; i++) cout << fr[i].x + fr[i].y << " ";
    while (t != m)
    {
        while (fr[h].x + fr[h].y == fr[t].x + fr[t].y) ++t;
        --t;
        if (h < t)
            for (int i = h; i <= t; i++)
            {
                if ((i == h) || (i == t)) ++ans[fr[i].id]; 
                else ans[fr[i].id] += 2;
            }
        h = t + 1;
        ++t;
    }
    
    
    
    
    sort(fr, fr + m, cmp4);
    h = 0;
    t = 0;
    while (t != m)
    {
        while (fr[h].x - fr[h].y == fr[t].x - fr[t].y) ++t;
        --t;
        if (h < t)
            for (int i = h; i <= t; i++)
            {
                if ((i == h) || (i == t)) ++ans[fr[i].id]; else ans[fr[i].id] += 2;
            }
        h = t + 1;
        ++t;
    }
    
    for (int i = 0; i < m; i++) ++num[ans[i]];
    for (int i = 0; i <= 8; i++) cout << num[i] << " ";
    return 0;
}