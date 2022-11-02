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

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>

typedef long long i64;
const double eps = 1e-7;
const i64 inf = 1e18;


int main()
{
    ios_base::sync_with_stdio(false);
    
    i64 n, m, s;
    
    cin >> n >> m >> s;
    
    i64 res = 0;
    
    for (int a = 0; 2 * a + 1 <= n; ++a)
        for (int b = 0; 2 * b + 1 <= m; ++b)
            for (int c = 0; 2 * c + 1 <= n; ++c)
            {
                i64 aa = 2 * a + 1, bb = 2 * b + 1, cc = 2 * c + 1;
                i64 curs = s - aa * bb;
                i64 dd;
                
                if (curs < 0)
                    continue;
                
                if (curs == 0 && cc > aa)
                    continue;
                    
                if (curs == 0)
                {
                    dd = -1;
                }
                else
                {
                    if (cc <= aa)
                    {
                        if (curs % cc != 0)
                            continue;
                            
                        i64 len = curs / cc;
                        
                        if (len % 2 == 1)
                            continue;
                        dd = len + bb;
                        dd /= 2;
                    }
                    else
                    {
                        if (cc * bb >= s)
                        {
                            i64 len = cc - aa;
                            if (curs % len != 0)
                                continue;
                            else
                                dd = curs / len;
                            if (dd % 2 == 0)
                                continue;
                            dd /= 2;
                        }
                        else
                        {
                            if (s % cc != 0)
                                continue;
                            else
                                dd = s / cc;
                            if (dd % 2 == 0)
                                continue;
                            dd /= 2;
                        }
                    }
                }
                    
                i64 l = max(a, c), r = n - max(a, c) - 1;
                i64 resl = max(0ll, (r - l + 1));
                
                l = max((i64)b, dd), r = m - max((i64)b, dd) - 1;
                i64 resr = max(0ll, r - l + 1);
                
                i64 cur = resl * resr;
                if (dd < 0)
                    cur *= (b + 1);
                
                res += cur;
            }
            
    cout << res;
                    
    cin >> n;
    
    return 0;
}