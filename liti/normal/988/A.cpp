//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
set<int> a; 
map<int,int> ind;

int main() {
    int n, k;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ) { 
        int x; cin >> x; 
        a.insert(x); 
        ind[x] = i;
    }
    if( a.size() < k ) 
        cout << "NO" << endl;
    else { 
        cout << "YES" << endl;
        for( int i = 0 ; i < k ; i++ ) { 
            cout << ind[*a.begin()] + 1 << ' ' ;
            a.erase(a.begin());
        }
    }
}