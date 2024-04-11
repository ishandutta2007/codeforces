#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int a, b, mod;

void Print(int x)
{
     int d = 100000000;
     while (d && x / d == 0) {
           cout << '0';
           d /= 10;
     }
     cout << x << endl;
}

int main()
{
    cin >> a >> b >> mod;
    int i;
    for (i = 0; i <= a && i <= mod; i++) {
        int md = ll(i) * 1000000000LL % ll(mod);
        int need = (mod - md) % mod;
        if (need > b) break;
    }
    if (i <= min(a, mod)) {
          cout << "1 ";
          Print(i);
    } else cout << "2\n";
    return 0;
}