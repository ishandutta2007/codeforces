#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if ((i * i + j * j) % m == 0)
                if (n >= i && n >= j)
                    res += ll(1 + (n - i) / m) * (1 + (n - j) / m);
    cout << res << endl;
    return 0;
}