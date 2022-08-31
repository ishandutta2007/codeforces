#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

struct t{
    int c1, c2, c3, c4;
    t(int aa, int bb, int cc, int dd) {
        c1 = aa;
        c2 = bb;
        c3 = cc;
        c4 = dd;
    }

    bool operator==(const t& o){
        if (o.c1 && c1) return 0;
        if (o.c2 && c2) return 0;
        if (o.c3 && c3) return 0;
        if (o.c4 && c4) return 0;
        ll ans1 = c1 + c2 * 5 + c3 * 10 + c4 * 50;
        ll ans2 = o.c1 + o.c2 * 5 + o.c3 * 10 + o.c4 * 50;
        int g = __gcd(c1, c2);
        g = __gcd(g, c3);
        g = __gcd(g, c4);
        g = __gcd(g, o.c1);
        g = __gcd(g, o.c2);
        g = __gcd(g, o.c3);
        g = __gcd(g, o.c4);
        if (g > 1) return 0;
        return ans1 == ans2;
    }

    void print() {
        cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << endl;
    }
};

ll dumb(ll n) {
    set<ll> s;
    if (n < 100) {
        ll cnt = 0;
        int cntb = 0;
        for (ll c1 = 0; c1 <= n; ++c1) {
            for (ll c2 = 0; c2 <= (n - c1); ++c2) {
                for (ll c3 = 0; c3 <= (n - c1 - c2); ++c3) {
                    ll c4 = n - c1 - c2 - c3;
                    ll ans = c1 + c2 * 5 + c3 * 10 + c4 * 50;
                    ++cnt;
                    s.insert(ans);
                }
            }

        }
        return s.size();
    }
    /*for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i] == v[j]) {
                v[i].print();
                v[j].print();
                cout << endl;
            }
        }
    }*/
    ll ans = 0;
    for (ll c2 = 0; c2 <= 20; ++c2) {
        for (ll c3 = 0; c3 <= 20; ++c3) {
            if (c2 >= 9 || c3 >= 9 || (c2 >= 1 && c3 >= 5)) continue;
            ans += (n + 1 - c2 - c3);
        }
    }

    return ans;
    //cout << cnt - s.size() << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cout << dumb(n);
    //return 0;

    return 0;
}