#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n, k;
ll a[Maxn];
map <ll, int> M;
ll res;

ll Add(ll a, ll b)
{
    if (a == 0 && b == 0) return 0;
    return 3ll * Add(a / 3, b / 3) + (a + b) % 3;
}

ll Sub(ll a, ll b)
{
    if (a == 0 && b == 0) return 0;
    return 3ll * Sub(a / 3, b / 3) + ((a - b) % 3 + 3) % 3;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int val; scanf("%d", &val);
            a[i] = a[i] * 3ll + ll(val);
        }
        for (int j = 0; j < i; j++)
            M[Add(a[i], a[j])]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j)
            M[Add(a[i], a[j])]--;
        ll nd = Sub(0, a[i]);
        auto it = M.find(nd);
        if (it != M.end()) res += ll(it->second) * (it->second - 1) / 2ll;
        for (int j = 0; j < n; j++) if (i != j)
            M[Add(a[i], a[j])]++; 
    }
    cout << res << endl;
    return 0;
}