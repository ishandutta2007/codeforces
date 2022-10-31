//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

int main() { 
    ll n,m; 
    cin >> n >> m; 
    if( m >= n ) { 
        cout << n << endl;
        return 0; 
    }
    ll cap = n;
    // m days has passed
    // after i th day , m will be added and m+i will be removed
    // let's move one day forward..
    cap -= m + 1; 
    // after this day there will be no more min(n,cap)
    cap ++; 
    // now each day i will be decreased , find when 
    // cap - ( 1 + 2 + 3 + ... + i ) <= 0 
    // cap - i * ( i + 1 ) / 2 <= 0
    // 2 * cap <= i * (i+1) 
    ll v = 2 * cap; 
    ll s = 0 , e = 2e9 + 10; 
    while( e - s > 1 ) { 
        ll m = (s+e)/2; 
        if( m * (m+1) >= v ) 
            e = m; 
        else
            s = m; 
    }
    cout << m + e << endl;
}