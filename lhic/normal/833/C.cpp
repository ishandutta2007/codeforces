#pragma GCC optimize "-O3"
#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int flr = 0;

int get(int x, int l, int r) {
    if (l > r)
        return 0;
    return (x & ((1 << (r + 1)) - 1)) >> l;
}

int al[20];
int ar[20];
int cc[10];
int cc2[10];
int ans;


void run(int x, int lf) {
    if (x == 10) {
        if (lf)
            return;
        memcpy(cc, cc2, sizeof(cc));
        if (cc[0] == 17 && cc[1] == 1 && flr) {
            ++ans;
            return;
        }
        int cur = 0;
        for (int i = 0; i < 10; ++i)
            if (cc[i])
                cur += (1 << i);
        int fl = 0;
        int fl1 = 0;
        for (int i = 17; i >= 0; --i) {
            if (fl1) {
                if (get(cur, al[i] + 1, 9)) {
                    ++ans;
                    return;
                }
            }
            else if (get(cur, al[i] + 1, ar[i] - 1)) {
                ++ans;
                return;
            }
            if (!cc[al[i]]) {
                fl = 1;
                break;
            }
            --cc[al[i]];
            if (!cc[al[i]])
                cur -= (1 << al[i]);
            if (al[i] != ar[i])
                fl1 = 1;
        }
        if (!fl) {
            ++ans;
            return;
        }
        memcpy(cc, cc2, sizeof(cc));
        cur = 0;
        for (int i = 0; i < 10; ++i)
            if (cc[i])
                cur += (1 << i);
        fl = 0;
        fl1 = 0;
        for (int i = 17; i >= 0; --i) {
            if (fl1) {
                if (get(cur, 0, ar[i] - 1)) {
                    ++ans;
                    return;
                }
            }
            if (!cc[ar[i]]) {
                fl = 1;
                break;
            }
            --cc[ar[i]];
            if (!cc[ar[i]])
                cur -= (1 << ar[i]);
            if (al[i] != ar[i])
                fl1 = 1;
        }
        if (!fl) {
            ++ans;
            return;
        }
        return;
    }
    for (int j = 0; j <= lf; ++j) {
        cc2[x] = j;
        run(x + 1, lf - j);
    }
}

int main() {
    ll l, r;
    cin >> l >> r;
    if (l == r) { 
        cout << 1 << "\n";
        return 0;
    }
    if (r == 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll)
        --r, flr = 1;
    for (int i = 0; i < 18; ++i) {
        al[i] = l % 10;
        ar[i] = r % 10;
        l /= 10;
        r /= 10;
    }
    run(0, 18);
    cout << ans << "\n";
    return 0;
}