#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define FORN for(int i = 0; i < n; ++i)
#define PB push_back

i64 a, b, c;

bool can(i64 t)
{
     i64 now = t * b;
     for(i64 i = 1; i <= c; ++i)
             if(now + b * i < a * i)
                    return false;
     return true;
}
                    
int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> c;
    
    i64 l = 0, r = a * c;
    while(l < r)
    {
            i64 m = (l + r) / 2;
            if(can(m))
                      r = m;
            else
                l = m + 1;
    }
    
    cout << l;
    
    cin >> a;
    return 0;
}