#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

inline int my_gcd(int a, int b) {
    if (__builtin_expect(a % b == 0, 1))
        return b;
    return my_gcd(b, a % b);;
}

constexpr int N = 5e5, BL = __builtin_sqrt(N / 4);
//constexpr int N = 5e5, BL = 1;

int b[N], bam = 0, gcd[N];
vector<int> a;

void recalc(int i) {
    gcd[i] = a[b[i]];
    for (int j = b[i] + 1; j < b[i + 1]; ++j)
        gcd[i] = my_gcd(a[j], gcd[i]);
}

int cnt(int l, int r, int x) {
    int res = 0;
    for (int i = l; i < r; ++i)
        if (__builtin_expect(a[i] % x, 0))
            if (res++)
                break;
    return res;
}

int main()
{
    std::mt19937 gen(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());
    std::uniform_int_distribution<> dis(BL / 2 - 10, BL / 2 + 10);
    int n = N;
    unsigned q = 4e5;
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(a));
    while (b[bam++] < n)
        b[bam] = BL * bam + dis(gen);
    b[--bam] = n;
    for (int i = 0; i < bam; ++i)
        recalc(i);
    cin >> q;
//    unsigned force = 0;
    while (q--) {
        int t, l, r, x = 1;
//        int t = 1, l = q * q % n, r = q * q * 2 % n, x = q % bam + 1;
//        int t = 1, l = b[q % (bam - 2) + 1] + 1, r = b[(q + bam / 2) % (bam - 2) + 1] - 1, x = 1 << (q % 31);
//        if (l > r)
//            swap(l -= 2, r += 2);
//        int t = 2, l = b[q % (bam - 2) + 1] + 1, r = q % bam + 1, x;
        cin >> t >> l >> r, --l;
        if (t == 1) {
            cin >> x;
            int lb = lower_bound(b, b + bam, l) - b, rb = prev(upper_bound(b, b + bam, r)) - b;
            int bad, the_bad = -1;
            if (lb <= rb)
                bad = cnt(l, b[lb], x) + cnt(b[rb], r, x);
            else
                bad = cnt(l, r, x);
            for (int i = lb; i < rb; ++i)
                if (__builtin_expect(gcd[i] % x, 0))
                    if (the_bad = i, bad++)
                        break;
            if (bad == 1 && the_bad != -1)
                bad = cnt(b[the_bad], b[the_bad + 1], x);
//            force += bad <= 1;
            cout << (bad <= 1? "YES\n": "NO\n");

        } else {
            a[l] = r;
            recalc(prev(upper_bound(b, b + bam, l)) - b);
//            force += gcd[l];
        }
    }
//    volatile unsigned calc = force;
    return 0;
}