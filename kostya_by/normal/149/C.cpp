//
//  main.cpp
//  cf106task3
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

using namespace std;

int a, n;
vector<int> nums[11111];
vector<int> teamA, teamB;
vector< pair<int, int> > remains;

bool cmp( pair<int, int> p1, pair<int, int> p2 )
{
    if (p1.first > p2.first) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        nums[a].pb(i);
    }
    for (int i = 0; i < 11111; i++)
    {
        while (nums[i].size() >= 2)
        {
            teamA.push_back( nums[i].back() ); nums[i].erase( nums[i].end() - 1 );
            teamB.push_back( nums[i].back() ); nums[i].erase( nums[i].end() - 1 );
        }
        if (nums[i].size() == 1)
        {
            remains.pb( mp( i, nums[i][0] ) );
        }
    }
    sort( remains.begin(), remains.end(), cmp);
    int nn = remains.size();
    if (nn % 2 == 1) nn = nn / 2 + 1; else nn = nn / 2;
    int suma = 0, sumb = 0, numa = 0, numb = 0;
    for (int i = 0; i < remains.size(); i++)
    {
        if (numa == nn)
        {
            teamB.pb( remains[i].second );
            sumb += remains[i].first;
            continue;
        }
        if (numb == nn)
        {
            teamA.pb( remains[i].second );
            suma += remains[i].first;
            continue;
        }
        if (suma < sumb)
        {
            numa++;
            teamA.pb( remains[i].second );
            suma += remains[i].first;
            continue;
        }
        teamB.pb( remains[i].second );
        sumb += remains[i].first;
        numb++;
    }
    printf("%d\n", int(teamA.size()));
    for (int i = 0; i < teamA.size(); i++) printf("%d ", teamA[i] + 1); printf("\n");
    printf("%d\n", int(teamB.size()));
    for (int i = 0; i < teamB.size(); i++) printf("%d ", teamB[i] + 1);
    return 0;
}