#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;

    cin >> n >> s;

    vector< int > a(n + 1), b(n + 1);
    vector< vector< int > > g(n + 1);

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }

    vector< int > used(n + 1);
    queue< int > q;

    q.push(1);
    used[1] = 1;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if(a[v]) {
            for(int to = v + 1;to <= n;to++) {
                if(!a[to]) continue;
                if(!used[to]) {
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
        if(b[v]) {
            for(int to = 1;to < v;to++) {
                if(!b[to]) continue;
                if(!used[to]) {
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    cout << (used[s] ? "YES" : "NO") << "\n";

    return 0;
}