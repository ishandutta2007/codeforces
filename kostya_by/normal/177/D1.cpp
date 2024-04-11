//
//  main.cpp
//  task4
//
//  Created by Sokol Kostya's MacBook on 21.04.11.
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

struct Ttree
{
    int l, r, pls;
    Ttree()
    {
        l = 0;
        r = 0;
        pls = 0;
    }
};

int aa[111111], bb[111111], n, m, c;
int pref[111111];
Ttree tree[555555];

void init(int id, int l, int r)
{
    //cout << id << " " << l << " " << r << endl;
    tree[id].l = l;
    tree[id].r = r;
    if (l == r) return;
    int x = (l + r) / 2;
    init(2 * id, l, x);
    init(2 * id + 1, x + 1, r);
}

void plus_int(int id, int l, int r, int val)
{
    int ll = tree[id].l;
    int rr = tree[id].r;
    if (ll == l && rr == r)
    {
        //cout << "!" << id << " " << l << " " << r << " " << val << endl;
        tree[id].pls += val;
        return;
    }
    int xx = (ll + rr) / 2;
    if (l <= xx) plus_int(2 * id, l , min(xx, r), val);
    if (r > xx)  plus_int(2 * id + 1, max(xx + 1, l), r,  val);
}

int get(int id, int ii, int val)
{
    int ll = tree[id].l;
    int rr = tree[id].r;
    if (ll == rr)
    {
        //cout << "! "<< id << " " << ll << " " << tree[id].pls << " " << val << endl;
        return val + tree[id].pls;
    }
    int xx = (ll + rr) / 2;
    if (ii <= xx) return get( 2 * id, ii, val + tree[id].pls );
    if (ii > xx) return get( 2 * id + 1, ii, val + tree[id].pls );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; i++) scanf("%d", &aa[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &bb[i]);
    init(1, 1, n);
    int l = 1;
    int r = n - m + 1;
    for (int i = 1; i <= m; i++)
    {
        //cout << i << " " << l << " " << r << endl;
        plus_int( 1, l, r, bb[i] );
        ++l; ++r;
    }
    //for (int i = 1; i <= n; i++) cout << get(1, i, 0) << " "; cout << endl; 
    for (int i = 1; i <= n; i++) printf("%d ", (aa[i] + get(1, i, 0)) % c);
    return 0;
}