//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

int main() {
    int n;
    cin >> n; 
    int v = int(sqrt(n)) - 1; 
    while( v * v < n ) 
        v++; 

    for(int i = 0; i < n; i += v ) { 
        for(int j = min(i + v - 1, n -1) ; j >= i; j-- ) 
            cout << 1 + j << ' ';
    }
    cout << endl;
    return 0;
}