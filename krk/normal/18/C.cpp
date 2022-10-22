#include <iostream>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; sum += a[i];
    }
    int cursum = 0, ans = 0;
    for (int i = 0; i < n-1; i++) {
        cursum += a[i];
        if (cursum == sum - cursum) ans++;
    }
    cout << ans << endl;
    return 0;
}