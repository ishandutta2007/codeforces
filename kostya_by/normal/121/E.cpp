//
//  main.cpp
//  lucky_array
//
//  Created by Sokol Kostya's MacBook on 03.05.11.
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
//#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const int block = 1600;

using namespace std;

struct Tsegment
{
    int ll, rr, pls, res;
    int mp[10005];
};

vector<int> lucky;
char empt[111];
Tsegment seg[444];
int n, m, ll, rr, a[555555], num[555555], dd, cur;
bool begin[555555], lll[11111];

void gen(int pos)
{
    if (pos <= 4)
    {
        if (cur != 0) lucky.pb( cur );
    }
    if (pos < 4)
    {
        cur *= 10;
        cur += 4;
        gen(pos + 1);
        cur /= 10;
        cur *= 10;
        cur += 7;
        gen(pos + 1);
        cur /= 10;
    }
}

void pls(int ll, int rr, int dd)
{
    int ii, aa;
    for (int i = ll; i <= rr;)
    {
        if (begin[i] == true && i + block - 1 <= rr)
        {
            seg[ num[i] ].pls += dd;
            i += block;
            continue;
        }
        ii = num[i];
        aa = a[i];
        seg[ii].mp[ aa ]--;
        aa += dd;
        seg[ii].mp[ aa ]++;
        a[i] = aa;
        ++i;
    }    
}

int cnt(int ll, int rr)
{
    int res = 0, xx;
    for (int i = ll; i <= rr;)
    {
        if (begin[i] == true && i + block - 1 <= rr)
        {
            for (int j = 0; j < lucky.size(); j++)
            {
                xx = lucky[j];
                xx -= seg[ num[i] ].pls;
                if (xx < 0) continue;
                res += seg[ num[i] ].mp[ xx ];
            }
            i += block;
            continue;
        }
        xx = a[i] + seg[ num[i] ].pls;
        if (lll[ xx ] == true) ++res;
        ++i;
    }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cur = 0;
    gen(0);
    for (int i = 0; i < lucky.size(); i++) lll[ lucky[i] ] = true;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 100; i++)
    {
        seg[i].ll = 1 + block * i;
        seg[i].rr = block * (i + 1);
        for (int j = seg[i].ll; j <= seg[i].rr; j++) num[j] = i;
        begin[ seg[i].ll ] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        seg[ num[i] ].mp[ a[i] ]++;
    }
    gets( empt );
    char c;
    for (int i = 1; i <= m; i++)
    {
        c = getchar();
        if (c == 'a')
        {
            c = getchar(); c = getchar();
            scanf("%d%d%d", &ll, &rr, &dd); gets( empt );
            pls(ll, rr, dd);
        }
        if (c == 'c')
        {
            c = getchar(); c = getchar(); c = getchar(); c = getchar();
            scanf("%d%d", &ll, &rr); gets( empt );
            int res = cnt( ll, rr );
            printf("%d\n", res);
        }
    }
    return 0;
}