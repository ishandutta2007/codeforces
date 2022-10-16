#include <iostream>

using namespace std;

int main()
{
    int n, a, res = -1e9;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a, res = max(res, a != int(__builtin_sqrtl(a)) *__builtin_sqrtl(a)? a: res);
    cout << res;
    return 0;
}