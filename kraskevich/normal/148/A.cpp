#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int k, l, m, n , d;
    
    cin >> k >> l >> m >> n >> d;
    
    vector<bool> u(d, false);
    
    for(int i = k - 1; i < d; i += k)
            u[i] = true;
    for(int i = l - 1; i < d; i += l)
            u[i] = true;
    for(int i = n - 1; i < d; i += n)
            u[i] = true;
    for(int i = m - 1; i < d; i += m)
            u[i] = true;
    
    int res = 0;
    
    for(int i = 0; i < d; ++i)
            if(u[i])
                    ++res;
    
    cout << res;
    
    return 0;
}