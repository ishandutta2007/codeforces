//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000 + 10;
int a[maxN];
int main() {
    int n; cin >> n; 
    for( int i = 0 ; i < n ; i++ ) 
        cin >> a[i]; 
    int cnt = 0;
    for( int i = 1 ; i + 1 < n ; i++ ) 
        if( a[i] < min( a[i+1], a[i-1] ) || a[i] > max(a[i-1],a[i+1]) )
            cnt++;
    cout << cnt << endl;
}