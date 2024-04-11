#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int a[Maxn];
int q;
ll cur;
map <ii, int> M;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cur += a[i];
    }
    scanf("%d", &q);
    while (q--) {
        int s, t, u; scanf("%d %d %d", &s, &t, &u);
        auto it = M.find(ii(s, t));
        if (it != M.end()) {
            cur -= max(a[it->second], 0);
            a[it->second]++;
            cur += max(a[it->second], 0);
            M.erase(it);
        }
        if (u) {
            M[ii(s, t)] = u;
            cur -= max(a[u], 0);
            a[u]--;
            cur += max(a[u], 0);
        }
        printf("%I64d\n", cur);
    }
    return 0;
}