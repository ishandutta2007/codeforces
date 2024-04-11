#include <iostream>
using namespace std;

typedef long long ull;

ull n, k, p;

char getChar(ull x, ull n, ull k)
{
     if (k == 0LL) return '.';
     if (n % 2LL)
        if (x == n) return 'X';
        else return getChar(x, n - 1LL, k - 1LL);
     if (x % 2LL == 0)
        if (n / 2LL - x / 2LL + 1LL <= k) return 'X';
        else return '.';
     k -= n / 2LL;
     if (n / 2LL - (x + 1LL) / 2LL + 1LL <= k) return 'X';
     else return '.';
}

int main()
{
    cin >> n >> k >> p;
    for (int i = 0; i < p; i++) {
        ull x; cin >> x;
        cout << getChar(x, n, k);
    }
    cout << endl;
    return 0;
}