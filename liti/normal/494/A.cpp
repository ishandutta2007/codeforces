/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
const int maxN = 100*1000 + 10; 

int a[maxN];
int main() { 
    string s;
    cin >> s; 

    int cnt = 0;

    int last = -1;
    int k = -1;
    for( int i = 0 ; i < sz( s ) ; i++ ) {
        if( s[i] == '(' ) 
            cnt++;
        else
            cnt--;
        if( cnt < 0 ) {
            cout << -1 << endl;
            return 0;
        }
        if( s[i] == '#' ) { 
            last = i; 
            k = cnt ;
        }
        k = min( cnt , k ) ; 
    }
//  cout << k << ' ' << cnt << endl;
    if( k < cnt ) {
        cout << -1 << endl;
        return 0;
    }

    for( int i = 0 ;i < sz(s) ; i++ ) 
        if( s[i] == '#' && i != last ) 
            cout << 1 << endl;
    if( last != -1 ) 
        cout << cnt + 1 << endl;
}