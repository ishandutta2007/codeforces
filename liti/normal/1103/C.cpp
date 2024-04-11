//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 3 * 100 * 1000;

vector<int> c[N];
int mark[N]; 
int p[N]; 
int h[N]; 
bool leaf[N]; 

int n, m, k;

void dfs(int s) { 
    mark[s] = true;
    if( h[s] >= (n+k-1) / k ) { 
        cout << "PATH" << endl;
        cout << h[s] + 1 << endl;
        do { 
            cout << s + 1 << ' ';
            s = p[s];
        } while( s != -1 );
        cout << endl;
        throw(0);
    }

    for(auto x: c[s]) 
        if( !mark[x] ) { 
            p[x] = s;
            h[x] = h[s] + 1;
            dfs(x); 
            leaf[s] = false;
        }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 

    cin >> n >> m >> k; 

    for(int i= 0; i < m; i++) { 
        int u, v;
        cin >> u >> v;
        u--; v--; 
        c[u].push_back(v);  
        c[v].push_back(u); 
    }

    fill(leaf, leaf + n, true);
    p[0] = -1;
    try {
        dfs(0); 
    } catch(int v) {
        return 0; 
    }

    cout << "CYCLES" << endl;
    int cnt = 0; 
    for(int i = 0; i < n && cnt < k; i++) 
        if( leaf[i] ) { 
            try { 
                for(auto x : c[i]) {
                    int d = h[i] - h[x] + 1;
                    if( d % 3 != 0 && d > 3 ) { 
                        cout << d << '\n';
                        int s = i; 
                        while( true ) { 
                            cout << s + 1 << ' ';
                            if( s == x ) break;
                            s = p[s];
                        }
                        cout << '\n';
                        throw(1);
                    }
                }
                for(int x = 0; x < 2; x++)
                    for(int y = x+1; y < 3; y++) {
                        int u = c[i][x];
                        int v = c[i][y]; 
                        if( u != p[i] && v != p[i] ) {
                            if( h[u] > h[v] ) swap(u, v);
                            int d = 2 + h[v] - h[u]; 
                            assert( d > 3 && d % 3 != 0 ); 

                            cout << d << '\n';
                            cout << i + 1 << ' ';

                            while(true) { 
                                cout << v + 1 << ' ';
                                if( v == u ) break;
                                v = p[v]; 
                            }
                            cout << '\n';
                            throw(1);
                        }
                    }
            } catch(int v) { 
                cnt++;
                continue;
            }
        }

    return 0;
}