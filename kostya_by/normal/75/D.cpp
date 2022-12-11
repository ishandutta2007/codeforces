//
//  main.cpp
//  maxsum
//
//  Created by Sokol Kostya's MacBook on 03.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, ll[50];
long long a[50][5000], suff[50][5000], pref[50][5000], sum[50], ss[50], pp[50], aa[50];

int main (int argc, const char * argv[])
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ll[i]);
        for (int j = 0; j < ll[i]; j++) cin >> a[i][j];
        sum[i] = 0;
        for (int j = 0; j < ll[i]; j++) sum[i] += a[i][j];
        pref[i][0] = a[i][0];
        for (int j = 1; j < ll[i]; j++) pref[i][j] = pref[i][j - 1] + a[i][j];
        suff[i][ll[i] - 1] = a[i][ll[i] - 1];
        for (int j = ll[i] - 2; j >= 0; j--) suff[i][j] = suff[i][j + 1] + a[i][j];
        pp[i] = pref[i][0];
        for (int j = 1; j < ll[i]; j++) pp[i] = max(pp[i], pref[i][j]);
        ss[i] = suff[i][ll[i] - 1];
        for (int j = ll[i] - 2; j >= 0; j--) ss[i] = max(ss[i], suff[i][j]);
        long long now = 0, nl = 0;
        aa[i] = -1000000000;
        for (int j = 0; j < ll[i]; j++)
        {
            now += a[i][j];
            aa[i] = max(aa[i], now);
            now = max(nl, now);
        }
       // cout << sum[i] << " " << ss[i] << " " << pp[i] << " " << aa[i] << endl; 
    }
    long long ans = -1000000000, now = 0, nl = 0;
   // cout << aa[0] << endl;
    for (int i = 0; i < m; i++)
    {
        int ii;
        scanf("%d", &ii);
        --ii;
        ans = max(ans, aa[ii]);
        long long now1, now2;
        now1 = now + sum[ii];
        ans = max(ans, now + pp[ii]);
        now2 = ss[ii];
        now = max(now1, now2);
        ans = max(ans, now);
        now = max(nl, now);
    }
    cout << ans;
    return 0;
}