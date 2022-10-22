#include <iostream>
using namespace std;

int n, a, b, c;
long long ans;

int main()
{
    cin >> n >> a >> b >> c;
    for (int i = 0; i <= c && 2 * i <= n; i++)
       for (int j = 0; j <= b && 2 * i + j <= n; j++)
          if ((n - 2 * i - j) * 2 <= a) ans++;
    cout << ans << endl;
    return 0;
}