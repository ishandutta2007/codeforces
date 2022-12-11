//
//  main.cpp
//  taskA
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

struct triple
{
    int first, second, third;
    triple()
    {
        first = 0;
        second = 0;
        third = 0;
    }
    triple(int a, int b, int c)
    {
        first = a;
        second = b;
        third = c;
    }
};

map<string, int> compress;
vector<triple> query;
int n, d, h = 0, tt, a, b;
string names[2222], s1, s2;
vector< pair<int, int> > ans;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> tt;
        if (compress[s1] == 0)
        {
            ++h;
            compress[s1] = h;
            names[h] = s1;
        }
        if (compress[s2] == 0)
        {
            ++h;
            compress[s2] = h;
            names[h] = s2;
        }
        a = compress[s1];
        b = compress[s2];
        query.pb( triple( a, b, tt ) );
    }
    for (int i = 0; i < query.size(); i++)
    {
        for (int j = 0; j < query.size(); j++)
        {
            if (i == j) continue;
            if (query[i].third >= query[j].third) continue;
            if (query[i].first != query[j].second || query[i].second != query[j].first) continue;
            int a = query[i].first;
            int b = query[j].first;
            if (query[j].third - query[i].third <= d) ans.pb( mp( min(a, b), max(a, b) ));
        }
    }
    if (ans.size() == 0)
    {
        cout << 0;
        return 0;
    }
    sort(ans.begin(), ans.end());
    int ans_num = 1;
    for (int i = 1; i < ans.size(); i++) if (ans[i] != ans[i - 1]) ++ans_num;
    cout << ans_num << endl;
    cout << names[ans[0].first] << " " << names[ans[0].second] << endl;
    for (int i = 1; i < ans.size(); i++) if (ans[i] != ans[i - 1]) cout << names[ans[i].first] << " " << names[ans[i].second] << endl;
    return 0;
}