#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (d == 0) cout << "Hermione\n";
    else if (c == 0) cout << "Ron\n";
    else if (b == 0) cout << "Hermione\n";
    else if (a == 0) cout << "Ron\n";
    else if (b * d * f > a * c * e) cout << "Ron\n";
    else cout << "Hermione\n";
    return 0;
}