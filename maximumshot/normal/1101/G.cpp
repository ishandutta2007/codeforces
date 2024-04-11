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

const int N = 2e5 + 5;

int n;
int a[N];

int f(int x) {
    return 1 << __lg(x);
}

void add(vector< int > & a, int x) {
    if(!x) return;
    for(int v : a) {
        if(f(v) & x) x ^= v;
    }
    if(!x) return;
    for(int &v : a) {
        if(f(x) & v) v ^= x;
    }
    a.push_back(x);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    if(!a[n]) {
        cout << "-1\n";
        return 0;
    }

    vector< int > basis;

    for(int i = 1;i <= n;i++) {
        add(basis, a[i]);
    }

    cout << (int)basis.size() << "\n";

    return 0;
}