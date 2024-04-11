#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[15];

bool is_arith_progression () {
    ll * c = new ll[3];
    for (int i = 0 ; i < 3 ; ++ i)
        c[i] = a[i];
    sort(c, c + 3);
    return (c[1] - c[0]) == (c[2] - c[1]);
}

bool valid_dif () {
    ll * d = new ll[3];
    for (int i = 0 ; i < 3 ; ++ i)
        d[i] = a[i];
    sort(d, d + 3);
    ll b = d[1] - d[0];
    ll c = d[2] - d[1];
    return b >= c;
}

bool valid_parity () {
    return !((*max_element(a, a + 3) - *min_element(a, a + 3)) % 2);
}

void feed (ll x) {
    printf("%lld\n", x);
    fflush(stdout);
    int place;
    scanf("%d", &place);
    if (place == 0) {
        exit(0);
    }

    -- place;
    a[place] += x;
}

void solve_arith_progression () {
    /**
    x   x + a x + 2a
    -> feed a
    x   x + a x + 3a
    feed 3a
    x   x + 3a  x + 4a <- used
    feed a
    used -> x + a   x + 3a  x + 4a
    feed a
    x + a   x + 3a  x + 5a <- used
    feed 2a
    can't avoid
    */
    assert(is_arith_progression());
    ll dif = *max_element(a, a + 3) - *min_element(a, a + 3);
    dif >>= 1;
    feed(dif);
    feed(3 * dif);
    feed(dif);
    feed(dif);
    feed(dif * 2);

    throw;
}

ll get_b () {
    ll * c = new ll[3];
    for (int i = 0 ; i < 3 ; ++ i)
        c[i] = a[i];
    sort(c, c + 3);
    return c[1] - c[0];
}

ll get_c () {
    ll * c = new ll[3];
    for (int i = 0 ; i < 3 ; ++ i)
        c[i] = a[i];
    sort(c, c + 3);
    return c[2] - c[1];

}


int main () {

    for (int i = 0 ; i < 3 ; ++ i)
        scanf("%lld", a + i);
    puts("First");
    fflush(stdout);

    while (!is_arith_progression()) {

        while (!valid_dif()) {
            ll b = get_b();
            ll c = get_c();
            feed(b + c);
            if (valid_dif()) break;
            feed(2 * b + 2 * c);
            assert(valid_dif());
            break;
        }

        if (is_arith_progression()) solve_arith_progression();
        ll b = get_b();
        ll c = get_c();
        feed(b - c);
        if (is_arith_progression()) solve_arith_progression();
        feed(3 * b - 3 * c);
        if (is_arith_progression()) solve_arith_progression();
        throw;
        /**
        0   b   b + c
        feed 2b - b - c = b - c
        only choice is
        0   b + c    2b - c
        then feed 4b - 2c - b - c = 3b - 3c
            b + c  2b - c  3b - 3
        */
    }

    solve_arith_progression();
}