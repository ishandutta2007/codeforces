#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;

vector<int> g[200];
vector<bool> u(200, false);

bool check(int v)
{
    for (int i = 0; i < g[v].size(); ++i)
        if (!u[g[v][i]])
            return false;
    return true;
}

bool all(int n)
{
    for (int i = 0; i < n; ++i)
        if (!u[i])
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    
    int c[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        c[i]--;
    }
    
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        
        for (int j = 0; j < k; ++j)
        {
            int v;
            cin >> v;
            
            g[i].push_back(--v);
        }
    }
    
    int res = inf;
    
    for (int s = 0; s < 3; ++s)
    {
        u.assign(n, false);
        
        int col = s;
        int cur = 0;
        
        for (;;)
        {
            int i = 0;
            while (i < n)
                if (c[i] == col && !u[i] && check(i))
                {
                    u[i] = true;
                    ++cur;
                    i = 0;
                }
                else
                {
                    ++i;
                }
            
            if (all(n)) 
                break;
            
            ++cur;
            col = (col + 1) % 3;
        }
        
        res = min(res, cur);
    }
    
    cout << res;           
                
    return 0;
}