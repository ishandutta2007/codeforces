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
 
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w;
#define ALL(x) x.begin(), x.end()

bool bit(int mask, int i)
{
    return ((mask & (1 << i)) ? 1 : 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
   
    int n;
    cin >> n;
    
    int b[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    
    for (int i = 0; i < n; ++i)
    {
        vector<bool> bits(31, false);
        
        for (int j = 0; j < n; ++j)
        {
            if (j == i)
                continue;
                
            for (int bt = 0; bt < 31; ++bt)
                if (bit(b[i][j], bt))
                    bits[bt] = true;
        }
        
        int res = 0;
        for (int bt = 0; bt < 31; ++bt)
            if (bits[bt])
                res = (res | (1 << bt));
        
        cout << res << " ";
    }
    
    return 0;
}