//
//  main.cpp
//  min_sum
//
//  Created by Sokol Kostya's MacBook on 20.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tpoint
{
    int x, y, xx, yy, type, id;
};

const int it = 1000;

bool cmp(Tpoint p1, Tpoint p2);
int sqr(int a);

bool cmp(Tpoint p1, Tpoint p2)
{
    if (p1.xx + p1.yy < p2.xx + p2.yy) return true;
    return false;
};

int sqr(int a)
{
    return a * a;
}

Tpoint points[100000];

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d",&a,&b);
        //cout << a << " " << b << endl;
        points[i].id = i;
        points[i].x = a;
        points[i].y = b;
        points[i].xx = a * a;
        points[i].yy = b * b;
        if (a >= 0 && b >= 0) c = 1;
        if (a >= 0 && b <= 0) c = 2;
        if (a <= 0 && b >= 0) c = 3;
        if (a <= 0 && b <= 0) c = 4;
        points[i].type = c;
    }
    int ans = 1000000000, ii, jj;
    sort(points, points + n, cmp);
    for (int i = 0; i < n; i++)
    {
        int left = i - it;
        left = max(0, left);
        for (int j = left; j < i; j++)
        {
            int dx = fabs(points[i].x) - fabs(points[j].x);
            int dy = fabs(points[i].y) - fabs(points[j].y);
            int now = dx * dx + dy * dy;
            //cout << points[i].id + 1 << " " << points[j].id + 1 << " " << now << endl;
            if (now < ans)
            {
                ans = now;
                ii = i;
                jj = j;
            }
        }
    }
    int t1 = 0, t2 = 0;
    if (points[ii].type == 1) t1 = 4;
    if (points[ii].type == 2) t1 = 2;
    if (points[ii].type == 3) t1 = 3;
    if (points[ii].type == 4) t1 = 1;
    
    if (points[jj].type == 1) t2 = 1;
    if (points[jj].type == 2) t2 = 3;
    if (points[jj].type == 3) t2 = 2;
    if (points[jj].type == 4) t2 = 4;
    //cout << ans << endl;
    cout << points[ii].id + 1 << " " << t1 << " " << points[jj].id + 1 << " " << t2;
    return 0;
}