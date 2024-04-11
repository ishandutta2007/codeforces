#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int dpr = 0, dpb = 0;
    
    for (int i = 0; i < n; ++i)
        if (i % 2 == 0)
            dpr += dpb + 1, dpr %= mod;
        else
            dpb += dpr + 1, dpb %= mod;
    
    cout << (dpb + dpr) % mod;
    
    cin >> n;
    
    return 0;
}