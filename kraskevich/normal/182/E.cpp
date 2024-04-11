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
using namespace std;

#define ll long long
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back


ll mod = (ll)1e9 + 7;
int f[100][3001][101];
int se[100][3001][101];
int a[101], b[101];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, l;
    
    cin >> n >> l;
    
    for(int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
    
    for(int i = 0; i < 100; ++i)
            for(int j = 0; j <= 3000; ++j)
                    for(int k = 0; k <= 100; ++k)
                            f[i][j][k] = se[i][j][k] = 0;
    
    for(int i = 0; i < 100; ++i)
            for(int h = 0; h <= 100; ++h)
                    se[i][0][h] = 1;
    
    ll ans = 0;
    
    for(int len = 1; len <= l; ++len)
    {
            for(int i = 0; i < n; ++i)
            {
                    int ca = a[i], cb = b[i];
                    int prev = len - ca;
                    if(prev >= 0)
                    {
                            f[i][len][cb] += se[i][len - ca][ca];
                            f[i][len][cb] %= mod;
                    
                    }
                    swap(ca, cb);
                    prev = len - ca;
                    if(prev >= 0 && ca != cb)
                    {
                            f[i][len][cb] += se[i][len - ca][ca];
                            f[i][len][cb] %= mod;
                    
                    }
            }
            ll s = 0;
            for(int h = 0; h <= 100; ++h)
            {
                    s = 0;
                    for(int i = 0; i < n; ++i)
                            s += (ll)f[i][len][h];
                    for(int i = 0; i < n; ++i)
                            se[i][len][h] = (s - (ll)f[i][len][h]) % mod;
            }
    }
    
    for(int h = 0; h <= 100; ++h)
            for(int i = 0; i < n; ++i)
                    ans += (ll)f[i][l][h], ans %= mod;
    
    cout << ans % mod;
    
    return 0;
}