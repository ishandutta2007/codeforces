//
//  main.cpp
//  deikstra
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

set< pair<long long, int> > st;
set< pair<long long, int> >::iterator it;
long long val[111111];
vector< pair<int, long long> > graf[111111];
pair<int, long long> now;
pair<long long, int> nn, mm;
int n, m, from[111111];
vector<int> ans;

int main (int argc, const char * argv[])
{   
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        now.first = a - 1;
        now.second = c;
        graf[b - 1].push_back(now);
        now.first = b - 1;
        graf[a - 1].push_back(now);
    }
    for (int i = 0; i < n; i++)
    {
        val[i] = inf;
        if (i == 0) val[i] = 0;
        nn.first = val[i];
        nn.second = i;
        st.insert(nn);
    }
    while (st.size() != 0)
    {
        nn = (*st.begin());
        st.erase(st.begin());
        int v = nn.second;
        for (int i = 0; i < graf[v].size(); i++)
        {
            int next = graf[v][i].first;
            long long res = graf[v][i].second + val[v];
            if (res < val[next])
            {
                nn.first = val[next];
                nn.second = next;
                it = st.find(nn);
                st.erase(it);
                val[next] = res;
                nn.first = val[next];
                st.insert(nn);
                from[next] = v;
            }
        }
    }
    if (val[n - 1] == inf)
    {
        cout << -1;
        return 0;
    }
    int vv = n - 1;
    while (vv != 0)
    {
        ans.push_back(vv);
        vv = from[vv];
    }
    ans.push_back(0);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}