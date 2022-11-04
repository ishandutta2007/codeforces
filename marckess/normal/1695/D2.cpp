// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#include <bits/stdc++.h>

const int MX = 200005;
int n, r, res, vis[MX];
vvi adj;

int dfs (int u) {
    int c = 0, n = 0, f = 0, d, e = 0, cv, ev;
    vis[u] = 1;

    for (int v : adj[u]) {
        if (vis[v])
            continue;
        n++;

        d = dfs(v);
        f |= d;
        if (d & 1) {
            c++;
            cv = v;
        }
        if (d & 2) {
            e++;
            ev = v;
        }
    }

    n--;
    if (n > c) {
        res += n - c;
        c += n - c;
    }
    
    if ((f & 2) && (c >= 2 || (c == 1 && (e > 1 || cv != ev))))
        f ^= 2;
        
    if (n < adj[u].size() - 1)
        f |= 2;
    
    if (n > 0)
        f |= 1;

    return f;
}

void main_() {
	cin >> n;
    adj = vvi(n + 1);

    forn (i, n - 1) {
    	int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    r = 1;
    forr (i, 1, n) {
		if (adj[i].size() > 2)
			r = i;
		vis[i] = 0;
	}

	res = 0;
    if (dfs(r) & 2)
        res++;
    cout << max(res, int(n > 1)) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}