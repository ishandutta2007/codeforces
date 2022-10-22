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

int n;
ll s;
int p[N];
int deg[N];
int height[N];

bool check(int d) {
    ll layout = 1;
    ll h = 1;
    ll total_sum = 1;
    ll cnt_vertex = 1;
    while(cnt_vertex < n) {
        if(cnt_vertex + layout * d <= n) {
            total_sum += (layout * d) * (h + 1);
            h++;
            cnt_vertex += layout * d;
            layout *= d;
        }else {
            ll rem = n - cnt_vertex;
            total_sum += rem * (h + 1);
            h++;
            cnt_vertex += rem;
            break;
        }
    }
    return total_sum <= s;
}

ll calc(int l, int cnt) {
    if(!cnt) return 0;
    int r = l + cnt - 1;
    return 1ll * (l + r) * (r - l + 1) / 2;
}

void print(int d) {
    int pv = 1;
    ll total_sum = 1;
    height[1] = 1;
    for(int v = 2;v <= n;v++) {
        while(deg[pv] == d || total_sum + calc(height[pv] + 1, n - v + 1) < s) pv++;
        p[v] = pv;
        deg[pv]++;
        height[v] = height[pv] + 1;
        total_sum += height[v];
    }
    cout << "Yes\n";
    for(int i = 2;i <= n;i++) {
        cout << p[i] << " ";
    }
    cout << "\n";

//    cout << "\n";
//    for(int v = 2;v <= n;v++) {
//        cout << p[v] << " " << v << "\n";
//    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    if(s < 2 * n - 1 || s > 1ll * n * (n + 1) / 2) {
        cout << "No\n";
        return 0;
    }

    int bl = 0;
    int br = inf;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    cerr << "br = " << br << "\n";

    print(br);

    return 0;
}