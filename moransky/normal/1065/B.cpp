#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
LL n, m;
int main(){
    cin >> n >> m;
    cout << max(n - 2 * m, 0ll) << " ";
    if(m == 0) printf("%lld\n", n);
    else if(m == 1) printf("%lld\n", n - 2);
    else{
        int now = 2;
        while(m - now + 1 > 0 && now < n) m -= (now - 1), now++;
        printf("%lld\n", n - now);
    }
    return 0;
}