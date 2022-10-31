//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii; 

bool pr(ll x) { 
    for(ll i = 2; i * i <= x; i++) 
        if( x % i == 0 ) return false;
    return true;
}

int main() {
    int t;
    cin >> t; 
    for(int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        if( a - b == 1 && pr(a+b) ) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}