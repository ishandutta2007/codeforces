//
//  main.cpp
//  another string task
//
//  Created by Sokol Kostya's MacBook on 09.05.11.
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

int n, k;
long long ans = 0;
vector<int> pos;
char st[1111111];

long long fun(int l, int r)
{
    long long l1, r1 = pos[l], l2 = pos[r], r2;
    if (l == 0) l1 = 1; else l1 = pos[l - 1] + 1;
    if (r == pos.size() - 1) r2 = n; else r2 = pos[r + 1] - 1;
    return (r1 - l1 + 1) * (r2 - l2 + 1);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> k; gets( st ); gets( st );
    n = int(strlen( st ));
    for (int i = 1; i <= n; i++) if (st[i - 1] == '1') pos.pb( i );
    if (k > pos.size())
    {
        cout << 0;
        return 0;
    }
    if (k == 0)
    {
        long long cur;
        if (pos.size() == 0)
        {
            cur = n;
            cur *= cur - 1;
            cur /= 2;
            cur += 1ll * n;
            cout << cur;
            return 0;
        }
        cur = pos[0] - 1;
        cur *= cur - 1;
        cur /= 2;
        ans += cur;
        cur = n - pos.back();
        cur *= cur - 1;
        cur /= 2;
        ans += cur;
        for (int i = 1; i < pos.size(); i++)
        {
            cur = pos[i] - 1 - pos[i - 1];
            cur *= cur - 1;
            cur /= 2;
            ans += cur;
        }
        for (int i = 0; i < n; i++) if (st[i] == '0') ++ans;
        cout << ans;
        return 0;
    }
    for (int i = 0; i < pos.size(); i++)
    {
        int j = i + k - 1;
        if (j >= pos.size()) break;
        ans += fun(i, j);
    }
    cout << ans;
    return 0;
}