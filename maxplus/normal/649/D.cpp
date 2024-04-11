#include <iostream>

using namespace std;

const int N = 200001;
int a[N], b[N], uam, ans, n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) if (a[i])
        ans += a[uam++] != a[i];
    cout << ans << '\n';
    return 0;
}