//
//  main.cpp
//  taskE
//
//  Created by Sokol Kostya's MacBook on 09.03.11.
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
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

struct Tcube
{
    long long size;
    int id;
    Tcube(long long a, int b)
    {
        size = a;
        id = b;
    }
};

struct Tcolor
{
    int id, num;
    Tcolor(int a, int b)
    {
        id = a;
        num = b;
    }
};

bool cmp_cube(Tcube c1, Tcube c2);
bool cmp_color(Tcolor c1, Tcolor c2);
void repair_answer(int a, int b);

bool cmp_cube(Tcube c1, Tcube c2)
{
    if (c1.size > c2.size) return true; return false;
};

bool cmp_color(Tcolor c1, Tcolor c2)
{
    if (c1.num > c2.num) return true; return false;
}

pair<long long, int> best_sum[111111];
long long cur_sum[111111];
map<int, int> compress;
vector< Tcube > cubes[111111];
vector< Tcolor > colors;
int n, c, s, h = 0, color_a, color_b;
long long ans = -1;

void repair_answer(int a, int b)
{
    int ii = 0;
    while (ii != cubes[b].size()) 
    {
        printf("%d %d ", cubes[a][ii].id, cubes[b][ii].id);
        ++ii;
    }
    if (cubes[a].size() != cubes[b].size()) printf("%d", cubes[a][ii].id);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int color, height;
        scanf("%d%d", &color, &height);
        if (compress[color] == 0)
        {
            ++h;
            compress[color] = h;
        }
        color = compress[color];
        cubes[color].pb( Tcube(height, i + 1) );
    }
    for (int i = 1; cubes[i].size() != 0; i++)
    {
        colors.pb( Tcolor( i, int( cubes[i].size() ) ) );
        sort( cubes[i].begin(), cubes[i].end(), cmp_cube );
    }
    sort( colors.begin(), colors.end(), cmp_color );
    for (int i = 0; i < 111111; i++) best_sum[i] = mp( -1, -1 );
    for (int i = 0; i < colors.size(); i++)
    {
        int id = colors[i].id;
        long long now = 0;
        for (int j = 0; j < cubes[id].size(); j++)
        {
            now += cubes[id][j].size;
            cur_sum[j + 1] = now;
        }
        for (int plus = 0; plus < 2; plus++)
        {
            if (best_sum[cubes[id].size() + plus].first == -1) continue;
            long long ans_cur = now + best_sum[cubes[id].size() + plus].first;
            if (ans_cur > ans)
            {
                ans = ans_cur;
                color_a = best_sum[cubes[id].size() + plus].second;
                color_b = id;
            }
        }
        for (int j = 1; j <= cubes[id].size(); j++)
        {
            if (best_sum[j].first == -1)
            {
                best_sum[j].first = cur_sum[j];
                best_sum[j].second = id;
            }
            if (best_sum[j].first < cur_sum[j])
            {
                best_sum[j].first = cur_sum[j];
                best_sum[j].second = id;
            }
        }
    }
    //cout << color_a << " " << color_b << endl;
    int ans_num = 2 * int(cubes[color_b].size());
    if (cubes[color_a].size() != cubes[color_b].size()) ++ans_num;
    cout << ans << endl << ans_num << endl;
    repair_answer(color_a, color_b);
    return 0;
}