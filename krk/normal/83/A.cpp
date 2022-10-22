#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, a[Maxn];
ll ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && a[i] == a[j]) j++;
        ll cnt = j - i;
        ans += cnt * (cnt + 1LL) / 2LL;
        i = j;
    }
    cout << ans << endl;
    return 0;
}