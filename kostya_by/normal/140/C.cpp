//
//  main.cpp
//  round100task3
//
//  Created by Sokol Kostya's MacBook on 04.01.11.
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
#include <queue>

typedef unsigned long long ull;
#define mp make_pair

const long double eps = 1e-7;
const long long inf = 1e18;

using namespace std;

struct tans
{
    int a1, a2, a3;
};

class cmp
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first < p2.first) return true;
        if (p1.first == p2.first && p1.second > p2.second) return true;
        return false;
    };
};

int n, aa;
vector< pair<int, int> > a;
vector< tans > ans;
map<int, int> rr;
map<int, int>::iterator it;
priority_queue< pair<int, int> , vector< pair<int, int> >, cmp> pp;

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &aa);
        rr[aa]++;
    }
    it = rr.begin();
    while (it != rr.end())
    {
        pp.push(mp(it->second, it->first));
        it++;
    }
    for (;pp.size() >= 3;)
    {
        pair<int, int> p1, p2, p3;
        p1 = pp.top();
        pp.pop();
        p2 = pp.top();
        pp.pop();
        p3 = pp.top();
        pp.pop();
        tans aaa;
        int aaaa[3];
        aaaa[0] = p1.second;
        aaaa[1] = p2.second;
        aaaa[2] = p3.second;
        sort(aaaa, aaaa + 3);
        aaa.a1 = aaaa[0];
        aaa.a2 = aaaa[1];
        aaa.a3 = aaaa[2];
        ans.push_back(aaa);
        p1.first--;
        p2.first--;
        p3.first--;
        if (p1.first != 0) pp.push(p1);
        if (p2.first != 0) pp.push(p2);
        if (p3.first != 0) pp.push(p3);
    }
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d %d %d\n",ans[i].a3,ans[i].a2,ans[i].a1);
    }
    return 0;
}