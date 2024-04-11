//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 1e6 + 10;
int a[maxN];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int d, b, c; 
    cin >> d >> b >> c; 
    int n; cin >> n;
    for( int i = 0 ; i < n ; i++ ) 
        cin >> a[i]; 
    sort( a , a + n ); 
    cout << lower_bound( a , a + n , c ) - upper_bound( a , a + n , b ) << endl;

}