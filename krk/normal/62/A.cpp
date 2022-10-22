#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a-d <= 1 && 2*a+2 >= d || b-c <= 1 && 2*b+2 >= c) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}