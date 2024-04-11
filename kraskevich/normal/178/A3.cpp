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

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    ll a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    ll sum = 0;
    for(int i = 0; i < n - 1; ++i)
    {
            int t = 0;
            while((1ll << t) + i < n)
                     ++t;
            --t;
            a[i + (1 << t)] += a[i];
            sum += a[i];
            cout << sum << endl;
    }
    
    cin >> n;
            
    return 0;
}