#include <iostream>
#include <algorithm>
using namespace std;

int base, ans;

int maxDig(int x)
{
    int big = 0;
    while (x) {
          big = max(big, x % 10);
          x /= 10;
    }
    return big;
}

int Change(int x, int p)
{
    int row = 1, num = 0;
    while (row <= x) row *= 10;
    row /= 10;
    while (row) {
          num = p * num + x % (10 * row) / row;
          row /= 10;
    }
    return num;
}

int main()
{
    int n, a, b, car = 0;
    cin >> a >> b;
    base = max(maxDig(a), maxDig(b)) + 1;
    n = Change(a, base) + Change(b, base);
    while (n) {
          ans++;
          n /= base;
    }
    cout << ans << endl;
    return 0;
}