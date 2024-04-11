#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;

//#define DEBUG 1



int main()
{
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
    #endif
    
    int k, n;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    vector<int> delta(k + 1, 0);
    int prev = -1, cur = -1;
    
    for (int i = 0; i < n; ++i)
    {
        if (cur > 0 &&  a[i] != cur)
        {
            if (prev == a[i])
                delta[cur] += 2;
            else
                delta[cur] += 1;
            prev = cur;
        }
        cur = a[i];
    }
    delta[cur]++;
    
    int mx = 0;
    for (int i = 1; i <= k; ++i)
        mx = max(mx, delta[i]);
    for (int i = 1; i <= k; ++i)
        if (delta[i] == mx)
        {
            cout << i;
            break;
        }
    
    return 0;
}