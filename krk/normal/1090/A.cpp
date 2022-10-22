#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
vector <int> V[Maxn];
int mx[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    int gmx = 0;
    for (int i = 0; i < n; i++) {
        int k; scanf("%d", &k);
        V[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &V[i][j]);
            mx[i] = max(mx[i], V[i][j]);
        }
        gmx = max(gmx, mx[i]);
    }
    for (int i = 0; i < n; i++)
        res += ll(gmx - mx[i]) * ll(V[i].size());
    cout << res << endl;
    return 0;
}