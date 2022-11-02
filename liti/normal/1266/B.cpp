//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second 

const int N = -1; 

int main() { 
    int n; 
    cin >> n; 
    while(n--) { 
        ll x; 
        cin >> x; 
        ll mod = x % 14; 
        if( 14 <= x && 1 <= mod && mod <= 6 ) 
            cout << "YES\n"; 
        else
            cout << "NO\n"; 
    }

}