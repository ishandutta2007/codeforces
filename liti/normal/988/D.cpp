//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 2000 * 100 + 10;

typedef long long ll;

ll a[maxN]; 

map<ll,int> id; 

int main(){ 
    ios::sync_with_stdio(false); cin.tie(0); 

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort( a , a + n ); 

    pair<int, vector<int>> ans; 

    {
        vector<int> tmp; 
        tmp.push_back( a[0] );
        ans = make_pair( 1 , tmp );
    }


    for( int i = 0 ; i < n ; i++ ) { 
        for( int t = 0 ; t < 34 ; t++ ) { 
            ll d = (1ll<<t); 
            if( id.count(a[i] - d) && ans.first == 1 ) { 
                ans.first = 2; 
                vector<int> tmp;
                tmp.push_back( a[i] - d ) ;
                tmp.push_back( a[i] ); 
                ans.second = tmp;
            }
            if( id.count(a[i] - d) && id.count(a[i] - 2 * d) && ans.first == 2 ) { 
                ans.first = 3; 
                vector<int> tmp;
                tmp.push_back( a[i] - 2*d ) ;
                tmp.push_back( a[i] - d ) ;
                tmp.push_back( a[i] ); 
                ans.second = tmp;
                break;
            }
        }
        id[a[i]] = i; 
    }
    cout << ans.first << endl;
    for( auto x : ans.second ) 
        cout << x << " " ;
    cout << endl;
}