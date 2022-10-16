#include <iostream>
#include <cassert>

using namespace std;

int64_t A[151], B[151], *a = A, *b = B;

int main()
{
    int n;
    cin >> n;
    a[0] = 1;
    for (int i = 0; i < n; ++i) {
        int dir = 0;
        for (int j = 0; j <= i; ++j) {
            if (b[j + 1] * a[j] == 1) {
                dir |= 2;
            } else if (b[j + 1] * a[j] == -1) {
                dir |= 1;
            }
        }
        dir |= dir == 0;
        for (int j = 0; j <= i; ++j) {
            b[j + 1] += a[j] * (3 - 2 * dir);
        }
        swap(a, b);
    }
    cout << n << '\n';
    for (int i = 0; i <= n; ++i) {
        cout << a[i] * a[n] << ' ';
    }
    cout << '\n' << n - 1 << '\n';
    for (int i = 0; i < n; ++i) {
        cout << b[i] * b[n - 1] << ' ';
    }
    cout << '\n';
    return 0;
}