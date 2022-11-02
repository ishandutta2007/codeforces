#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <list>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define pii pair<long long, long long>
#define forn for(int i = 0; i < n; ++i)

i64 a[100000];
i64 sum[100000];
vector<pii> cost;
set<int> best;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    i64 b;
    cin >> b;
    forn cin >> a[i];
    i64 ans = n - 1;
    
    for(int i = 0; i < n - 1; ++i)
        cost.push_back(pii(a[i], i));
    sort(cost.begin(), cost.end());
    reverse(cost.begin(), cost.end());
    
    for(int i = 0; i < k - 1; ++i)
            best.insert(cost[i].S);
            
    i64 smalls = 0, bigs = 0;
    for(int i = 0; i < k - 1; ++i)
            smalls += cost[i].F;
    bigs = smalls + cost[k - 1].F;
    
    for(int i = 0; i < n; ++i)
    {
            i64 cur;
            if(!best.count(i))
                              cur = smalls + a[i];
            else
                cur = bigs;
            if(cur > b)
                   ans = min(ans, (i64)i);
    }
                              
    cout << ans + 1;
    
    cin >> n;         
    return 0;
}