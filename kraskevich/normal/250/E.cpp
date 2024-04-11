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

string s[200];
string no = "Never";

int main()
{
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
    #endif
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    
    
    int x = 0;
    int dir = 1; // 1 - right; -1 - left
    bool ok = true;
    long long timer = 0;
    
    for (int i = 0; i < n - 1; ++i)
    {
        set<int> lo;
        set<int> cur;
        
        int l = -1, r = m;
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#')
            {
                if (j < x)
                    l = j;
                else
                    r = min(r, j);
            }
        ++l;
        --r;
        
        for (int j = l; j <= r; ++j)
            if (s[i][j] == '+')
                cur.insert(j);
        for (int j = l; j <= r; ++j)
            if (s[i + 1][j] == '.')
                lo.insert(j);
        
        if (!lo.size())
        {
            ok = false;
            break;
        }
        
        for(;;)
            {
            if (dir == 1)
            {
                set<int>::iterator iter = cur.lower_bound(x);
                int bod;
                if (iter == cur.end())
                    bod = r + 1;
                else
                    bod = *iter;
                
                int stp;
                iter = lo.lower_bound(x);
                if (iter == lo.end())
                    stp = r + 1;
                else
                    stp = *iter;
                
                if (stp < bod)
                {
                    timer += stp - x + 1;
                    x = stp;
                    break;
                }
                else
                {
                    timer += bod - x;
                    x = bod - 1;
                    cur.erase(bod);
                    dir = -1;
                }
            }
            else
            {
                set<int>::iterator iter = cur.lower_bound(x);
                int bod;
                
                if (iter == cur.begin())
                    bod = l - 1;
                else
                {
                    --iter;
                    bod = *iter;
                }
                
                int stp;
                iter = lo.upper_bound(x);
                if (iter == lo.begin())
                    stp = l - 1;
                else
                {
                    --iter;
                    stp = *iter;
                }
                
                if (stp > bod)
                {
                    timer += x - stp + 1;
                    x = stp;
                    break;
                }
                else
                {
                    timer += x - bod;
                    x = bod + 1;
                    cur.erase(bod);
                    dir = 1;
                }
            }
        }
        
    }
    
    if (!ok)
        cout << no;
    else
        cout << timer;
        
            
    
    return 0;
}