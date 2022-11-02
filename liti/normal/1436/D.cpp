#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;

const int N = 2*1000*100 + 100; 
const ll MX = ll(N) * ll(1000*1000*1000);


ll a[N]; 

vector<int> c[N]; 

ll dfs(int s, ll cap) { 
    if( c[s].size() == 0 ) { 
        if( cap < a[s] ) 
            throw(false);
        return cap - a[s]; 
    }

    ll rem_cap = 0;
    for(auto x : c[s])
        rem_cap = min(rem_cap + dfs(x, cap), MX);

    if( rem_cap < a[s] )
        throw(false);
    return rem_cap - a[s];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    cin >> n;

    for(int i = 1; i < n; i++) { 
        int p; 
        cin >> p;
        p--;
        c[p].push_back(i); 
    }

    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    ll l = -1, r = MX;

    while( r - l > 1 ) { 
        ll m = (r + l) / 2; 

        try {
            dfs(0, m); 
            throw(true);
        } catch( bool res ) { 
            if(res)
                r = m;
            else
                l = m;
        }
    }
    cout << r << endl;
}