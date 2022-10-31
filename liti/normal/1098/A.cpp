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

const int N = 1000 * 100 + 100;

vector<int> c[N]; 
int v[N];
int a[N];

void dfs(int s, int mn) { 
    if( v[s] == -1 ) {
        int mx = 1.5e9; 
        for(auto x: c[s]) { 
            if( v[x] < mn ) throw(1);
            mx = min( mx , v[x] - mn ); 
        }
        if( mx > 1.3e9 ) { 
            a[s] = 0; 
            return;
        }
        a[s] = mx;
        for(auto x: c[s]) { 
            a[x] = v[x] - mn - mx;
            dfs(x, -1); 
        }
    } else {
        for(auto x: c[s]) 
            dfs(x, v[s]);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 
    int n;
    cin >> n; 

    for(int i = 1; i < n; i++) { 
        int p;
        cin >> p;
        p--;
        c[p].push_back(i); 
    }

    for(int i = 0; i < n; i++) 
        cin >> v[i];

    try { 
        a[0] = v[0];
        dfs(0, 0); 
    } catch(int v) { 
        cout << -1 << endl;
        return 0;
    }

    ll sum = 0; 
    for(int i = 0; i < n; i++)
        sum += a[i];
    cout << sum << endl;

    return 0;
}