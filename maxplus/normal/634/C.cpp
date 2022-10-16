#include <iostream>

using namespace std;

const int N = 200002, BL = __builtin_sqrt(N) + 1, BAM = BL < N / BL + 1? N / BL + 1: BL;
int n, k, a, b, q, t, d, ad, am[BAM][BL];

struct prod{
    int f, s;
    prod():f(), s(){}
    prod(int am):f(min(am, b)), s(min(am, a)){}
    prod& operator +=(const prod &other)
    {
        f += other.f;
        s += other.s;
        return *this;
    }
    prod& operator -=(const prod &other)
    {
        f -= other.f;
        s -= other.s;
        return *this;
    }
} pr[BAM];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k >> a >> b >> q;
    while (q--)
    {
        cin >> t >> d;
        int bn = d / BL, en = d % BL;
        if (t == 1)
        {
            cin >> ad;
            pr[bn] -= prod(am[bn][en]);
            pr[bn] += prod(am[bn][en] += ad);
        }
        else
        {
            int d1 = d + k, bn1 = d1 / BL, en1 = d1 % BL, cb = 0, ce = 0;
            int ans = 0;
            while (cb < bn)
                ans += pr[cb++].f;
            while (ce < en)
                ans += prod(am[cb][ce++]).f;
            while (ce < BL && (bn != bn1 || ce < en1))
                ans += 0, ce++;
            if (ce == BL)
                ce = 0, cb++;
            while (cb < bn1)
                ans += 0, cb++;
            while (ce < en1)
                ans += 0, ce++;
            while (ce < BL)
                ans += prod(am[cb][ce++]).s;
            if (ce == BL)
                ce = 0, cb++;
            while (cb < BAM)
                ans += pr[cb++].s;
            cout << ans << '\n';
        }
    }
    return 0;
}