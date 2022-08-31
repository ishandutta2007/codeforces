#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<ll, char> pc;

int main()
{
    int n;
    cin >> n;
    ll mx = 10000000000;
    ll bl = mx, al = mx, pl = mx;
    ll br = -mx, ar = -mx, pr = -mx;
    vector<pi> p;
    vector<pc> m;
    for (int i = 0; i < n; i++) {
        ll x;
        char c;
        cin >> x >> c;
        m.push_back({x, c});
        if (c == 'P') {
            p.push_back({x, i});
            pl = min(pl, x);
            pr = max(pr, x);
        }
        if (c == 'B') {
            bl = min(bl, x);
            br = max(br, x);
        }
        if (c == 'R') {
            al = min(al, x);
            ar = max(ar, x);
        }
    }
    if (pl == mx) {
        if (al == mx) {
            cout << br - bl;
        }
        else if (bl == mx) {
            cout << ar - al;
        }
        else {
            cout << ar + br - al - bl;
        }
    }
    else {
        ll ans = pr - pl;
        if (al < pl) {
            ans += pl - al;
        }
        if (bl < pl) {
            ans += pl - bl;
        }
        if (ar > pr) {
            ans += ar - pr;
        }
        if (br > pr) {
            ans += br - pr;
        }
        for (int i = 0; i < p.size() - 1; i++) {
            ll la = p[i].second;
            ll lb = p[i].second;
            ll mna = mx, mnb = mx;
            for (int j = p[i].second; j < p[i + 1].second + 1; j++) {
                if (m[j].second == 'R' || m[j].second == 'P') {
                    mna = min(mna, p[i + 1].first - m[j].first + m[la].first - p[i].first);
                    la = j;
                }
                if (m[j].second == 'B' || m[j].second == 'P') {
                    mnb = min(mnb, p[i + 1].first - m[j].first + m[lb].first - p[i].first);
                    lb = j;
                }
            }
            if (mna < p[i + 1].first - p[i].first) {
                ans += mna;
            }
            if (mnb < p[i + 1].first - p[i].first) {
                ans += mnb;
            }
            if (mna + mnb > p[i + 1].first - p[i].first) {
                ans += p[i + 1].first - p[i].first - mna - mnb;
            }
        }
        cout << ans;
    }
}