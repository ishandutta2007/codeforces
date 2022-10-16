#include <iostream>

using namespace std;

int main()
{
    int64_t n, ans;
    cin >> n;
    ans = n * 9 - 3;
    while (--n > 2)
        ans *= 4;
    cout << ans;
    return 0;
}