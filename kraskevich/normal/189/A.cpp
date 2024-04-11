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
    
    i64 n, a, b, c;
    
    cin >> n >> a >> b >> c;
    
    i64 ans = 0;
    
    for(int i = 0; i <= 4000; ++i)
            for(int j = 0; j <= 4000; ++j)
            {
                    i64 cur = i * a + j * b;
                    if(cur > n || (n - cur) % c != 0)
                           continue;
                    i64 cnt = (n - cur) / c;
                    ans = max(ans, i + j + cnt);
            }
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}