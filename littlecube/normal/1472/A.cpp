#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;


int main()
{
    ll t, w, h, n;
    cin >> t;
    while(t--){
        ll r = 1;
        cin >> w >> h >> n;
        while(w%2==0){
            w /= 2;
            r *= 2;
        }
         while(h%2==0){
            h /= 2;
            r *= 2;
        }
        if(r >= n)
            cout << "YES\n";
            else
                cout << "NO\n";
    }
    return 0;
}