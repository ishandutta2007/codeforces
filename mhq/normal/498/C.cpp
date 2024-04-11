#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int x1[110];
int y1[110];
int l1[150];
int r1[150];
int b[33000];
set < int > pr;
bool used[33000];
int par[33000];
vector < int > g[33000];
bool kun (int v) {
    if (used[v] == 1) return false;
    used[v] = true;
    for ( int j = 0; j < g[v].size(); j++) {
        int to = g[v][j];
        if ( par[to] == 0 || kun(par[to])) {
            par[to] = v;
            return true;
        }
    }
    return false;
}
int main()
{   ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int vert = 1;
    for ( int i = 1; i <= n; i++) {
        cin >> a[i];
        l1[i] = vert;
        for ( int j = 2; j * j <= a[i]; j++) {
            while (a[i] % j == 0) {
            a[i] = a[i] / j;
            b[vert] = j;
            vert++;
            }
        }
        if ( a[i] != 1) {
            b[vert] = a[i];
            vert++;
        }
        r1[i] = vert - 1;
    }
    int A, B;
    for ( int j = 1; j <= m; j++) {
        cin >> A >> B;
        if ( A % 2 != 0) {
            swap(A, B);
        }
        for ( int t = l1[A]; t <= r1[A]; t++) {
            for ( int it = l1[B]; it <= r1[B]; it++) {
                if (b[t] == b[it]) g[t].push_back(it);
            }
        }
    }
    for ( int i = 1; i <= vert; i++) {
        for ( int j = 1; j <= vert; j++) {
            used[j] = false;
        }
        kun(i);
    }
    int ans = 0;
    for ( int i = 1; i <= vert; i++) {
        if ( par[i] != 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}