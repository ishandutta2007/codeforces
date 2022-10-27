#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10;
using ll = long long;
ll const inf = 1e18;

int n;
ll x;
ll a[nax];

struct segtree {
    static const int Mx = 4 * nax;

    ll sg[Mx] = {}, tag[Mx] = {};

    inline void pull (int v) {
        sg[v] = min(sg[v * 2], sg[v * 2 + 1]);
    }

    inline void push (int v) {
        if (v * 2 + 1 < Mx && tag[v]) {
            sg[v * 2] +=  tag[v];
            sg[v * 2 + 1] += tag[v];
            tag[v * 2] +=  tag[v];
            tag[v * 2 + 1] += tag[v];
        }
        tag[v] = 0;
    }

    inline void update (int v, int x, int y, int l, int r , ll val) {
        push(v);
        if (l > r) return ;

        if (l == x && r == y) {
            sg[v] += val; tag[v] += val;
            return push(v);
        }

        int mid = x + y >> 1;
        update(v * 2, x , mid, l, min(r, mid), val);
        update(v * 2 + 1, mid + 1, y, max(l, mid + 1), r, val);
        pull(v);
    }

    inline ll query (int v, int x, int y, int l, int r) {
        push(v);
        if (l > r) return INT_MAX;

        if (l == x && r == y) {
            return sg[v];
        }

        int mid = x + y >> 1;

        return min(query(v << 1 , x , mid, l, min(r, mid)), query(v * 2 + 1, mid + 1, y, max(l, mid + 1), r));
    }

};

ll s[nax];


int main () {

    scanf("%d", &n);

    ll all_sum = 0;

    for (int i = 1 ; i <= (n + 1) / 2 ; ++ i) {
        scanf("%lld", &a[i]);
        all_sum += a[i];
        s[i] = all_sum;
    }



    scanf("%lld", &x);

    for (int i = (n + 1) / 2  + 1 ; i <= n ; ++ i) {
        s[i] = s[i - 1] + x;
    }

    all_sum += x * (n / 2);

    if (x >= 0) {
        if (all_sum <= 0) return !printf("-1");
        else return !printf("%d\n", n);
    }

    segtree sg;

    if (all_sum > 0) return !printf("%d\n", n);


    sg.update(1, 1, n, 1, 1, all_sum);



    for (int j = 2 ; j <= (n + 1) / 2 ; ++ j) {
        sg.update(1, 1, n, 1, j - 1, -x);
        sg.update(1, 1, n, j, j, s[n ] - s[j - 1]);




        if (sg.query(1, 1, n, 1, j) > 0) {
            return !printf("%d\n", n - j + 1);
        }
    }

    return !printf("-1");

}
/*
    Long time no see...
        CF round
*/