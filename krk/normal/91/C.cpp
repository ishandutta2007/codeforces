#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 1000000009;
const int Maxn = 100005;

int n, m;
int p[Maxn], siz[Maxn];
int res = 1;

int getPar(int v)
{
    if (p[v] == v) return v;
    return p[v] = getPar(p[v]);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i; siz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int para = getPar(a), parb = getPar(b);
        if (para == parb) res = 2 * res % mod;
        else if (siz[para] < siz[parb]) {
                p[para] = parb;
                siz[parb] += siz[para];
             } else {
                    p[parb] = para;
                    siz[para] += siz[parb];
             }
        cout << (res + mod - 1) % mod << endl;
    }
    return 0;
}