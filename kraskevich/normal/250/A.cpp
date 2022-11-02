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
    
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    int all = 0, cur = 0;
    vector<int> res;
    
    for (int i = 0; i < n; ++i)
    {
        ++all;
        if (a[i] < 0)
            ++cur;
        if (cur == 3)
        {
            res.push_back(all - 1);
            all = 1;
            cur = 1;
        }
    }
    
    res.push_back(all);
    
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
        
    
    return 0;
}