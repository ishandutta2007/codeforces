#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, l, r;
    cin >> n;
    l = 1;
    r = n;
    while (l < r)
    {
        cout << l << " " << r << " ";
        ++l; --r;
    }
    if (l == r) cout << l;
    return 0;
}