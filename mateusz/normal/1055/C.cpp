#include <bits/stdc++.h>

using namespace std;

int main() {
    long long la, ra, ta,
              lb, rb, tb;
              
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    
    long long d = __gcd(ta, tb);
    if (la > lb) {
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }
    
    long long firstStart = (lb - la) / d * d + la;
    
    long long firstEnd = firstStart + (ra - la);
    long long ans = max(0LL, min(firstEnd, rb) - lb + 1);
    
    long long secondStart = firstStart + d;
    long long secondEnd = secondStart + (ra - la);
    ans = max(ans, min(secondEnd, rb) - secondStart + 1);
    
    cout << ans << endl;
    return 0;
}