#include <iostream>
#define MAXW 1000100

using namespace std;

int a[MAXW], n, w, ans;

int main()
{
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> w), a[w]++;
    for (int i = 0; i < MAXW; ++i)
        a[i + 1] += (a[i] >> 1), a[i] &= 1;
    for (int i = 0; i < MAXW; ++i)
        ans += a[i];
    cout << ans;
    return 0;
}