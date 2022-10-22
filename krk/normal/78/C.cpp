#include <iostream>
using namespace std;

int n, m, k;

int main()
{
    cin >> n >> m >> k;
    bool havecut = k == 1 && m > 1;
    for (int i = 2; i <= m / i && !havecut; i++)
       havecut = m % i == 0 && (i >= k || m / i >= k);
    if (!havecut) cout << "Marsel\n";
    else if (n % 2 == 0) cout << "Marsel\n";
    else cout << "Timur\n";
    return 0;
}