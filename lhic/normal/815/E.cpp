#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}


map<ll, ll> mm;

pair<ll, ll> get(ll n, ll k) {
    mm.clear();
    mm[n] += 1;
    while (true) {
        auto it = mm.rbegin();
        ll x = it->first;
        ll c = it->second;
        if (x % 2 == 1) {
            if (c < k) {
                if (c != 0) {
                    k -= c;
                    ll l = (x - 1) / 2;
                    ll r = x / 2;
                    mm[l] += c;
                    mm[r] += c;
                }
                mm.erase(x);
            }
            else {
                return make_pair(x, k);
            }
        }
        else {
            ll c2 = mm[x - 1];
            if (c + c2 < k) {
                if (x == 2)
                    return make_pair(1, k);
                k -= c + c2;
                mm.erase(x);
                mm.erase(x - 1);
                ll l, r;
                if (c != 0) {
                    l = (x - 1) / 2;
                    r = x / 2;
                    mm[l] += c;
                    mm[r] += c;
                }
                if (c2 != 0) {
                    l = (x - 2) / 2;
                    r = (x - 1) / 2;
                    mm[l] += c2;
                    mm[r] += c2;
                }
            }
            else {
                return make_pair(x - 1, k);
            }
        }
    }
    assert(false);
    return make_pair(0, 0);
}
ll n, k;

ll get2(ll n, ll k) {
    mm.clear();
    mm[n] += 1;
    while (true) {
        auto it = mm.rbegin();
        ll x = it->first;
        ll c = it->second;
        if (x == k)
            return c;
        if (x == k + 1) {
            return c + mm[x - 1];
        }
        if (x < k)
            return 0;
        ll l = (x - 1) / 2;
        ll r = x / 2;
        mm[l] += c;
        mm[r] += c;
        mm.erase(x);
    }
    return 0;
}

ll get3(ll n, ll k) {
    if (n == 0)
        return 0;
    mm.clear();
    mm[n] += 1;
    while (true) {
        auto it = mm.rbegin();
        ll x = it->first;
        ll c = it->second;
        if (x == k)
            return c;
        if (x < k)
            return 0;
        ll l = (x - 1) / 2;
        ll r = x / 2;
        mm[l] += c;
        mm[r] += c;
        mm.erase(x);
    }
    return 0;
}

int main() {
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (k == 2) {
        cout << n << "\n";
        return 0;
    }
    n -= 2;
    k -= 2;
    pair<ll, ll> l = get(n, k);
    if (l.first == 1) {
        ll cur = n;
        ll lb = 2;
        ll rb = n + 1;
        while (cur != 1 && cur != 2) {
            ll nl = (cur - 1) / 2;
            ll c1 = get3(nl, 1);
            ll c2 = get3(nl, 2);
            if (c1 + c2 < l.second) {
                l.second -= c1 + c2;
                lb = (lb + rb) / 2 + 1;
                cur = cur / 2;
            }
            else {
                rb = (lb + rb) / 2 - 1;
                cur = nl;
            }
        }
        if (cur == 1) {
            cout << lb << "\n";
        }
        else {
            if (l.second == 1)
                cout << lb << "\n";
            else
                cout << lb + 1 << "\n";
        }
    }
    else {
        ll cur = n;
        ll lb = 2;
        ll rb = n + 1;
        while (cur != l.first && cur != l.first + 1) {
            ll nl = (cur - 1) / 2;
            ll c = get2(nl, l.first);
            if (c < l.second) {
                l.second -= c;
                lb = (lb + rb) / 2 + 1;
                cur = cur / 2;
            }
            else {
                rb = (lb + rb) / 2 - 1;
                cur = nl;
            }
        }
        cout << (lb + rb) / 2 << "\n";
    }
    return 0;
}