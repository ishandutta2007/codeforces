//
//  main.cpp
//  magical_square
//
//  Created by Sokol Kostya's MacBook on 08.05.11.
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

int a[16], n, nn, s, aa[4][4], rr[4], cc[4], dd[44], need[4], c[4];
bool AnswerIsFound = false, used[16];
vector<int> d;

void rec(int ii, int jj)
{
    if (AnswerIsFound == true) return;
    if (jj == n)
    {
        if (rr[ii] != s) return;
        ++ii;
        jj = 0;
    }
    if (ii == n - 1)
    {
        for (int i = 0; i < n; i++) need[i] = c[i] = s - cc[i];
        if (need[0] + dd[1] != s) return;
        if (need[n - 1] + dd[0] != s) return;
        d.clear();
        sort(c, c + n);
        for (int i = 0; i < nn; i++) if (used[i] == false) d.pb( a[i] );
        sort( d.begin(), d.end() );
        for (int i = 0; i < n; i++) if (c[i] != d[i]) return;
        AnswerIsFound = true;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++) cout << aa[i][j] << " ";
            cout << endl;
        }
        for (int i = 0; i < n; i++) cout << need[i] << " ";
        return;
    }
    for (int i = 0; i < nn; i++)
    {
        if (AnswerIsFound == true) return;
        if (used[i] == true) continue;
        rr[ii] += a[i];
        cc[jj] += a[i];
        if (ii == jj) dd[0] += a[i];
        if (ii + jj == n - 1) dd[1] += a[i];
        aa[ii][jj] = a[i];
        used[i] = true;
        rec(ii, jj + 1);
        used[i] = false;
        rr[ii] -= a[i];
        cc[jj] -= a[i];
        if (ii == jj) dd[0] -= a[i];
        if (ii + jj == n - 1) dd[1] -= a[i];
    }
}

int main (int argc, const char * argv[])
{
    cin >> n;
    nn = n * n;
    for (int i = 0; i < nn; i++) cin >> a[i];
    sort(a, a + nn);
    s = 0;
    for (int i = 0; i < nn; i++) s += a[i];
    s /= n;
    cout << s << endl;
    rec( 0, 0 );
    //cout << AnswerIsFound << endl;
    return 0;
}