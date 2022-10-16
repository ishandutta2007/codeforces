#include <iostream>
#include <cmath>

using namespace std;

int64_t fdst(int64_t f1, int64_t f2)
{
    return min(abs(f1 - f2) * 5, 10 + abs(f1 - f2));
}

int64_t n, m, k, a, b, s1, s2, f1, f2;

int main()
{
    cin >> n >> m >> k >> a >> b;--a, --b;
    if (b < a)
        swap(a, b);
    s1 = a / m / k, s2 = b / m / k;
    f1 = a % (m * k) / k, f2 = b % (m * k) / k;
    if (s1 == s2)
        cout << fdst(f1, f2);
    else
        cout << fdst(f1, 0) + min(s2 - s1, s1 - s2 + n) * 15 + fdst(0, f2);
    return 0;
}