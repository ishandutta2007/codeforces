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

#define ll long long
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back 

const ll mod = 1e9 + 7;

ll pw(ll x, ll n)
{
         ll res = 1;
         while(n)
         {
                 if(n % 2 == 0)
                 {
                      n /= 2;
                      x *= x;
                      x %= mod;
                 }
                 else
                 {
                     res *= x;
                     --n;
                     res %= mod;
                 }
         }
         return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    ll n;
    
    cin >> n;
    
    if(n == 0)
    {
         cout << 1;
         return 0;
    }
    
    ll all = pw(4, n - 1) * 2ll, diff = pw(2, n - 1);
    
    cout << (all + diff) % mod;
    
    cin >> n;
    
    return 0;
}