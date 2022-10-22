#include <iostream>
using namespace std;

long long a, b;
long long nexta, nextb;
long long d, m;

int main()
{
    cin >> a >> b;
    nexta = a; nextb = b;
    long long cur = 0;
    while (nexta != nextb)
       if (nexta < nextb) {
                 d += nexta - cur;
                 cur = nexta;
                 nexta += a;
       } else {
              m += nextb - cur;
              cur = nextb;
              nextb += b;
       }
    if (a > b) d += nexta - cur;
    else m += nextb - cur;
    if (d > m) cout << "Dasha\n";
    else if (d < m) cout << "Masha\n";
    else cout << "Equal\n";
    return 0;
}