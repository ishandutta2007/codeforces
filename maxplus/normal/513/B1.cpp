#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

int8_t a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int8_t s, mi, ms;
int16_t n, m, num;

inline int8_t f()
{
    s = mi = a[0];
    for (int8_t i = 0; i < n - 1; ++i, s += (mi = a[i]))
        for (int8_t j = i; j < n - 1; ++j, s += (mi = min(mi, a[j])))
            ;
    return s;
}

inline void print()
{
    for (int i = 0; i < n; ++i)
        cout << (int16_t)a[i] << ' ';
    exit(0);
}

int main()
{
    cin >> n >> m;
    do
        ms = max(ms, f());
    while (next_permutation(a, a + n));
    do
        if (f() == ms)
            if (num == m - 1)
                print();
            else
                num++;
    while (next_permutation(a, a + n));
    return 0;
}