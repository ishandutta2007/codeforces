#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n, k, phi[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                (phi[j] /= i) *= (i - 1);
    sort(phi + 3, phi + n + 1);
    cout << (k == 1 ? 3 : accumulate(phi + 3, phi + k + 3, 2LL));
}