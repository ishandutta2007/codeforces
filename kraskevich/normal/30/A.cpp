#include <iostream>
using namespace std;

#define ll long long

ll pw(ll a, ll n) {
         ll res = 1;
         for(int i = 0; i < n; ++i) res *= a;
         return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll a, b, n;
    cin >> a >> b >> n;
    for(int x = -min(1000ll, pw(10, 10 / n)); x <= min(1000ll, pw(10, 10 / n)); ++x)
            if(a * pw(x, n) == b) {
                 cout << x;
                 cin >> n;
                 return 0;
            }
    cout << "No solution";
    
    cin >> n;
    return 0;
}