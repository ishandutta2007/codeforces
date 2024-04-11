#include <iostream>

using namespace std;

int main()
{
    int64_t x, ans = 0;
    cin >> x;
    ((x %= 360) += 360) %= 360;
    while (x > 45 && x < 315)
        x = (x + 270) % 360, ans++;
    cout << ans;
    return 0;
}