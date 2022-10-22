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

const int N = 1e5 + 5;

int n, m, l;
int a[N];
int p[N], cc = 0;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    p[x] = y;
    return 1;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = min(a[i], l + 1);
        if(a[i] > l) cc++;
        p[i] = i;
    }

    for(int i = 1;i + 1 <= n;i++) {
        if(a[i] > l && a[i + 1] > l) {
            cc -= merge(i, i + 1);
        }
    }

    for(int iter = 0;iter < m;iter++) {
        int type;
        cin >> type;
        if(type == 0) {
            cout << cc << "\n";
        }else {
            int pos, val;
            cin >> pos >> val;
            if(a[pos] > l) continue;
            a[pos] += val;
            a[pos] = min(a[pos], l + 1);
            if(a[pos] > l) {
                cc++;
                if( pos > 1 && a[pos - 1] > l) cc -= merge(pos, pos - 1);
                if(pos < n && a[pos + 1] > l) cc -= merge(pos, pos + 1);
            }
        }
    }

    return 0;
}