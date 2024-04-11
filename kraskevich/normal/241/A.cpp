#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    
    long long m, k;
    cin >> m >> k;
    
    long long d[m], s[m];
    for (int i = 0; i < m; ++i)
        cin >> d[i];
    for (int i = 0; i < m; ++i)
        cin >> s[i];
    
    long long now = 0, time = 0;
    
    for (int i = 0; i < m;)
    {
        int nxt = m;
        for (int j = i + 1; j < m; ++j)
            if (s[j] > s[i])
            {
                nxt = j;
                break;
            }
        
        long long l = 0, r = 1000 * 1000 * 1000;
        long long dt = 0;
        long long fuel = 0;
        
        while (l < r)
        {
            long long m = (l + r) / 2;
            bool ok = true;
            fuel = now + (m + 1) * s[i];
            
            
            for (int j = i; j < nxt; ++j)
            {
                if (j != i)
                    fuel += s[j];
                fuel -= d[j];
                if (fuel < 0)
                    ok = false;
            }
            
            if (ok)
                r = m;
            else
                l = m + 1;
        }
        
        //cout << nxt << " " << l << endl;
        
        
        dt = 0;
        fuel = now + (l + 1) * s[i];
        
            
        for (int j = i; j < nxt; ++j)
        {
            fuel -= d[j];
            if (j != i)
                fuel += s[j];
            dt += d[j];
        }
        
        time += (dt + l * k);
        now = fuel;
        i = nxt;
    }
    
    cout << time;
    
    //cin >> time;

    
    return 0;
}