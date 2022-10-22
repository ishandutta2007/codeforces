#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll tot = 0, res = 0;

ll get_cnt(ll n) {
    if(n <= 1) return 1;
    return get_cnt(n / 2) * 2 + 1;
}

void get(ll n, ll l, ll r) {
    if(tot > r) return;
//    cout << n << " : " << tot << "\n";
    if(n == 0) {
        tot++;
        if(tot > r) return;
    }else if(n == 1) {
        tot++;
        if(tot > r) return;
        if(tot >= l) res++;
    }else {
        ll add = get_cnt(n / 2);
//        cout << "add = " << add << "\n";
        // 1 .. add
        if(l <= tot + add) {
//            cout << "left\n";
//            cout << n << " -> " << n / 2 << "\n";
            get(n / 2, l, r);
        }else {
//            cout << "no left";
            tot += add;
        }
        tot++;
        if(tot >= l && tot <= r && n % 2) res++;
//        cout << n << " -> " << n / 2 << "\n";
        get(n / 2, l, r);
    }
}

int main() {

    ll n, l, r;

    cin >> n >> l >> r;

    get(n, l, r);

    cout << res << "\n";

    return 0;
}