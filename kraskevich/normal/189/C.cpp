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

const int N = 300 * 1000;
int pos[N];
int a[N];
int b[N];
int move[N];
int n;

bool can(int k)
{
     int p = n - k;
     bool ok = true;
     for(int i = 0; i < p; ++i)
             move[i] = pos[a[i]] - i;
     if(move[0] > k || move[0] < 0)
                ok = false;
     for(int i = 1; i < p; ++i)
             if(move[i] < move[i - 1] || move[i] > k || move[i] < 0)
                        ok = false;
     return ok;
}
      
int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    for(int i = 0; i < n; ++i)
    {
            cin >> b[i];
            pos[b[i]] = i;
    }
    
    int l = 0, r = n - 1;
    while(l < r - 1)
    {
            int m = (l + r) / 2;
            if(can(m))
                      r = m;
            else
                l = m;
    }
    if(can(l))
              r = l;
              
    cout << r << endl;
    
    cin >> n;
    
    return 0;
}