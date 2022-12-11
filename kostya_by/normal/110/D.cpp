//
//  main.cpp
//  Lucky Probability
//
//  Created by Sokol Kostya's MacBook on 21.01.11.
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

vector<int> lucky;
int now = 0;

void rec(int a)
{
    if (a <= 9)
    {
        lucky.push_back(now);
    }
    if (a < 9)
    {
        now *= 10;
        now += 4;
        rec(a + 1);
        now += 3;
        rec(a + 1);
        now /= 10;
    }
}

long long ll1, ll2, rr1, rr2, l1, r1, l2, r2, a1, b1, a2, b2, c1, d1, c2, d2, f1, e1, f2, e2;
int k;

int main (int argc, const char * argv[])
{
    cin >> ll1 >> rr1 >> ll2 >> rr2 >> k;
    rec(0);
    sort(lucky.begin(), lucky.end());
    for (int i = 0; i < lucky.size(); i++)
    {
        //cout << lucky[i] << endl;
    }
    long long zn = (rr1 - ll1 + 1) * (rr2 - ll2 + 1);
    long long ch = 0;
    lucky.push_back(1111111111);
    for (int i = 1; i < lucky.size() - 1; i++)
    {
        if (i < k) continue;
        int j = i - k;
        l1 = lucky[j] + 1;
        r1 = lucky[j + 1];
        l2 = lucky[i];
        r2 = lucky[i + 1] - 1;
        a1 = max(ll1, l1);
        b1 = min(rr1, r1);
        a2 = max(ll2, l2);
        b2 = min(rr2, r2);
        if (a1 <= b1 && a2 <= b2) ch += (b1 - a1 + 1) * (b2 - a2 + 1);
        
        //if (ll1 == ll2 && rr1 == rr2) continue;
        c1 = max(ll2, l1);
        d1 = min(rr2, r1);
        c2 = max(ll1, l2);
        d2 = min(rr1, r2);
        if (c1 <= d1 && c2 <= d2) ch += (d1 - c1 + 1) * (d2 - c2 + 1);
        
        f1 = max(a1, c2);
        e1 = min(b1, d2);
        f2 = max(a2, c1);
        e2 = min(b2, d1);
        if (f1 <= e1 && f2 <= e2) ch -= (e1 - f1 + 1) * (e2 - f2 + 1);
    }
    cout << fixed << setprecision(10) << 1.0 * ch / zn;
    return 0;
}