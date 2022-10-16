#include <iostream>

using namespace std;

int64_t a[200001], por[200001], sor[200001];

int main()
{
    int64_t n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int64_t mult = 1;
    for (int i = 0; i < k; ++i)
        mult *= x;
    for (int i = 0; i < n; ++i)
        por[i + 1] = por[i] | a[i];
    for (int i = n - 1; i > 0; --i)
        sor[i - 1] = sor[i] | a[i];
    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, por[i] | sor[i] | (a[i] * mult));
    cout << ans;
    return 0;
}