#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main()
{
    long long b, k;
    cin >> b >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    if (b % 2 == 0) {
        if (a[k - 1] % 2 == 0)
            cout << "even\n";
        else
            cout << "odd";
        return 0;
    }
    int x = 0;
    for (int i = 0; i < k; i++)
        x += a[i] % 2;
    x %= 2;
    cout << (x == 0 ? "even" : "odd");
    return 0;
}