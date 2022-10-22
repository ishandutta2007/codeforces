#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    vec< ll > a(14), b;

    ll res = 0;

    for(int i = 0;i < 14;i++) {
        cin >> a[i];
    }

    for(int i = 0;i < 14;i++) {
        if(!a[i]) continue;
        ll al = a[i] / 14;
        int md = a[i] % 14;
        b = a;
        b[i] = 0;
        for(int j = 0;j < 14;j++) {
            b[j] += al;
        }
        for(int j = 0;j < md;j++) {
            b[(i + j + 1) % 14]++;
        }
        ll tmp = 0;
        for(int j = 0;j < 14;j++) {
            if(b[j] & 1) continue;
            tmp += b[j];
        }
        if(tmp > res) res = tmp;
    }

    cout << res << "\n";

    return 0;
}