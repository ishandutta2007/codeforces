#include <iostream>

using namespace std;

int i, n, a[200001], tmp, j;

main()
{
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n/2; i += 2) swap(a[i], a[n - i - 1]);
    for (i = 0; i < n; i++) cout << a[i] << " ";
}