#include <iostream>

using namespace std;

constexpr int N = 2e5;

int a[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, t, res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t, res += !!a[t]++;
    cout << res + 1 << '\n';
    return 0;
}