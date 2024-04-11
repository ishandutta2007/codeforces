#include <iostream>

using namespace std;

int ans(int* a)
{
    return (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - (a[0] * a[0] + a[2] * a[2] + a[4] * a[4]);
}

int main()
{
    int a[13];
    for (int i = 0; i < 6; ++i)
        (cin >> a[i]), a[i + 6] = a[i];
    for (int i = 0; i < 5; ++i)
        if (ans(a + i) != ans(a + i + 1))
            return -1;
    cout << ans(a);
    return 0;
}