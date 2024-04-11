//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 * 100 + 100;

int a[maxN];

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, k;
    cin >> n >> x >> k;

    for( int i = 0 ; i < n ; i++ ) 
        cin >> a[i]; 

    sort(a, a + n); 
    int l = 0, r = 0; 

    long long ans = 0;
    for(int i = 0 ; i < n ; i++ ) { 
        while( l < n && a[l] < a[i] ) 
            l++;
        while( r < n && a[r] < a[i] ) 
            r++;
        while( l < n && a[l] / x - ( a[i] - 1 ) / x < k )
            l++;
        while( r < n && a[r] / x - ( a[i] - 1 ) / x <= k )
            r++;
        ans += r - l;
    }
    cout << ans << endl;
}