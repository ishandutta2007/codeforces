#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

ll fast(string s, ll x, ll y) {
    if (x < y) {
        swap(x, y);
        for (char& c : s) {
            if (c != '?')
                c ^= '0' ^ '1';
        }
    }
    int n = (int) s.size();
    vector<int> p;
    ll c0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?')
            p.push_back(i);
        else if (s[i] == '0')
            c0++;
    }
    ll a = 0;
    for (int cur = 0, i = 0; i < n; i++) {
        if (s[i] == '0')
            cur++;
        else
            a += cur;
    }
    ll res = inf64;
    vector<ll> pref0(n), suff1(n);
    for (int i = 1; i < n; i++)
        pref0[i] = pref0[i - 1] + (s[i - 1] == '0');
    for (int i = n - 2; i >= 0; i--)
        suff1[i] = suff1[i + 1] + (s[i + 1] == '1');
    for (int it = (int) p.size(); it >= 0; it--) {
        res = min(res, a * (x - y) + c0 * (n - c0) * y);
        if (it > 0) {
            int i = p[it - 1];
            a -= pref0[i];
            a += suff1[i];
            c0++;
        }
    }
    return res;
}

void work() {
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    ll fs = fast(s, x, y);
    cout << fs << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}