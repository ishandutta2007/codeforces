
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 5, M = 1e9 + 7;
int t, n, m, u, v;
ll c[N];
vector<int> adj[N];
ll pow2[N], h[N];
unordered_map<int, ll> mm;

ll mod(ll a) {
    return ((a % M) + M) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    pow2[0] = 1;
    for(int i = 1; i < N; i++) {
        pow2[i] = mod(2 * pow2[i - 1]);
    }
    while(t--) {
        cin >> n >> m;
        mm.clear();
        for(int i = 0; i < n; i++) {
            cin >> c[i];
            adj[i].clear();
            h[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            h[v - 1] += pow2[u - 1];
        }
        for(int i = 0; i < n; i++) {
            if(h[i] != 0) mm[h[i]] += c[i];
        }
        ll g = 0;
        for(auto p : mm) {
            g = gcd(g, p.second);
        }
        cout << g << "\n";
    }
}