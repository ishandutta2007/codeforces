//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int main() { 
    int t[5], sum = 0; 
    for( int i = 0 ; i < 5 ; i++ ) {
        cin >> t[i]; 
        sum += t[i]; 
    }
    sort( t , t + 5 ); 
    int ans = sum;
    for( int i = 4 ; i > 0 ; i-- ) 
        if( i > 1 && t[i] == t[i-2] )
            ans = min(ans, sum - 3 * t[i] ); 
        else if( t[i] == t[i-1] ) 
            ans = min( ans , sum - 2 * t[i] ); 
    cout << ans << endl;
}