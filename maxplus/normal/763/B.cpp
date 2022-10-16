#include <iostream>

using namespace std;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cout << "YES\n";
    int a, b;
    cin >> a;
    while (cin >> a >> b)
        cin >> a >> b, cout << (a & 1) * 2 + (b & 1) + 1 << '\n';
    return 0;
}