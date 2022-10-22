#include <iostream>
using namespace std;

int a, b, n;
char res;

int gcd(int x, int y)
{
    if (!x) return y;
    return gcd(y % x, x);
}

int main()
{
    cin >> a >> b >> n;
    while (true) {
          int needa = gcd(n, a);
          if (needa > n) {
                    res = '1';
                    break;
          }
          n -= needa;
          int needb = gcd(n, b);
          if (needb > n) {
                    res = '0';
                    break;
          }
          n -= needb;
    }
    cout << res << endl;
    return 0;
}