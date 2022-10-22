#include <iostream>

using namespace std;

int main()
{
    int n, k;
    bool b[1001] = {};
    cin >> n >> k;
    for (int i = 3; i <= n; i+=2)
        if (!b[i])
            for (int j = i+i; j <= n; j += i)
                b[j] = true;

    int a[1000] = {2}, an = 1;
    for (int i = 3; i <= n; i+=2)
        if (!b[i])
            a[an++] = i;
    an--;
    for (int i = 0; i < an && (a[i] + a[i+1] + 1) <= n; i++)
        if (!b[a[i] + a[i+1] + 1])
            k--;
    if (k <= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}