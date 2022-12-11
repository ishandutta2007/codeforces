//
//  main.cpp
//  subsegments
//
//  Created by Sokol Kostya's MacBook on 08.02.11.
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
//#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

set<int, greater<int> > st;
map<int, int> mp;

int n, k, a[111111], ll, rr;

void push(int xx)
{
    mp[xx]++;
    if (mp[xx] == 1)
    {
        st.insert(xx);
    }
    if (mp[xx] == 2)
    {
        st.erase( st.find(xx) );
    }
}

void pop(int xx)
{
    mp[xx]--;
    if (mp[xx] == 1)
    {
        st.insert(xx);
    }
    if (mp[xx] == 0)
    {
        st.erase( st.find(xx) );
    }
}


int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n >> k;
    ll = 1; rr = k;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        if (i <= k) push(a[i]);
    }
    while (rr < n)
    {
        if (st.size() == 0) printf("Nothing\n"); else printf("%d\n", (*st.begin()));
        pop(a[ll]); ++ll;
        ++rr; push(a[rr]);
    }
    if (st.size() == 0) printf("Nothing\n"); else printf("%d\n", (*st.begin()));
    return 0;
}