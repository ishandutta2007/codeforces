//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second 

const int N = 1000*100 + 100;  

ll val[N]; 

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 

    int n, m;
    cin >> n >> m; 

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; 
        u--; v--; 

        val[v] += w; 
        val[u] -= w; 
    }

    vector<int> l, r; 
    for(int i = 0; i < n; i++) 
        if( val[i] < 0 ) 
            l.push_back(i); 
        else if( val[i] > 0 ) 
            r.push_back(i); 

    int i = 0, j = 0; 

    vector<pair<pair<int,int>,ll>> ans; 
    while( i != l.size() && j != r.size() ) { 
        if( val[l[i]] == 0 ) { 
            i++; 
            continue; 
        }
        if( val[r[j]] == 0 ) {
            j++; 
            continue; 
        }


        ll mn = min( -val[l[i]] , val[r[j]] ) ; 

        ans.push_back( { {l[i], r[j]} , mn } ); 
        val[l[i]] += mn; 
        val[r[j]] -= mn; 
    }


    cout << ans.size() << endl; 
    for(auto x : ans) 
        cout << x.F.F+1 << " " << x.F.S+1 << " " << x.S << '\n';
}