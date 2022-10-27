#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ull = long long ;

ull get_sum (ull x) {
    return (x) * (x + 1) / 2;
}

ull odd_sum (ull x) {
    assert(x % 2);
    return ((x + 1) / 2) * ((x + 1) / 2);
}

ull even_sum (ull x) {
    assert((x + 1) % 2);
    return get_sum(x) - odd_sum(x - 1);
}

int main () {

    int T;

    for (scanf("%d", &T) ; T -- ;) {

        int sx, sy, ex, ey;

        scanf("%d %d %d %d", &sx, &sy, &ex,  &ey);

        ull d = ex - sx;
        ull r = ey - sy;

        ull f = get_sum(r) + (r % 2 ? odd_sum(r + 2 * d) : even_sum(r + 2 * d)) - (r % 2 ? odd_sum(r) : even_sum(r));
        ull s = even_sum(d * 2);
        s += get_sum(r + 2 * d) - get_sum(d * 2);

     ///   cerr << f << ' ' << s << endl;

        printf("%llu\n", s - f + 1);
    }
}
/*
    Long time no see...
        CF round
*/