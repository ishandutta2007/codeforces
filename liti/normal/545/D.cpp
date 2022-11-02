//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
 
const int maxN = 1000*100 + 100; 
ll a[maxN];
int main() { 
    int n; 
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) 
	cin >> a[i]; 
    sort( a , a + n ) ; 
    int ans = 0; 
    ll sum = 0; 
    for( int i = 0 ; i < n ; i++ ) { 
	if( sum > a[i] ) continue; 
	sum += a[i]; 
	ans++; 
    }
    cout << ans << endl;
}