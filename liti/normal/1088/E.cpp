//8:15
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 3 * 100 * 1000 + 10; 
ll a[maxN]; 

vector<int> c[maxN]; 

ll ans; 
int anscnt; 

ll dfs(int s, int p, bool fin) { 
    ll r = a[s]; 
    for( auto x : c[s] ) 
        if( x != p ) { 
            ll v = dfs( x , s , fin ); 
            if( v > 0 ) 
                r += v; 
        }
    if( !fin ) 
        ans = max(ans, r); 
    else if( ans == r ) {
        anscnt++; 
        return -1; 
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    int n;
    cin >> n;

    int pos = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
        if( a[i] > 0 ) 
            pos = i;
    }

    for(int i = 1 ; i < n; i++)  { 
        int u, v;
        cin >> u >> v; 
        u--; v--; 
        c[u].push_back(v);
        c[v].push_back(u); 
    }


    if( pos != -1 ) { 
        dfs(pos, -1, false);
        dfs(pos, -1, true); 
        cout << ans * anscnt << ' ' << anscnt << endl;
    } else {
        ll v = *max_element(a, a + n); 
        int cnt = 0;
        for(int i = 0; i < n; i++) 
            if( a[i] == v ) 
                cnt++; 
        cout << v * cnt << ' ' << cnt << endl;
    }

    return 0;
}