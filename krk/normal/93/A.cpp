#include <iostream>
using namespace std;

int n, m, a, b;

int main()
{
    cin >> n >> m >> a >> b;
    int divA = (a - 1) / m, modA = (a - 1) % m + 1;
    int divB = (b - 1) / m, modB = (b - 1) % m + 1;
    if (divA == divB) cout << "1\n";
    else if (modA == 1 && modB == m) cout << "1\n";
    else if (modA == 1 && b == n) cout << "1\n";
    else if (modB + 1 == modA) cout << "2\n";
    else if (modA == 1) cout << "2\n";
    else if (modB == m || b == n) cout << "2\n";
    else if (divA + 1 == divB) cout << "2\n";
    else cout << "3\n";
    return 0;
}