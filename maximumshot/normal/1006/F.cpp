#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 25;

int n, m;
ll k;
ll a[N][N];
unordered_map< ll, ll > mem[N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }

    int T = n + m - 2;
    int t1 = T / 2;
    int t2 = T - t1;

    for(int mask = 0;mask < (1 << t1);mask++) {
        int i = 0;
        int j = 0;
        ll xr = a[0][0];
        int ok = 1;
        for(int it = 0;it < t1;it++) {
            if((mask >> it) & 1) {
                j++;
            }else {
                i++;
            }
            if(i >= n || j >= m) { ok = 0; break; }
            xr ^= a[i][j];
        }
        if(!ok) continue;
        mem[i][j][xr]++;
    }

    ll result = 0;

    for(int mask = 0;mask < (1 << t2);mask++) {
        int i = n - 1;
        int j = m - 1;
        ll xr = a[n - 1][m - 1];
        int ok = 1;
        for(int it = 0;it < t2;it++) {
            if((mask >> it) & 1) {
                j--;
            }else {
                i--;
            }
            if(i < 0 || j < 0) { ok = 0; break; }
            xr ^= a[i][j];
        }
        if(!ok) continue;
        ll need = k ^ xr ^ a[i][j];
        auto fnd = mem[i][j].find(need);
        if(fnd != mem[i][j].end()) result += fnd->second;
    }

    cout << result << "\n";

    return 0;
}