#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long i64;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    if(n == 0 && m != 0)
    {
         cout << "Impossible";
         return 0;
    }
    if(n == 0 && m == 0)
    {
         cout << "0 0";
         return 0;
    }
    
    cout << n + max(0, m - n) << " " << n + max(m - 1, 0);
    
    cin >> n;
    
    return 0;
}