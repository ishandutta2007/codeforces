#include <iostream>
using namespace std;

const int Maxn = 100;

int n, k, a[Maxn], ans;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
       cin >> a[i];
    while (a[0] < k) {
          ans++;
          int was = k;
          for (int i = n - 1; i >= 0; i--)
             if (a[i] != was) was = a[i]++;
    }
    cout << ans << endl;
    return 0;
}