#include <iostream>

using namespace std;
int a[100000], b[100000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; i--)
        b[i] = a[i] + a[i + 1];
    for (int i = 0; i < n; i++)
        cout << b[i] <<' ';
    return 0;
}