//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii;

const int maxN = 1000 * 100 * 2 + 100; 

int f[maxN], l[maxN];

set<pii> num; 

int a[maxN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q; 

    memset(f, -1, sizeof f); 

    int z = -1;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        if( f[a[i]] == -1 ) 
            f[a[i]] = i; 
        l[a[i]] = i; 
        num.insert( pii(i, a[i]) );

        if( a[i] == 0 ) 
            z = i;
    }

    if( f[q] == -1 ) { 
        if( z == -1 ) { 
            cout << "NO" << endl;
            return 0;
        }
        a[z] = q;
        f[q] = l[q] = z;
        num.erase( pii(z, 0) );
        num.insert( pii(z, q) );
    }

    for(int i = q; i >= 1; i--)
        if( f[i] != -1 ) { 
            auto it = num.lower_bound( pii(f[i], i) );
            while( it->first != l[i] ) { 
                if( it->second == 0 ) 
                    a[it->first] = i;

                if( a[it->first] < i ) { 
                    cout << "NO" << endl;
                    return 0;
                }

                num.erase( it );
                it = num.lower_bound( pii(f[i], i) );
            }
            num.erase( it );
        }

    cout << "YES" << endl;
    for(int i = 0 ; i < n ; i++)
        cout << max(1, a[i]) << ' ' ; 
    cout << endl;

    return 0;
}