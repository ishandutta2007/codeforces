#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

void solve(){
    long long n, l, r, b1,b2;
    unsigned int x, y, z;
    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    vector<unsigned int> b(n);
    b[0] = b1, b[1] = b2;
    for(int i = 2; i < n; i++){
        b[i] = (b[i - 2] * x + b[i - 1] * y + z);
    }
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        a[i] = (b[i] % (r - l + 1)) + l;
    }
    const ll INF = 4e18 + 7;
    long long ans = INF;
    ll mn = INF;
    for(int i = 0; i < n; i++){
        if(a[i] > mn)
            ans = min(ans, mn * a[i]);
        mn = min(mn, a[i]);
    }
    ll mx = -INF;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] < mx)
            ans = min(ans, mx * a[i]);
        mx = max(mx, a[i]);
    }

    if(ans == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << '\n';
    return;
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif
    int test;
    cin >> test;
    while(test--) solve();

    return 0;
}