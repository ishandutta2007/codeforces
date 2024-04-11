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
                    
int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    
    cin >> n >> m;
    
    int cur = (m + 1) / 2;
    
    int go[m];
    
    int l = (m + 1) / 2, r = l + 1;
    
    if(m % 2 == 1)
    {
         go[l] = l - 1;
         --l;
    }
    
    while(l > 0)
    {
            go[l] = r;
            go[r] = l - 1;
            --l;
            ++r;
    }
    
    for(int i = 0; i < n; ++i)
    {
            cout << cur << endl;
            cur = go[cur];
            if(cur <= 0 || cur > m)
                   cur = (m + 1) / 2;
    }
    
    cin >> n;
    
    return 0;
}