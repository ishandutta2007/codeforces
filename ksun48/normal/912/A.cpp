#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    LL ans = max(0LL, 2*x+y-a) + max(0LL, 3*z + y - b);
    cout << ans << endl;
}