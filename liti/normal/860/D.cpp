//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 2000 * 100 + 100; 
typedef pair<int,int> pii; 

vector<pii> c[maxN]; 
bool mark[maxN]; 
bool used[maxN];
int arr[maxN], ind; 
int st[maxN];

struct Ans { 
    int x, y, z; 
};

void dfs(int s) { 
    mark[s] = true;
    st[s] = ind;
    arr[ind++] = s; 
    for( auto x : c[s] ) 
        if( !mark[x.first] ) 
            dfs(x.first); 
}

vector<Ans> ans;

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) { 
        int u, v; 
        cin >> u >> v;
        u--; v--; 
        c[u].push_back( {v,i} ); 
        c[v].push_back( {u,i} ); 
    }

    for (int i = 0; i < n; i++) 
        if( !mark[i] ) 
            dfs(i);

    reverse(arr, arr+n); 
    for( int t = 0; t < n; t++ ) { 
        int s = arr[t]; 
        sort( c[s].begin() , c[s].end() , [](pii a, pii b) { 
                return st[a.first] > st[b.first]; 
                }
            );
        pii last(-1,-1);
        for( auto x : c[s] ) 
            if( !used[x.second] ) { 
                if( last.first == -1 ) 
                    last = x;
                else { 
                    ans.push_back( {last.first+1,s+1,x.first+1} );
                    used[last.second] = true;
                    used[x.second] = true;
                    last = pii(-1,-1);
                }
            }
    }

    cout << ans.size() << '\n';
    for( auto x : ans ) 
        cout << x.x << " " << x.y << " " << x.z << '\n';
}