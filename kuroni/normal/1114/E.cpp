#include <iostream>
#include <cstdio>
#include <random>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 65;

mt19937 mt(N * N * N);
int n, d = 0, a[N];

int main()
{
    // random_device seems to be deterministic?
    cin >> n;
    uniform_int_distribution<int> dis(1, n);
    for (int r, i = 29; i >= 0; i--)
        if (a[0] + (1 << i) <= 1E9)
        {
            cout << "> " << a[0] + (1 << i) << endl;
            cin >> r;
            if (r == 1)
                a[0] += (1 << i);
        }
    a[0]++;
    for (int i = 1; i <= 30; i++)
    {
        int pos = dis(mt);
        cout << "? " << pos << endl;
        cin >> a[i];
    }
    for (int i = 0; i <= 30; i++)
        for (int j = i + 1; j <= 30; j++)
            d = __gcd(d, abs(a[i] - a[j]));
    cout << "! " << a[0] - (n - 1) * d << " " << d << endl;
}