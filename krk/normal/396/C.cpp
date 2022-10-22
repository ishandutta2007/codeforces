#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 300005;

int n;
vector <int> neigh[Maxn];
int cur = 1, L[Maxn], R[Maxn];
int lvl[Maxn];
int q;
int BIT1[Maxn], BIT2[Maxn];

void Traverse(int v)
{
    L[v] = cur++;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        lvl[u] = lvl[v] + 1; Traverse(u);
    }
    R[v] = cur;
}

void Insert(int BIT[], int x, int val)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] = (BIT[i] + val) % mod;
}

int Get(int BIT[], int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res = (res + BIT[i]) % mod;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(1);
    scanf("%d", &q);
    while (q--) {
        int typ, v, x, k;
        scanf("%d %d", &typ, &v);
        if (typ == 1) {
            scanf("%d %d", &x, &k);
            Insert(BIT1, L[v], k); Insert(BIT1, R[v], (-k + mod) % mod);
            int toadd = (ll(lvl[v]) * k + x) % mod;
            Insert(BIT2, L[v], toadd); Insert(BIT2, R[v], (-toadd + mod) % mod);
        } else printf("%d\n", (Get(BIT2, L[v]) - ll(Get(BIT1, L[v])) * lvl[v] % mod + mod) % mod);
    }
    return 0;
}