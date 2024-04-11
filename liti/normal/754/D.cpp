//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

struct Q { 
    int l,r, id; 
}; 

inline bool cmp( Q a , Q b ) { 
    if( a.l == b.l ) 
        return a.r < b.r; 
    return a.l < b.l; 
}

set<pair<int,int>> curr,good; 

const int maxN = 3 * 100 * 1000 + 100; 

Q a[maxN];
int n, k;

int solve( int mx ) { 
    curr.clear(); 
    good.clear(); 

    int ret = 0; 
    for( int i = 0 ; i < n ; i++ ) { 
        auto x = a[i]; 
        good.insert( { x.r , x.id } ); 
        if( good.size() > k ) { 
            auto v = *good.begin(); 
            good.erase( v ); 
        }
        if( good.size() == k ) { 
            ret = max( ret , good.begin()->first - x.l ); 
            if( ret == mx ) { 

                cout << ret << endl;
                vector<int> ans; 
                for( auto y : good ) 
                    ans.push_back( y.second ); 
                sort( ans.begin() , ans.end() ); 
                for( int i = 0 ; i < k ; i++ ) 
                    cout << ans[i] << " " ; 
                cout << endl;
                return mx; 
            }
        }
    }
    return ret; 
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> k;

    for( int i = 0 ; i < n ; i++ ) { 
        cin >> a[i].l >> a[i].r ; 
        a[i].l--;
        a[i].id = i+1; 
    }
    sort( a , a + n , cmp ); 
    int val = solve( maxN + 10 ); 
    solve( val ); 
}