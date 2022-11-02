#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long i64;
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back

int main()
{
    ios_base::sync_with_stdio(0);
    
    i64 w, h;
    
    cin >> w >> h;
    
    i64 ans = 0;
    
    for(i64 i = 2; i <= w; i += 2)
            for(i64 j = 2; j <= h; j += 2)
                    ans += (w - i + 1) * (h - j + 1);
    
    cout << ans;
    
    cin >> w;
    
    return 0;
}