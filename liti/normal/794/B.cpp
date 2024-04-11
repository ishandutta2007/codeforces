//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

ld H; 
void solve( int n , ld h , ld base , ld toadd ) { 
    if( n == 1 ) return; 
    ld k = sqrt( (n-1)/ld(n)  ); 
    solve( n - 1 , h * k , base * k , toadd + h - k * h ); 
    cout << H - (toadd + h - k * h) << ' ' ; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision( 20 ); 
    int n, h; 
    cin >> n >> h; 
    H = h;
    solve( n , h , 1 , 0 ); 
}