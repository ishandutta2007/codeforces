#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e3 + 5;

int n;
ll a[N][N];

ll f(ll x) {
    ll bl = 0;
    ll br = inf + 10;
    ll bm;
    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (bm * bm <= x) {
            bl = bm;
        } else {
            br = bm;
        }
    }
    return bl;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        ll A = a[i][j];
        ll B = a[i][k];
        ll C = a[j][k];
        ll x = A * B / C;
        cout << f(x) << " ";
    }

    cout << "\n";

    return 0;
}