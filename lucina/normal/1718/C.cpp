#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;


int n, nq;
int64_t a[nax];
int64_t b[nax];
int64_t ans[nax];
int64_t s[nax];
array <int64_t, 2> q[nax];
bool vis[nax];

void solve() {
    cin >> n >> nq;
    vector <int> divisors;
    fill(vis + 1, vis + 1 + n, false);

    vector <int> fnd;
    for (int i = n - 1 ; i >= 1 ; -- i) {
        if (n % i) continue;
        bool ok = true;
        for (int j : divisors)
            if (j % i == 0) {
                ok = false;
                break;
            }
        if (ok) divisors.push_back(i);
    }
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
        b[i] = a[i];
    }
    ans[0] = 0;

    for (int i = 1 ; i <= nq ; ++ i) {
        cin >> q[i][0] >> q[i][1];
        ans[i] = 0;
        -- q[i][0];
    }

    /**
        if we can't manage to brute force all divisors?

    */

    for (int d : divisors) {
        copy(b, b + n, a);

        fill(s, s + d, 0);

        for (int i = 0 ; i < n ; ++ i) {
            s[i % d] += a[i];
        }
        multiset <int64_t> setik;
        for (int i = 0 ; i < d ; ++ i)
            setik.insert(s[i]);

        ans[0] = max(ans[0], *setik.rbegin() * d);

        for (int i = 1 ; i <= nq ; ++ i) {
            auto [pos, val] = q[i];
            setik.erase(setik.find(s[pos % d]));
            s[pos % d] = s[pos % d] - a[pos] + val;
            setik.insert(s[pos % d]);
            a[pos] = val;
            ans[i] = max(ans[i], *setik.rbegin() * d);
        }
    }
    for (int i = 0 ; i <= nq ; ++ i) {
        cout << ans[i] << '\n';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    GL div.1
*/