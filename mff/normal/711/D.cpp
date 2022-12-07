#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;
const int64 mod = 1000000007;

int to[maxn];
int mk[maxn];
int ds[maxn];

int64 fexp(int64 a, int64 n){
    if (n == 0) return 1;
    if (n & 1) return a * fexp(a, n - 1) % mod;
    return fexp(a * a % mod, n / 2);
}

int get_size(int u, int i){
    mk[u] = i;
    int v = to[u];

    if (mk[v] != 0 && mk[v] != i)
        return -1;

    if (mk[v] == i){
        return ds[u] + 1 - ds[v];
    }

    ds[v] = ds[u] + 1;
    return get_size(v, i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n; cin >> n;

    for (int i = 1; i <= n; ++i){
        cin >> to[i];
    }

    int64 ans = 1;
    int tot = 0;

    for (int i = 1; i <= n; ++i){
        if (mk[i]) continue;

        int sz = get_size(i, i);
        if (sz == -1) continue;

        tot += sz;
        ans = ans * ((fexp(2, sz) - 2 + mod) % mod) % mod;
    }

    ans = ans * fexp(2, n - tot) % mod;

    cout << ans << endl;

    return 0;
}