#include <iostream>

using namespace std;

int main()
{
    int64_t s, x, a, b;
    cin >> s >> x;
//    int ans = 0;
//    for (int i = 1; i < s; ++i)
//    {
//
//    }
    a = (s - x);
    if (a < 0 || a % 2)
        return cout << 0, 0;
    a >>= 1;
    b = x + a;
    if (((s - b) ^ b) != x)
        return cout << 0, 0;
    cout << (1ll << __builtin_popcountll(x)) - 2 * (s == x);
    return 0;
}