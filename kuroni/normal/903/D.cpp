#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

map<int, int> cnt;
int n, a[200005];
long long sum = 0;
long double ans = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        sum += a[i];
        ans += sum - 1LL * a[i] * (n - i + 1);
        cnt[a[i]]++;
        ans += cnt[a[i] - 1];
        ans -= cnt[a[i] + 1];
    }
    cout << fixed << setprecision(0) << ans;
}