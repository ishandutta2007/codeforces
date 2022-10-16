#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 1000;

int n, m, c, p, l, r, a[N];

void Set(int pos) {
    cout << pos + 1 << '\n';
    a[pos] = p;
    if (pos == l)
        ++l;
    if (pos == r)
        --r;
}

int main()
{
    cin >> n >> m >> c;
    r = n - 1;
    while (l <= r) {
        cin >> p;
        if (p <= c / 2)
            Set(upper_bound(a, a + l, p) - a);
        else
            Set(lower_bound(a + r, a + n, p) - a - 1);
    }
    return 0;
}