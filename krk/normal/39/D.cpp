#include <iostream>
using namespace std;

int main()
{
    int a1, b1, c1;
    int a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (a1 == a2 || b1 == b2 || c1 == c2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}