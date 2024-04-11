//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b; 

    int x[2] = {0,0}; 
    int y[2] = {0,0};

    long long ans = 0;
    for(int i = 0; i < n; i++) { 
        if( b[i] == '0' ) 
            ans += y[ 1 - ( a[i] - '0' ) ];
        else
            ans += x[ 1 - ( a[i] - '0' ) ];

        if( b[i] == '0' ) 
            x[ a[i] - '0' ]++; 
        y[ a[i] - '0' ]++; 
    }
    
    cout << ans << endl;

    return 0;
}