#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
 
using namespace std;
 
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w;
#define ALL(x) x.begin(), x.end()




int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    
    if (n == 1 || n % 2 == 0)
    {
        cout << -1;
        return 0;
    }
    
    int res = 0;
    for (int i = n; i >= 2; --i)
    {
        int par = i / 2, ch = (i % 2 ? par * 2 : par * 2 + 1);
        while (a[i] > 0)
        {
            --a[i];
            --a[ch];
            --a[par];
            ++res;
        }
    }
    if (a[1] > 0)
        res += a[1];
    
    cout << res;
        
    //WAIT;
    
    return 0;
}