#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const ll Maxb = 60;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q;
int a[Maxn];
map <int, ll> M;
int BIT[Maxn][Maxb];

void Add(int x, ll val, int delt)
{
    for (int i = x; i <= n; i += i & -i)
        for (int j = 0; j < Maxb; j++)
            if (val & 1ll << ll(j))
                BIT[i][j] += delt;
}

vector <ll> Get(int x)
{
    vector <ll> res(Maxb, 0);
    for (int i = x; i > 0; i -= i & -i)
        for (int j = 0; j < Maxb; j++)
            res[j] += BIT[i][j];
    return res;
}

ll getHash(int val)
{
    auto it = M.find(val);
    if (it != M.end()) return it->second;
    ll res = uniform_int_distribution<ll>(0, (1ll << 60ll) - 1ll)(rng);
    M.insert(make_pair(val, res));
    return res;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        Add(i, getHash(a[i]), 1);
    }
    while (q--) {
        int typ, p1, p2, p3; scanf("%d %d %d", &typ, &p1, &p2);
        if (typ == 1) {
            Add(p1, getHash(a[p1]), -1);
            a[p1] = p2;
            Add(p1, getHash(a[p1]), 1);
        } else {
            scanf("%d", &p3);
            if ((p2 - p1 + 1) % p3) printf("NO\n");
            else {
                auto got1 = Get(p2);
                auto got2 = Get(p1 - 1);
                bool ok = true;
                for (int i = 0; i < Maxb; i++)
                    if (got1[i] % p3 != got2[i] % p3)
                        ok = false;
                printf("%s\n", ok? "YES": "NO");
            }
        }
    }
    return 0;
}