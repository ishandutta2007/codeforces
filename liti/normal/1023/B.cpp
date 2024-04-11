//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;

    if( k <= n ) 
        cout << (k-1)/2 << endl;
    else  
        cout << max(0ll, (n - (k-n) + 1) / 2) << endl;

    return 0;
}