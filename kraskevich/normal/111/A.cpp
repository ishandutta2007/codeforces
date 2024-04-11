#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ll n, x, y;
    
    cin >> n >> x >> y;
    
    ll maxN = y - (n - 1);
    if(maxN * maxN + n - 1 < x || n > y)
            cout << -1;
    else {
         cout << maxN << endl;
         for(int i = 0; i < n - 1; ++i)
                 cout << 1 << endl;
    }
    
    cin >> n;
    return 0;
}