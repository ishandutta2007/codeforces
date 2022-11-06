#include <iostream>

using namespace std;
int n, a[101];
int ma = -1;
int main()
{
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma = max(a[i], ma);
    }
    for (int i = 0;i < n; i++)
    {
        ans += ma - a[i];
    }
    cout << ans;
    return 0;
}