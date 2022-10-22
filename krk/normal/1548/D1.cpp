#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 6006;
const int Maxd = 4;

int n;
int X[Maxn], Y[Maxn];
int my[Maxd];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        int cur = 0;
        if (X[i] % 4 == 2) cur += 2;
        if (Y[i] % 4 == 2) cur++;
        my[cur]++;
    }
    for (int i = 0; i < Maxd; i++) {
        res += ll(my[i]) * (my[i] - 1ll) * (my[i] - 2ll) / 6ll;
        res += ll(my[i]) * (my[i] - 1ll) / 2ll * ll(n - my[i]);
    }
    cout << res << endl;
    return 0;
}