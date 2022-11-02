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
#define REP(i, l, r) for(int i = l; i <= r; ++i)

int main()
{
    ios_base::sync_with_stdio(0);
    
    int x, t, a, b, da, db;
    bool ok = false;
    
    cin >> x >> t >> a >> b >> da >> db;
    if(x == 0)
        ok = true;
    
    for(int t1 = 0; t1 < t; ++t1)
        for(int t2 = 0; t2 < t; ++t2)
        {
            if(a - t1 * da == x)
                ok = true;
            if(b - t2 * db == x)
                ok = true;
            if(a - t1 * da + b - db * t2 == x)
                ok = true;
        }
    
    cout << (ok ? "YES" : "NO");
    
    cin >> x;
    return 0;
}