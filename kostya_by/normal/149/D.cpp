//
//  main.cpp
//  cf106task4
//
//  Created by Sokol Kostya's MacBook on 10.02.11.
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
const int mod = 1000000007;

using namespace std;

int ff[777][777][5], start[777], finish[777];
vector<int> five;

string ss;

int fun(int ll, int rr, int kk);

int fun(int ll, int rr, int kk)
{
    if (ff[ll][rr][kk] != -1) return ff[ll][rr][kk];
    if (ll + 1 == rr)
    {
        ff[ll][rr][kk] = 1;
        return 1;
    }
    vector< pair<int, int> > vv;
    int ii = ll + 1;
    while (ii < rr)
    {
        int jj = start[ii];
        vv.push_back( mp(ii, jj) );
        ii = jj + 1;
    }
  //  for (int i = 0; i < vv.size(); i++) cout << vv[i].first << "-" << vv[i].second << ", "; cout << endl;
    vector< vector<int> > gg;
    for (int i = 0; i < vv.size(); i++) gg.pb( five );
    if (kk == 0 || kk == 2 || kk == 4)
    {
        //gg[0][0] = fun( vv[0].first, vv[0].second, 0);
        gg[0][1] = fun( vv[0].first, vv[0].second, 1);
        gg[0][2] = fun( vv[0].first, vv[0].second, 2);
        gg[0][3] = fun( vv[0].first, vv[0].second, 3);
        gg[0][4] = fun( vv[0].first, vv[0].second, 4);
    }
    if (kk == 1)
    {
       // gg[0][0] = fun( vv[0].first, vv[0].second, 0);
        gg[0][2] = fun( vv[0].first, vv[0].second, 2);
        gg[0][3] = fun( vv[0].first, vv[0].second, 3);
        gg[0][4] = fun( vv[0].first, vv[0].second, 4);
    }
    if (kk == 3)
    {
       // gg[0][0] = fun( vv[0].first, vv[0].second, 0);
        gg[0][1] = fun( vv[0].first, vv[0].second, 1);
        gg[0][2] = fun( vv[0].first, vv[0].second, 2);
        gg[0][4] = fun( vv[0].first, vv[0].second, 4);
    }
    for (int i = 1; i < vv.size(); i++)
        for (int j = 1; j < 5; j++)
        {
            long long res = 0, val = fun( vv[i].first, vv[i].second, j );
            if (j == 0)
            {
                //res += gg[i - 1][0];
                res += gg[i - 1][1];
                res += gg[i - 1][2];
                res += gg[i - 1][3];
                res += gg[i - 1][4];
            }
            if (j == 1)
            {
               // res += gg[i - 1][0];
                res += gg[i - 1][1];
                res += gg[i - 1][3];
                res += gg[i - 1][4];
            }
            if (j == 2)
            {
               // res += gg[i - 1][0];
                res += gg[i - 1][1];
                res += gg[i - 1][2];
                res += gg[i - 1][3];
                res += gg[i - 1][4];
            }
            if (j == 3)
            {
               // res += gg[i - 1][0];
                res += gg[i - 1][1];
                res += gg[i - 1][2];
                res += gg[i - 1][3];
            }
            if (j == 4)
            {
               // res += gg[i - 1][0];
                res += gg[i - 1][1];
                res += gg[i - 1][2];
                res += gg[i - 1][3];
                res += gg[i - 1][4];
            }
            res *= val;
            res %= mod;
            gg[i][j] = int(res);
        }
    long long res = 0;
    if (kk == 0 || kk == 1 || kk == 3)
    {
       // res += gg[vv.size() - 1][0];
        res += gg[vv.size() - 1][1];
        res += gg[vv.size() - 1][2];
        res += gg[vv.size() - 1][3];
        res += gg[vv.size() - 1][4];
    }
    if (kk == 2)
    {
       // res += gg[vv.size() - 1][0];
        res += gg[vv.size() - 1][1];
        res += gg[vv.size() - 1][3];
        res += gg[vv.size() - 1][4];
    }
    if (kk == 4)
    {
      //  res += gg[vv.size() - 1][0];
        res += gg[vv.size() - 1][1];
        res += gg[vv.size() - 1][2];
        res += gg[vv.size() - 1][3];
    }
    //cout << ll << " " << rr << " " << " " << kk << " " << res << endl;
    res %= mod;
    ff[ll][rr][kk] = int(res);
    return int(res);
}

stack<int> st;

int main (int argc, const char * argv[])
{
    cin >> ss;
    ss = '(' + ss + ')';
    for (int i = 0; i < 777; i++)
        for (int j = 0; j < 777; j++)
            for (int k = 0; k < 5; k++)
                ff[i][j][k] = -1;
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '(') st.push(i);
        if (ss[i] == ')')
        {
            int ii = st.top(); st.pop();
            start[ii] = i;
            finish[i] = ii;
        }
    }
    five.pb(0); five.pb(0); five.pb(0); five.pb(0); five.pb(0);
    cout << fun(0, int(ss.size() - 1), 0);
    return 0;
}