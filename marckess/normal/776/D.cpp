#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int n, m, a, b, x, u;
bitset<200005> bs;
vector<vi> edge(200005);
vector<vii> adj(200005);
vi color(200005, -1);

bool colorear (int i) {
    for (int j = 0; j < adj[i].size(); j++) {
        tie(u, x) = adj[i][j];
        
        if (color[u] != -1) {
            if ( x == 1 && color[u] != color[i] ) {
                return false;
            }
            if ( x == 0 && color[u] == color[i] ) {
                return false;
            }
        } else {
            if ( x == 1 ){
                color[u] = color[i];
            } else{
                color[u] = color[i] == 1 ? 0 : 1;
            }
            if ( !colorear(u) ){
                return false;
            }
        }
    }
    return true;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> x;
        bs[i] = x;
    }

    for (int i = 1; i <= m; i++) {
        cin >> x;
        while (x--) {
            cin >> a;
            edge[a].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        adj[ edge[i][0] ].emplace_back( edge[i][1], bs[i] );
        adj[ edge[i][1] ].emplace_back( edge[i][0], bs[i] );
    }
    
    bool res = true;
    for (int i = 1; i <= m && res; i++) {
        if ( color[i] == -1 ) {
            color[i] = 0;
            res &= colorear(i);
        }
    }

    cout << (res ? "YES" : "NO") << endl;
    
    return 0;
}