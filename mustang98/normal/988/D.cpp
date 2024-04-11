#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

set<ll> s;
vector<ll> v;
int n;

void check3() {
    for (ll pow2 = 1; pow2 < 1LL * 4 * inf; pow2 *= 2) {
        for (int i = 0; i < n; ++i) {
            ll cur = v[i];
            if (s.count(cur + pow2) && s.count(cur + pow2 + pow2)) {
                cout << 3 << endl;
                cout << cur << ' ' << cur + pow2 << ' ' << cur + pow2 * 2 << endl;
                exit(0);
            }
        }
    }
}

void check2() {
    for (ll pow2 = 1; pow2 < 1LL * 4 * inf; pow2 *= 2) {
        for (int i = 0; i < n; ++i) {
            ll cur = v[i];
            if (s.count(cur + pow2)) {
                cout << 2 << endl;
                cout << cur << ' ' << cur + pow2 << endl;
                exit(0);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        s.insert(a);
        v.PB(a);
    }
    check3();
    check2();
    cout << 1 << endl;
    cout << v[0];
    return 0;
}