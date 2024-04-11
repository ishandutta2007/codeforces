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
#include <fstream>

using namespace std;

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;

i64 tenPw(int n)
{
    i64 res = 1;
    
    for (int i = 0; i < n; ++i)
        res *= 10ll;
        
    return res;
}

i64 calc(i64 x)
{
    if (x < 10)
        return x;
    
    i64 ans = 0;
    
    for (int len = 2; len <= 18; ++len)
        for (int d = 1; d <= 9; ++d)
        {
            i64 l = tenPw(len - 1) * d + d - 1, r = l + (tenPw(len - 2) - 1) * 10 + 1;
            
            while (l < r)
            {
                i64 m = (l + r + 1) / 2; 
                if (m > x)
                    r = m - 1;
                else
                    l = m;
            }
            
            if (l == tenPw(len - 1) * d + d - 1)   
                continue;
                
            if (l % 10 != d)
                --l;
            ans += (l - (tenPw(len - 1) * d + d - 1)) / 10 + 1;
        }
    
    return ans + 9;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    i64 l, r;
    
    cin >> l >> r;
    
    cout << calc(r) - calc(l - 1) << endl;
    
    return 0;
}