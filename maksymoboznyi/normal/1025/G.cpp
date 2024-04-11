#include <iostream>

using namespace std;

const int M = 1e9 + 7;

const int N = 501;

int n, p[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != -1)
            p[x]++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x = 1;
        for (int j = 0; j < p[i]; j++)
            x *= 2, x %= M;
        sum += (x - 1);
        sum %= M;
    }
    int f = 1;
    for (int i = 1; i < n; i++)
        f *= 2, f %= M;
    f--;
    cout << (f - sum + M) % M;
    return 0;
}