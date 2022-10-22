#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll Sum(ll x, ll y) {
    return min(inf64, x + y);
}

ll Mul(ll x, ll y) {
    ld res = (ld)x * y;
    if(res > 2e18 + 100) {
        return inf64;
    }else {
        return min(inf64, x * y);
    }
}

vec< ll > p(vec< ll > a) {
    vec< ll > b(a.size());
    ll cur = 0;
    for(int i = 0;i < (int)a.size();i++) {
        cur = Sum(cur, a[i]);
        b[i] = cur;
    }
    return b;
}

ll f(ll i, ll x, ll y, ll z) {
    ll tmp = i % 2 ? Mul(i, (i + 1) / 2) : Mul(i / 2, i + 1);
    tmp = Mul(tmp, x);
    tmp = Sum(tmp, Sum(Mul(i, y), z));
    return tmp;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    int n;
    ll k;

    cin >> n >> k;

    vec< ll > a(n);

    int cnt = 0;
    int le = inf;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(a[i] > 0) {
            le = min(le, i);
            cnt++;
        }
    }

    if(*max_element(ALL(a)) >= k) {
        cout << "0\n";
        return 0;
    }

    if(n - le >= 4) {
        reverse(ALL(a));
        while(a.back() == 0) a.pop_back();
        reverse(ALL(a));
        n = (int)a.size();
        for(int i = 0;;i++) {
            ll mx = i == 0 ? *max_element(ALL(a)) : a.back();
            if(mx >= k) {
                cout << i << "\n";
                break;
            }
            a = p(a);
        }
    }else {
        if(n - le == 3) {
            ll x = a[n - 3];
            ll y = a[n - 2];
            ll z = a[n - 1];
            ll bl = 0;
            ll br = inf64;
            ll bm;
            while(br - bl > 1) {
                bm = (bl + br) / 2;
                if(f(bm, x, y, z) >= k) {
                    br = bm;
                }else {
                    bl = bm + 1;
                }
            }
            if(bl < br && f(bl, x, y, z) >= k) {
                cout << bl << "\n";
            }else {
                cout << br << "\n";
            }
        }else {
            ll x = a[n - 2];
            ll y = a[n - 1];
            ll i = (k - y + x - 1) / x;
            cout << i << "\n";
        }
    }

    return 0;
}