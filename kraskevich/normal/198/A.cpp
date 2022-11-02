#include <iostream> 
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    long long n, k, b, t;
    
    cin >> k >> b >> n >> t;
    
    if(k == 1)
    {
        long long z = b * n + 1;
        cout << max(0ll, (z - t) / b + ((z - t) % b ? 1 : 0));
    }
    else
    {
        long long x = n;
        long long cur = 1;
        
        while(cur <= (double)(t * (k - 1) + b) / (double)(k - 1 + b) && x >= 0 && cur > 0)
            cur *= k, --x;
        
        cout << x + 1;
    }
    
    cin >> k;
    
    return 0;
}