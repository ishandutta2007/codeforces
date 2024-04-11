//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 17.02.11.
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

vector<long long> dd, aa;
long long nn;
int ff[33333];

int fun(int ii);

int fun(int ii)
{
    if (ff[ii] != -1) return ff[ii];
    if (ii == 0)
    {
        ff[ii] = 1;
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < ii; i++)
    {
        if (aa[ii] % aa[i] != 0) continue;
        if (fun(i) == 0)
        {
            ff[ii] = 1;
            if (ii == aa.size() - 1)
            {
                cout << 1 << endl << aa[i];
            }
            return 1;
        }
        cnt++;
    }
    if (cnt == 0)
    {
        ff[ii] = 1;
        if (ii == aa.size() - 1)
        {
            cout << 1 << endl << 0;
        }
        return 1;
    }
    ff[ii] = 0;
    if (ii == aa.size() - 1)
    {
        cout << 2;
    }
    return 0;
};

int main (int argc, const char * argv[])
{
    cin >> nn;
    for (long long i = 2; i * i <= nn; i++)
    {
        if (nn % i != 0) continue;
        dd.pb( i ); dd.pb( nn / i );
    }
    sort(dd.begin(), dd.end());
    if (dd.size() == 0)
    {
        cout << 1 << endl << 0;
        return 0;
    }
    aa.pb( dd[0] );
    for (int i = 1; i < dd.size(); i++) if (dd[i] != dd[i - 1]) aa.pb( dd[i] );
    //for (int i = 0; i < aa.size(); i++) cout << aa[i] << " ";
    for (int i = 0; i < 33333; i++) ff[i] = -1;
    aa.pb( nn );
    fun(aa.size() - 1);
    return 0;
}