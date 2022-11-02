//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int a[105]; 
int main() {
    int n,x; cin >> n >> x; x--; 
    for( int i = 0 ; i < n ; i++ ) { 
        int t; cin >> t; 
        a[abs(i-x)] += t; 
    }
    int ans = a[0]; 
    int v = min( x , n - x - 1 ); 
    for( int i = 1 ; i <= v ; i++ ) 
        if( a[i] == 2 ) 
            ans += 2; 
    for( int i = v+1 ; i < n ; i++ ) 
        ans += a[i]; 
    cout << ans << endl;
}