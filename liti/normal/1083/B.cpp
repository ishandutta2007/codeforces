//In the name of God
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 
#define sz(x) ((int)(x).size())

int main() { 
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    ll sum = 0; 
    ll curr = 0; 

    int good = 0;
    for(int i = 0; i < n; i++) {
        if( !good ) {
            if( s[i] == t[i] ) 
                sum++; 
            else
                good = 1;
        }
        if( good ) { 
            curr = curr * 2; 
            if( good == 2 && s[i] == 'a' ) 
                curr++; 
            if( good == 2 && t[i] == 'b' )
                curr++; 

            good = 2;

            if( curr + 2 >= k ) {
                cout << sum + ll(n-i) * k << endl;
                return 0;
            }

            sum += curr + 2; 
        }

    }
    cout << sum << endl;

    return 0;
}