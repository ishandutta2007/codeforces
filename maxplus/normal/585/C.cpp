#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

stack<int64_t> ans;

int main()
{
    int64_t a, b;
    char let;
    cin >> a >> b;
    if (__gcd(a, b) != 1)
        (cout << "Impossible"), exit(0);
    if (a < b)
        let = 'B';
    else
        let = 'A';
    while (a > 1 && b > 1)
        if (a < b)
            (cout << b / a << let), b %= a, let = char('A' ^ 'B' ^ let);
        else
            (cout << a / b << let), a %= b, let = char('A' ^ 'B' ^ let);
    if (a < b && b / a > 1)
        cout << b / a - 1 << let;
    else if (a > b && a / b > 1)
        cout << a / b - 1 << let;
    return 0;
}