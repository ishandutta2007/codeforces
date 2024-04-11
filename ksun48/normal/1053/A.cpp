#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, m, k;
    cin >> n >> m >> k;
    LL n1, m1, k1;
    n1 = n; m1 = m; k1 = k;
    LL a = __gcd(n1, k1);
    n1 /= a;
    k1 /= a;
    LL b = __gcd(m1, k1);
    m1 /= b;
    k1 /= b;
    if(k1 > 2){
        cout << "NO" << '\n';
    } else if(k1 == 2){
        cout << "YES" << '\n';
        cout << 0 << " " << 0 << endl;
        cout << n1 << " " << 0 << endl;
        cout << n1 << " " << m1 << endl;
    } else if(k1 == 1){
        if(n1 * 2 <= n){
            n1 *= 2;
        } else if(m1 * 2 <= m){
            m1 *= 2;
        }
        cout << "YES" << '\n';
        cout << 0 << " " << 0 << endl;
        cout << n1 << " " << 0 << endl;
        cout << n1 << " " << m1 << endl;
    }
}