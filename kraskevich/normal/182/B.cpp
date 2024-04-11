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

ll a[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    
    ll n, d;
    
    cin >> d >> n;
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    ll s = 0, op = 0;
    
    for(int i = 0; i < n; ++i)
    {
            if(s != 0)
                 op += d - s;
            s = a[i] % d;
    }
    
    cout << op << endl;
    
    cin >> n;
    return 0;
}