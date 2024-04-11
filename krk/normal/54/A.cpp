#include <iostream>
using namespace std;

int n, k, c, nw = 0, ans = 0;

int main()
{
    int tmp;
    cin >> n >> k >> c;
    while (c--) {
          cin >> tmp;
          while (nw + k < tmp) { ans++; nw += k; }
          ans++; nw = tmp;
    }
    if (nw < n) while (nw + k <= n) { ans++; nw += k; }
    cout << ans << endl;
    return 0;
}