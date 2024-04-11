//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 1000 * 100 + 10;
set<int> curr;
int main() {
    int n; cin >> n; 

    int now = n; 
    for( int i = 0 ; i < n ; i++ ) { 
        int x; cin >> x; 
        curr.insert( x );
        while( curr.size() && *curr.rbegin() == now ) { 
            cout << *curr.rbegin() << " " ;
            curr.erase( --curr.end() );
            now--; 
        }
        cout << endl;
    }
}