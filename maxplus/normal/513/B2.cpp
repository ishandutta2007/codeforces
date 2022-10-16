#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int64_t a[50], b = -1;
int64_t s, mi, ms;
int64_t n = 10, m, num;

inline int64_t f()
{
    s = mi = a[0];
    for (int64_t i = 0; i < n - 1; ++i, s += (mi = a[i]))
        for (int64_t j = i; j < n - 1; ++j, s += (mi = min(mi, a[j])))
            ;
    return s;
}

bool met[50];

inline void gen(int64_t pr, int64_t m)
{
    if (a[pr - 1] == n - 1)
        return;
    if (pr && a[pr - 1] == n - 2)
    {
        met[a[pr] = n - 1] = 1;
        return;
    }
    a[pr] = pr? a[pr - 1] + 1:0;
    int64_t d = (int64_t)1 << (n - a[pr] - 2);
//    if (m == 2 * d)
//    {
//        met[a[pr] = n - 1] = 1;
//        return;
//    }
    while (m > d)
        a[pr]++, m -= d, d = (d + 1) / 2;
    met[a[pr]] = 1;
    return gen(pr + 1, m);
}

inline void print()
{
    for (int64_t i = 0; i < n; ++i)
        cout << a[i] + 1 << ' ';
    cout << '\n';
//    exit(0);
}

int main()
{
    cin >> n >> m;
//    for (m = 1; m < (1 << n - 1); ++m)
//    {
//        int64_t M = m;
//        int64_t m = M;
//        memset(a, 0, sizeof(a));
//        memset(met, 0, sizeof(met));
//    if (m == 1)
//    {
//        for (int64_t i = 0; i < n; ++i)
//            cout << i + 1 << ' ';
//        return 0;
//    }
    gen(0, m);
    int64_t cp = 0;
    while (a[cp] != n - 1)   cp++;
    cp++;
    int64_t cm = n - 1;
    while (cm >= 0)
        if (!met[cm])
            a[cp++] = cm--;
        else
            cm--;
    print();
//    }
    return 0;
}