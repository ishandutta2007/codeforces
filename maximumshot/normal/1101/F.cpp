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

const int N = 3e5 + 5;

int n, m;
int a[N];
vector< vector< int > > dp[405];

struct Truck {
    int s, f, c, r;
} b[N];

bool check(ll V) {
    for(int i = 1;i <= m;i++) {
//        cout << dp[ b[i].s ][ b[i].f - b[i].s ][ b[i].r ] << " " << V / b[i].c << " ?\n";
        if(dp[ b[i].s ][ b[i].f - b[i].s ][  min(b[i].r, b[i].f - b[i].s) ] > V / b[i].c) {
            return 0;
        }
    }
    return 1;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for(int i = 1;i <= m;i++) {
        cin >> b[i].s >> b[i].f >> b[i].c >> b[i].r;
        b[i].r++;
    }

    for(int i = 1;i <= n;i++) {
        dp[i].resize(n - i + 1, vector< int >(0));
        for(int di = 0;i + di <= n;di++) {
            dp[i][di].resize(di + 1, inf);
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int di = 0;i + di <= n;di++) {
            int j = i + di;
            for(int st = i != j;st <= di;st++) {
                if(!st) {
                    dp[i][di][st] = 0;
                    continue;
                }
                for(int qj = j;qj >= i;qj--) {
                    dp[i][di][st] = min(dp[i][di][st], max(dp[i][qj - i][st - 1], a[j] - a[qj]));
                    if(dp[i][qj - i][st - 1] < a[j] - a[qj]) break;
                }
            }
        }
    }

    ll bl = -1;
    ll br = inf64 + 10;
    ll bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    cout << br << "\n";

    return 0;
}