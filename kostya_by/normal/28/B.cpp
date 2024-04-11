//
//  main.cpp
//  pSort
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

int a[111], b[111], n;
bool used[111];

vector<int> graf[111];

void dfs(int v);

void dfs(int v)
{
    if (used[v] == true) return;
    used[v] = true;
    for (int i = 0; i < graf[v].size(); i++)
    {
        //cout << graf[v][i] << endl;
        dfs(graf[v][i]);
    }
}

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (fabs(i - j) == b[i] || fabs(i - j) == b[j]) 
            {
                //cout << i << " " << j << endl; 
                graf[i].push_back(j);
                graf[j].push_back(i);
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 111; j++) used[j] = false;
        dfs(i);
        for (int j = 1; j <= n; j++)
        {
            //cout << used[j] << " ";
            if (a[j] == i)
            {
                //cout << j << endl;
                if (used[j] == false)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
       // cout << endl;
    }
    cout << "YES";
    return 0;
}