#include <iostream>
using namespace std;

long long n, m, a;

int main()
{
    cin >> n >> m >> a;
    long long nn, mm;
    nn = n / a;
    if (nn * a < n) nn++;
    mm = m / a;
    if (mm * a < m) mm++;
    cout << nn * mm << endl;
    return 0;
}