#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n;
int a[N];
int b[N];
int sz;

ll gcd(ll x, ll y) {
    return x == 0 ? y : gcd(y % x, x);
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++) {
        ll tmp, x;
        x = a[i];
        tmp = gcd(x, a[1]);
        x /= tmp;
        tmp = gcd(x, a[2]);
        x /= tmp;
        tmp = gcd(x, a[3]);
        x /= tmp;
        if(x == 1) {
            b[sz++] = a[i];
        }
    }

    ll res = 0;

    map< ll, ll > cn;
    map< ll, ll > have;

    ll tmp, A, B, C, x;
    for(int i = 0;i < sz;i++) {
        A = a[1];
        B = a[2];
        C = a[3];
        x = b[i];
        tmp = gcd(x, A);
        x /= tmp;
        A /= tmp;
        tmp = gcd(x, B);
        x /= tmp;
        B /= tmp;
        tmp = gcd(x, C);
        x /= tmp;
        C /= tmp;
        if((double)A * (double)B * (double)C > 1e18 + 100) {}
        else {
            ll need = A * B * C;
            res += cn[need];
        }
        for(pair< ll, ll > iter : have) {
            cn[iter.first * (ll)b[i]] += iter.second;
        }
        have[b[i]]++;
    }

    cout << res << "\n";

    return 0;
}