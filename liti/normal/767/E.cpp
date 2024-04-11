//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
#define int ll
typedef pair<int,int> pii; 

const int maxN = 1000 * 100 + 10; 
int c[maxN], w[maxN]; 

int pay[maxN]; 
int p[maxN];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m; 
    for( int i = 0 ; i < n ; i++ ) 
        cin >> c[i]; 
    for( int i = 0 ; i < n ; i++ ) 
        cin >> w[i]; 

    ll sum = m; 
    set<pii> curr;
    ll tot = 0; 
    for( int i = 0 ; i < n ; i++ ) { 
        int v = c[i] % 100;
        p[i] = c[i]/100;
        if( v == 0 ) continue;
        pay[i] = v;
        curr.insert( { w[i] * ( 100 - v ) , i } ); 
        if( sum < v ) { 
            pii x = *curr.begin(); 
            curr.erase( curr.begin() ); 
            sum += 100; 
            pay[x.second] = 0 , p[x.second]++;
            tot += x.first;
        }
        sum -= v;
    }

    cout << tot << endl;
    for( int i = 0 ; i < n ; i++ ) 
        cout << p[i] << " " << pay[i] << "\n"; 
}