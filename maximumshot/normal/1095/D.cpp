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

    int n;

    cin >> n;

    vector< pii > a(n);

    for(pii & p : a) {
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
    }

    vector< int > p;

    {
        int x = 0;
        int y = a[0].first;
        int z = a[0].second;
        if(a[y].first == z || a[y].second == z) {}
        else swap(y, z);
        p.push_back(x);
        p.push_back(y);
        p.push_back(z);
    }

    while((int)p.size() < n) {
        int x = p[(int)p.size() - 2];
        int y = p[(int)p.size() - 1];
        int z = a[x].first == y ? a[x].second : a[x].first;
        p.push_back(z);
    }

    for(int x : p) {
        cout << x + 1 << " ";
    }

    cout << "\n";

    return 0;
}