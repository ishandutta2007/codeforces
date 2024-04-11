#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 505;

int n;
int a[N];

void read() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
}

void gen() {
    n = 10;
    for(int i = 0;i < n;i++) {
        a[i] = rand() % 1000000 + 1;
    }
}

ll fast() {
    ll s = 0;

    for(int i = 0;i < n;i++) {
        s += a[i];
    }

    int const SQRT = 50000;

    ll res = s;

    for(int h = 1;h <= SQRT;h++) {
        int ok = 1;
        ll tot = 0;
        for(int i = 0;i < n;i++) {
            if(a[i] % (h+1) == 0) {
                tot += a[i] / (h+1);
            }else if(a[i]/h >= a[i]%h) {
                tot += a[i] / (h + 1) + 1;
            }else {
                ok = 0;
                break;
            }
        }
        if(ok) {
            res = min(res, tot);
        }
    }

    for(int c = 1;c <= SQRT && c <= a[0];c++) {
        {
            ll hl = max(1, (a[0] - 1) / c );
            ll hr = min(a[0], a[0] / c);
            for(ll h = hl;h <= hr;h++) {
                int ok = 1;
                ll tot = 0;
                for(int i = 0;i < n;i++) {
                    if(a[i] % (h+1) == 0) {
                        tot += a[i] / (h+1);
                    }else if(a[i]/h >= a[i]%h) {
                        tot += a[i] / (h + 1) + 1;
                    }else {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    res = min(res, tot);
                }
            }
        }
    }
    return res;
}

int main() {

    read();

    cout << fast() << "\n";

    return 0;
}