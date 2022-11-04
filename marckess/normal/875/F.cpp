#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 400005;
int n, m, a[MX], b[MX], w[MX], q[MX];
int p[MX], rk[MX], x[MX], y[MX];

int parent (int a) { return p[a] == a ? a : p[a] = parent(p[a]); }
void joint (int a, int b) {
    a = parent(a), b = parent(b);
    if (a == b) return;
    if (rk[a] < rk[b]) swap(a, b);
    
    p[b] = a;
    x[a] += x[b];
    y[a] += y[b];
    if (rk[a] == rk[b]) rk[a]++;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    iota(p, p+MX, 0);
      
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> w[i];
    
    iota(q, q+n, 0);
    sort(q, q+n, [&] (int i, int j) {
        return w[i] > w[j];
    });
    
    for (int i = 0; i < n; i++) x[i] = 1;
    for (int i = n; i <= n+m; i++) y[i] = 1;
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int u = parent(q[i]), e = x[u], d = y[u];
        
        forn(_,2) {
            int v = parent(a[q[i]]+n);
            if (u != v) e += x[v], d += y[v];
            swap(a[q[i]], b[q[i]]);
        }
        
        if (e <= d) {
            joint(u, a[q[i]]+n);
            joint(u, b[q[i]]+n);
            res += w[q[i]];
        }
    }
    
    cout << res << endl;
    
    return 0;
}