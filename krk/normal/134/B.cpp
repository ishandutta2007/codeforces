#include <iostream>
#include <algorithm>
using namespace std;

int getMin(int a, int b)
{
    if (b == 0) return 10000000;
    if (b == 1) return a - 1;
    return a / b + getMin(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    int res = n;
    for (int i = 1; i <= n; i++)
       res = min(res, getMin(n, i));
    cout << res << endl;
    return 0;
}