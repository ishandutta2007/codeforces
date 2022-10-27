#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = int64_t;
int n, nq;
ll a[nax];
ll dif[nax];

ll get_ans(ll x, ll y) {
    y -= x;
    x = 0;
    ll res = y / 2;
    return max(y - res, res);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    cin >> nq;

    for (int i = 1 ; i < n ; ++ i)
        dif[i] = a[i + 1] - a[i];
    ll x = a[1], y = 0;

    for (int i = 1 ; i < n ; ++ i) {
        if (dif[i] <= 0) {
            y += dif[i];
        } else x += dif[i];
    }

    cout << get_ans(0, x) << '\n';
    ll z = 0;
    while (nq --) {
        int l, r, add;
        cin >> l >> r >> add;
        int old_l = l;
        /**
            calm down a bit; try to summarize this stupid solution
            answer = a[1] + all positive value
            keep track value of a[1]
            get_ans(x, 0)
        */
        if (l == 1) {
            x += add;
        }

        if (l != 1) {
            -- l;
            if (dif[l] >= 0) x -= dif[l];
            dif[l] += add;
            if (dif[l] >= 0) x += dif[l];
        }
        if (r != n) {
            if (dif[r] >= 0) x -= dif[r];
            dif[r] -= add;
            if (dif[r] >= 0) x += dif[r];
        }
        cout << get_ans(0, x) << '\n';
    }


}