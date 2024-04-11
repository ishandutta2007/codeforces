#include <iostream>
using namespace std;

long long best = 0;

long long calc(long long x, long long y, long long z, long long k) {
     long long curz = k - (x + y);
     curz = min(curz, z - 1);
     long long t = (x + 1) *  (y + 1) * (curz + 1);
     best = max(best, t);
     return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    long long x, y, z, k;
    cin >> x >> y >> z >> k;
    long long all = x * y * z; 
    for(int xx = 0; xx <= x - 1; ++xx) {
            int l = 0, r = y - 1;
            while(l < r - 3) {
                    int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
                    if(calc(xx, m1, z, k) > calc(xx, m2, z, k))
                               r = m2;
                    else
                        l = m1;
            }
            for(int i = l; i <= r; ++i)
                    calc(xx, i, z, k);
    }               
    
    cout << best << endl;
    
    cin >> k;                  
    return 0;
}